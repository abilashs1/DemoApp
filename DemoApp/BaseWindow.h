#pragma once
#include <vector>
#include <memory>
#include "defines.h"

class EventHandler;
class Event;

class BaseWindow
{
public:
	BaseWindow(Platform);
	virtual ~BaseWindow();
public:

	void addEventHandler(std::shared_ptr<EventHandler>);
	void handleEvent(Event*);
public:
	static BaseWindow* getInstance()
	{
		return m_window;
	}
	static BaseWindow* m_window;
	Platform platform()
	{
		return m_platform;
	}
public:
	virtual bool initialise(int, int) = 0;
	virtual bool run();
	
protected:

	std::vector<std::shared_ptr< EventHandler> >	m_handlers;
	Platform										m_platform;
};

