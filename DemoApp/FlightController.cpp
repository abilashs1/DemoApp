#include "FlightController.h"
#include "KeyBoardHandler.h"
#include "MouseHandler.h"
#include <iostream>

#define DEBUG 1
FlightController::FlightController(std::shared_ptr<EventHandler> hdlr) :Controller(hdlr)
{

}

FlightController::~FlightController()
{
}


bool FlightController::forward()
{
	/*Keyboard*/
	{
		auto& hldr = std::dynamic_pointer_cast<KeyboardHandler>(m_handler);
		if (hldr != nullptr)
		{
			if (hldr->getKeyDown(KeyCode::W))
			{
#ifdef DEBUG
				std::cout << "FlightController"  << " " << __func__ << std::endl;
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
				std::cout << __func__ << "Mouse " << std::endl;
#endif // DEBUG

				return true;
			}
		}
	}
	return false;
}

bool FlightController::strafe_up()
{
	return false;
}

bool FlightController::strafe_down()
{
	return false;
}

