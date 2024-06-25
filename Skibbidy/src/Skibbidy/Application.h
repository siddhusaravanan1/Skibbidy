#pragma once
#include "Core.h"
#include "iostream"

namespace Skibbidy
{
	class SKD_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	Application* CreateApplication();
}


