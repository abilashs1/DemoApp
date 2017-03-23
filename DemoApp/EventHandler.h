#pragma once
#include <algorithm>
#include <vector>
#include "Event.h"
#include "defines.h"
class EventHandler
{
public:
	EventHandler();
	virtual ~EventHandler();
public:

	virtual void onEvent(Event*)
	{

	}
	virtual void run()
	{

	}
public:
	void platform(Platform type)
	{
		m_type = type;
	}
	void registerEvent(EventCode ev);
	void unregisterEvent(EventCode ev);
	void validateOnEvent(Event* ev);
	
private:
	std::vector<EventCode> m_codes;
	Platform				m_type;
};

