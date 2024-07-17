#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Skibbidy
{
	class SKD_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
//core log macros
#define SKD_CORE_TRACE(...)		::Skibbidy::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define SKD_CORE_INFO(...)		::Skibbidy::Log::GetCoreLogger()->info(__VA_ARGS__);
#define SKD_CORE_WARN(...)		::Skibbidy::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define SKD_CORE_ERROR(...)		::Skibbidy::Log::GetCoreLogger()->error(__VA_ARGS__);
#define SKD_CORE_CRITICAL(...)	::Skibbidy::Log::GetCoreLogger()->critical(__VA_ARGS__);

//client log macros
#define SKD_TRACE(...)			::Skibbidy::Log::GetClientLogger()->trace(__VA_ARGS__);
#define SKD_INFO(...)			::Skibbidy::Log::GetClientLogger()->info(__VA_ARGS__);
#define SKD_WARN(...)			::Skibbidy::Log::GetClientLogger()->warn(__VA_ARGS__);
#define SKD_ERROR(...)			::Skibbidy::Log::GetClientLogger()->error(__VA_ARGS__);
#define SKD_FATAL(...)			::Skibbidy::Log::GetClientLogger()->fatal(__VA_ARGS__);

