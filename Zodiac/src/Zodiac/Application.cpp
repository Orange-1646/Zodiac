#include "zopch.h"
#include "Application.h"
#include "Zodiac/Events/ApplicationEvent.h"
#include "Zodiac/Log.h"
#include "glad/glad.h"
#include "Input.h"

namespace Zodiac {

		Application* Application::s_Instance = nullptr;

		Application::Application() 
		{
			s_Instance = this;
			m_Window = std::unique_ptr<Window>(Window::Create());
			m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
		};
		Application::~Application() 
		{
		};
		void Application::OnEvent(Event& e)
		{
			EventDispatcher dispatcher(e);

			dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
			for (auto iter = m_LayerStack.end(); iter != m_LayerStack.begin();)
			{
				(*--iter)->OnEvent(e);
				if (e.Handled)
				{
					break;
				}
			}
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

				for (Layer* layer : m_LayerStack)
				{
					layer->OnUpdate();
				}

				m_Window->OnUpdate();

				auto [x, y] = Input::GetMousePosition();

				ZO_CORE_TRACE("{0}, {1}", x, y);
			}
		}

		void Application::PushLayer(Layer* layer)
		{
			m_LayerStack.PushLayer(layer);
			layer->OnAttach();
		}

		void Application::PushOverlay(Layer* overlay)
		{
			m_LayerStack.PushOverlay(overlay);
			overlay->OnAttach();
		}
}