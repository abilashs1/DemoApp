#include "EventHandler.h"


EventHandler::EventHandler()
{
}


EventHandler::~EventHandler()
{
}
void EventHandler::registerEvent(EventCode ev)
{
	m_codes.push_back(ev);
}
void EventHandler::unregisterEvent(EventCode ev)
{
	auto it = std::find(m_codes.begin(), m_codes.end(), ev);
	if (it != m_codes.end())
	{
		m_codes.erase(it);
	}
}
void EventHandler::validateOnEvent(Event* ev)
{
	EventCode ec = ev->eventCode();
	if (std::find(m_codes.begin(), m_codes.end(), ec) != m_codes.end())
		onEvent(ev);
}