#pragma once
#include <memory>
class EventHandler;

class Controller
{
public:
	Controller(std::shared_ptr<EventHandler>);
	virtual ~Controller();
public:
	virtual bool forward();
	virtual bool reverse();
	virtual bool left();
	virtual bool right();
public:
	std::shared_ptr<EventHandler> getEventHandler();
protected:
	std::shared_ptr<EventHandler>	m_handler;
};

