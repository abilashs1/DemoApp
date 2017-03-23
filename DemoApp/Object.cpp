#include "Object.h"
#include "Controller.h"
#include <iostream>

Object::Object()
{
}


Object::~Object()
{
}

void Object::setController(std::shared_ptr<Controller> d)
{
	m_controller = d;
}

bool Object::run()
{
	if (m_controller->forward())
	{
		std::cout << __func__ << " forward Object " << m_id << std::endl;
	}
	if (m_controller->reverse())
	{
		std::cout << __func__ << " reverse Object " << m_id << std::endl;
	}
	if (m_controller->left())
	{
		std::cout << __func__ << " left Object " << m_id << std::endl;
	}
	if (m_controller->right())
	{
		std::cout << __func__ << " right Object " << m_id << std::endl;
	}
	return true;
}
