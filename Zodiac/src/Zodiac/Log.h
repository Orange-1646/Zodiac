#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace Zodiac {
	
	class ZODIAC_API Log
	{
	public:
		Log();
		~Log();

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// core log macros
#define ZO_CORE_TRACE(...)     ::Zodiac::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ZO_CORE_INFO(...)      ::Zodiac::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZO_CORE_WARN(...)      ::Zodiac::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZO_CORE_ERROR(...)     ::Zodiac::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ZO_CORE_FATAL(...)     ::Zodiac::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// client log macros
#define ZO_TRACE(...)          ::Zodiac::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ZO_INFO(...)           ::Zodiac::Log::GetClientLogger()->info(__VA_ARGS__)
#define ZO_WARN(...)           ::Zodiac::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ZO_ERROR(...)		   ::Zodiac::Log::GetClientLogger()->error(__VA_ARGS__)
#define ZO_FATAL(...)		   ::Zodiac::Log::GetClientLogger()->fatal(__VA_ARGS__)