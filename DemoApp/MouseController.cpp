#include "MouseController.h"
#include "MouseHandler.h"


MouseController::MouseController(std::shared_ptr<EventHandler> hdlr):Controller(hdlr), m_delta(30)
{
}


MouseController::~MouseController()
{
}
#include <iostream>
bool MouseController::forward()
{
	auto& hldr = std::static_pointer_cast< MouseHandler >(m_handler);
	//hldr->run();
	if (hldr->prvY - hldr->curY > m_delta)
		return true;
	return false;
}
bool MouseController::reverse()
{
	auto& hldr = std::static_pointer_cast< MouseHandler >(m_handler);
	//hldr->run();
	if ( hldr->curY - hldr->prvY > m_delta)
		return true;
	return false;
}
bool MouseController::left()
{
	auto& hldr = std::static_pointer_cast< MouseHandler >(m_handler);
	//hldr->run();
	if ( hldr->prvX - hldr->curX > m_delta)
		return true;
	return false;
}

bool MouseController::right()
{
	auto& hldr = std::static_pointer_cast< MouseHandler >(m_handler);
	//hldr->run();
	if (hldr->curX - hldr->prvX > m_delta)
		return true;
	return false;
}