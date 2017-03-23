#include "KeyboardController.h"
#include "KeyboardHandler.h"
#include <iostream>
#define DEBUG 1
KeyboardController::KeyboardController(std::shared_ptr<EventHandler> hdlr):Controller(hdlr)
{
	
}

KeyboardController::~KeyboardController()
{
}

bool KeyboardController::forward()
{
	 auto& hldr = std::static_pointer_cast< KeyboardHandler >(m_handler);
	if (hldr->getKeyDown(KeyCode::W))
	{
#ifdef DEBUG
		std::cout << __func__ << std::endl;
#endif // DEBUG

		return true;
	}
	return false;
}
bool KeyboardController::reverse()
{
	auto& hldr = std::static_pointer_cast< KeyboardHandler >(m_handler);
	if (hldr->getKeyDown(KeyCode::S))
	{
#ifdef DEBUG
		std::cout << __func__ << std::endl;
#endif // DEBUG
		return true;
	}
	return false;
}
bool KeyboardController::left()
{
	auto& hldr = std::static_pointer_cast< KeyboardHandler >(m_handler);
	if (hldr->getKeyDown(KeyCode::A))
	{
#ifdef DEBUG
		std::cout << __func__ << std::endl;
#endif // DEBUG
		return true;
	}
	return false;
}
bool KeyboardController::right()
{
	auto& hldr = std::static_pointer_cast< KeyboardHandler >(m_handler);
	if (hldr->getKeyDown(KeyCode::D))
	{
#ifdef DEBUG
		std::cout << __func__ << std::endl;
#endif // DEBUG
		return true;
	}
	return false;
}
