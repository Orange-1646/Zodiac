#pragma once


#ifdef ZO_PLATFORM_WINDOWS

extern Zodiac::Application* Zodiac::CreateApplication();
#include "Log.h"

int main(int argc, char** argv) {

	Zodiac::Log::Init();
	ZO_CORE_INFO("Initialized Loggers");
	ZO_INFO("Hello!");

	Zodiac::Application* app = Zodiac::CreateApplication();
	app->Run();
	delete app;
}
#endif
