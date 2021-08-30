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

#define BIT(x) (1 << x)