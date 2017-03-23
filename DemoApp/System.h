#pragma once
#include <unordered_map>
#include <typeindex>
#include <algorithm>
#include <memory>
#include "defines.h"
#include "Window.h"
#include "keyboardHandler.h"
#include "Controller.h"
#include "Object.h"

class System
{
public:
	System(Platform );
	virtual ~System();
	/*
	* Template function to get any EventHandler
	*
	*/
	template < typename T >
	std::shared_ptr< T > getEventHandler(void)
	{
		auto it = m_handler_map.find(typeid(T));

		if (it != m_handler_map.end())
			return std::dynamic_pointer_cast< T >(it->second);

		return nullptr;
	}

	/*
	* Template function which adds required EventHandler to a vector
	*/
	template< typename T >
	std::shared_ptr< T > addEventHandler(Platform ptfrm)
	{
		static_assert(std::is_base_of< EventHandler, T >::value, "Non-EventHandler class cannot be added!");
		auto& org = std::make_shared< T >();
		const auto& temp = std::static_pointer_cast< EventHandler >(org);
		temp->platform(ptfrm);
		m_handler_map[typeid(T)] = temp;
		m_handlers.push_back(temp);
		if (m_window->platform() == ptfrm)
		{
			m_window->addEventHandler(temp);
		}
		return org;
	}
	/*
	* Template function to get any EventHandler
	*
	*/
	template < typename T >
	std::shared_ptr< T > getController(void)
	{
		auto it = m_controller_map.find(typeid(T));

		if (it != m_controller_map.end())
			return std::dynamic_pointer_cast< T >(it->second);

		return nullptr;
	}

	/*
	* Template function which adds required EventHandler to a vector
	*/
	template< typename T >
	std::shared_ptr< T > addController(std::shared_ptr<EventHandler> hldr)
	{
		static_assert(std::is_base_of< Controller, T >::value, "Non-Controller class cannot be added!");
		auto& org = std::make_shared< T >(hldr);
		const auto& temp = std::static_pointer_cast< Controller >(org);
		m_controller_map[typeid(T)] = temp;
		return org;
	}

	/*
	* Template function which adds required Object to a vector
	*/
	template< typename T >
	std::shared_ptr<T> addObject(unsigned int id)
	{
		static_assert(std::is_base_of< Object, T >::value, "Non-Object class cannot be added!");
		auto& org = std::make_shared< T >();
		const auto& temp = std::static_pointer_cast< Object>(org);
		m_object_map[id] = temp;
		m_objects.push_back(temp);
		temp->id(id);
		return org;
	}
	template< typename T >
	std::shared_ptr<T> getObject(unsigned int id)
	{
		auto it = m_object_map.find(id);

		if (it != m_object_map.end())
			return std::dynamic_pointer_cast< T >(it->second);

		return nullptr;
	}
public:
	bool run();
private:
	std::unordered_map< std::type_index, std::shared_ptr< EventHandler >>	m_handler_map;
	std::vector<std::shared_ptr< EventHandler> >							m_handlers;
	std::unordered_map< std::type_index, std::shared_ptr< Controller >>		m_controller_map;
	std::unordered_map< unsigned int, std::shared_ptr< Object >>			m_object_map;
	std::vector<std::shared_ptr<Object>>									m_objects;
	BaseWindow*																m_window;
};

