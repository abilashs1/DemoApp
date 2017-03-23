#include "BaseWindow.h"
#include "EventHandler.h"


BaseWindow* BaseWindow::m_window = nullptr;

BaseWindow::BaseWindow(Platform type)
{
	m_platform = type;
	m_window = this;
}


BaseWindow::~BaseWindow()
{
}

void BaseWindow::handleEvent(Event * evt)
{
	for (auto handler : m_handlers)
		handler->validateOnEvent(evt);
}

void BaseWindow::addEventHandler(std::shared_ptr<EventHandler>  hdlr)
{
	m_handlers.push_back(hdlr);	
}

bool BaseWindow::run()
{
	for (auto handler : m_handlers)
		handler->run();
	return true;
}
