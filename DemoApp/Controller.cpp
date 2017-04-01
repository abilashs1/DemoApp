#include "Controller.h"

#include "KeyboardHandler.h"
#include "MouseHandler.h"
#include <iostream>
#define DEBUG 1

Controller::Controller(std::shared_ptr<EventHandler> hdlr):m_handler(hdlr)
{

}

Controller::~Controller()
{
}

bool Controller::forward()
{
	/*Keyboard*/
	{
		auto& hldr = std::dynamic_pointer_cast<KeyboardHandler>(m_handler);
		if (hldr != nullptr)
		{
			if (hldr->getKeyDown(KeyCode::W))
			{
#ifdef DEBUG
				std::cout << "Controller " << " "<< __func__ << std::endl;
#endif // DEBUG

				return true;
			}
		}
	}
	/*Mouse*/
	{
		auto& hldr = std::dynamic_pointer_cast<MouseHandler>(m_handler);
		if (hldr != nullptr)
		{
			if (hldr->direction(MouseCode::North))
			{
#ifdef DEBUG
				std::cout << __func__ << " Mouse "<<std::endl;
#endif // DEBUG
				return true;
			}
		}
	}
	return false;
}

bool Controller::reverse()
{
	auto& hldr = std::dynamic_pointer_cast< KeyboardHandler >(m_handler);
	if (hldr != nullptr)
	{
		if (hldr->getKeyDown(KeyCode::S))
		{
#ifdef DEBUG
			std::cout << __func__ << std::endl;
#endif // DEBUG
			return true;
		}
	}
	return false;
}

bool Controller::left()
{
	auto& hldr = std::dynamic_pointer_cast< KeyboardHandler >(m_handler);
	if (hldr != nullptr)
	{
		if (hldr->getKeyDown(KeyCode::A))
		{
#ifdef DEBUG
			std::cout << __func__ << std::endl;
#endif // DEBUG
			return true;
		}
	}
	return false;
}

bool Controller::right()
{
	auto& hldr = std::dynamic_pointer_cast< KeyboardHandler >(m_handler);
	if (hldr != nullptr)
	{
		if (hldr->getKeyDown(KeyCode::D))
		{
#ifdef DEBUG
			std::cout << __func__ << std::endl;
#endif // DEBUG
			return true;
		}
	}
	return false;
}


std::shared_ptr<EventHandler> Controller::getEventHandler()
{
	return m_handler;
}
