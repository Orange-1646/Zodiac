#include "zopch.h"
#include "Application.h"
#include "Zodiac/Events/ApplicationEvent.h"
#include "Zodiac/Log.h"
#include "GLFW/glfw3.h"

namespace Zodiac {
	
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
		Application::Application() 
		{
			m_Window = std::unique_ptr<Window>(Window::Create());
			m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
		};
		Application::~Application() 
		{
		};
		void Application::OnEvent(Event& e)
		{
			ZO_CORE_INFO("{0}", e);
			EventDispatcher dispatcher(e);

			dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));


		}

		bool Application::OnWindowClose(WindowCloseEvent& e)
		{
			ZO_CORE_INFO("Shutting Down Window");
			m_Running = false;
			return true;
		}

		void Application::Run() 
		{
			while (m_Running)
			{
				glClearColor(.3, .4, .5, 1.);
				glClear(GL_COLOR_BUFFER_BIT);
				m_Window->OnUpdate();
			}
		}
}