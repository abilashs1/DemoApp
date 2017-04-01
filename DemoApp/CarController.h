#pragma once
#include "Controller.h"

class CarController :
	public Controller
{
public:
	CarController(std::shared_ptr<EventHandler>);
	virtual ~CarController();
};

