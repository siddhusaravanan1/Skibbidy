#include "Skibbidy.h"

class Sandbox : public Skibbidy::Application
{
public:
	Sandbox()
	{
		
	}

	~Sandbox()
	{
		 
	}
};

Skibbidy::Application* Skibbidy::CreateApplication()
{
	return new Sandbox();
}