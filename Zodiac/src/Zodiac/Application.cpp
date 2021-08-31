#include "zopch.h"
#include "Application.h"
#include "Zodiac/Events/ApplicationEvent.h"
#include "Zodiac/Log.h"
#include "GLFW/glfw3.h"

namespace Zodiac {

		Application::Application() 
		{
			m_Window = std::unique_ptr<Window>(Window::Create());
		};
		Application::~Application() 
		{
		};

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