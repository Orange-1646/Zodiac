#pragma once

#include "Application.h"

#ifdef ZO_PLATFORM_WINDOWS

extern Zodiac::Application* Zodiac::CreateApplication();

int main(int argc, char** argv) {

	Zodiac::Application* app = Zodiac::CreateApplication();
	app->Run();
	delete app;
}
#endif
