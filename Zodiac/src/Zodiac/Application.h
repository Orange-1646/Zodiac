#pragma once

#include "Core.h"
#include "Window.h"
#include "Zodiac/Events/ApplicationEvent.h"
#include "Zodiac/Layer.h"
#include "Zodiac/LayerStack.h"

namespace Zodiac {

	class ZODIAC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}

