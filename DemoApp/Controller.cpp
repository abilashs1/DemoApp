#include "Controller.h"



Controller::Controller(std::shared_ptr<EventHandler> hdlr):m_handler(hdlr)
{

}


Controller::~Controller()
{
}

std::shared_ptr<EventHandler> Controller::getEventHandler()
{
	return m_handler;
}
