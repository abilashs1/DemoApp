#pragma once
#include <memory>
class EventHandler;

class Controller
{
public:
	Controller(std::shared_ptr<EventHandler>);
	virtual ~Controller();
public:
	virtual bool forward() = 0;
	virtual bool reverse() = 0;
	virtual bool left() = 0;
	virtual bool right() = 0;
public:
	std::shared_ptr<EventHandler> getEventHandler();
protected:
	std::shared_ptr<EventHandler>	m_handler;
};

