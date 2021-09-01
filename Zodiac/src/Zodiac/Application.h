#pragma once

#include "Core.h"
#include "Window.h"
#include "Zodiac/Events/ApplicationEvent.h"

namespace Zodiac {

	class ZODIAC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);


	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}

