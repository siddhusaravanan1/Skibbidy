#pragma once
#ifdef SKD_PLATFORM_WINDOWS
	#ifdef SKD_BUILD_DLL
		#define SKD_API __declspec(dllexport)
	#else
		#define SKD_API __declspec(dllimport)
	#endif	
#else
	#error SKIBBIDY ONLY WORKS ON WINDOWS
#endif