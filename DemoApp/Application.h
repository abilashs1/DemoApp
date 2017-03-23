#pragma once
#include <memory>
#include "defines.h"

class System;
class Application
{
public:
	Application(Platform);
	~Application();
public:
	void initialise();
	void run();
private:
	void initialiseHandler();
private:
	std::unique_ptr<System> m_system;
	Platform				m_platform;

};

