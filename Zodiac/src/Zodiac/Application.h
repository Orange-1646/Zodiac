#pragma once

#include "Core.h"

namespace Zodiac {

	class ZODIAC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

