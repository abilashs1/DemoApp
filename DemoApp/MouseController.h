#pragma once
#include "Controller.h"
class MouseController :
	public Controller
{
public:
	MouseController(std::shared_ptr<EventHandler>);
	virtual ~MouseController();

public:
	virtual bool forward();
	virtual bool reverse();
	virtual bool left();
	virtual bool right();
private:
	int m_delta;
};

