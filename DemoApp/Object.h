#pragma once
#include <memory>
#include <string>
class Controller;

class Object
{
public:
	Object();
	virtual ~Object();
public:
	void setController(std::shared_ptr<Controller>);
	bool run();
	void id(int id)
	{
		m_id = id;
	}
protected:
	std::shared_ptr<Controller> m_controller;
	unsigned int					m_id;
};

