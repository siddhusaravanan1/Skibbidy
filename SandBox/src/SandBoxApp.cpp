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

int main()
{
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}