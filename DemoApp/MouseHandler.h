#pragma once
#include "EventHandler.h"
enum class MouseCode :unsigned
{
	North,
	NorthWest,
	NorthEast,
	South,
	East,
	West,
};
class MouseHandler :
	public EventHandler
{
public:
	MouseHandler();
	virtual ~MouseHandler();

	virtual void onEvent(Event*);
	virtual void run();
public:
	bool direction(MouseCode);
public:
	int curX;
	int curY;
	int prvX;
	int prvY;
	int m_delta = 30;
};

