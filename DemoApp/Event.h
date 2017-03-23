#pragma once
enum class EventCode :unsigned
{
	KEYDOWN = 0,
	KEYUP,
	MOUSEMOVE,
};

class Event
{
public:
	Event();
	Event(const Event&) = delete;
	Event& operator=(const Event& toCopy) = delete;
	~Event();
	EventCode eventCode(EventCode e);
	EventCode eventCode();
	
public:
	EventCode evt;
};