#pragma once
#include "Controller.h"
class FlightController :
	public Controller
{
public:
	FlightController(std::shared_ptr<EventHandler>);
	virtual ~FlightController();
public:
	virtual bool forward();
	bool strafe_up();
	bool strafe_down();
};

