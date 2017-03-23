#pragma once
#include "EventHandler.h"
class MouseHandler :
	public EventHandler
{
public:
	MouseHandler();
	virtual ~MouseHandler();

	virtual void onEvent(Event*);
	virtual void run();
public:
	int curX;
	int curY;
	int prvX;
	int prvY;
};

