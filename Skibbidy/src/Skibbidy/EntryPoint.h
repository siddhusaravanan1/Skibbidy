#pragma once

#ifdef SKD_PLATFORM_WINDOWS
extern Skibbidy::Application* Skibbidy::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Skibbidy::CreateApplication();
	Skibbidy::Log::init();
	Skibbidy::Log::GetCoreLogger()->critical("Krishna is gay");
	app->Run();
	delete app;
}
#endif