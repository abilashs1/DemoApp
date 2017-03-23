#pragma once
#include "Controller.h"

class EventHandler;

class KeyboardController :
	public Controller
{
public:
	KeyboardController(std::shared_ptr<EventHandler>);
	virtual ~KeyboardController();
public:
	virtual bool forward();
	virtual bool reverse();
	virtual bool left();
	virtual bool right();
};

