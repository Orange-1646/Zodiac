#pragma once

#ifdef ZO_PLATFORM_WINDOWS
	#ifdef ZO_BUILD_DLL
		#define ZODIAC_API __declspec(dllexport)
	#else
		#define ZODIAC_API __declspec(dllimport)
	#endif
#else
	#error Zodiac Engine only supports windows for now.
#endif

#ifdef ZO_ENABLE_ASSERTS
	#define ZO_ASSERT(x, ...) { if(!x) { ZO_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ZO_CORE_ASSERT(x, ...) { if(!x) { ZO_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ZO_ASSERT(x, ...) 
	#define ZO_CORE_ASSERT(x, ...) 
#endif

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)