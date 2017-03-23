#include "Event.h"

Event::Event()
{
}


Event::~Event()
{
}

EventCode Event::eventCode(EventCode e)
{
	evt = e;
	return e;
}

EventCode Event::eventCode()
{
	return evt;
}