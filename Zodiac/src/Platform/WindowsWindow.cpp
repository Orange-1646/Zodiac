#include "zopch.h"
#include "WindowsWindow.h"
#include "Zodiac/Core.h"

namespace Zodiac {

	static bool s_GLFWInitialized = false;
	static void GLFWErrorCallback(int errCode, const char* errMsg)
	{
		ZO_CORE_ERROR("GLFW Error ({0}): {1}", errCode, errMsg);
	}

	 WindowsWindow::WindowsWindow(const WindowProps& props)
	 {
		Init(props);
	 }
	 WindowsWindow:: ~WindowsWindow()
	 {
		 Shutdown();
	 }
	Window* Window::Create(const WindowProps & props)
	{
		return new WindowsWindow(props);
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			ZO_CORE_ASSERT(success, "GLFW initialization failed!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// Set GLFW Callbacks

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				data.Width = width;
				data.Height = height;

				WindowResizeEvent resizeEvent(width, height);
				data.EventCallback(resizeEvent);
			});
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowCloseEvent closeEvent;

				data.EventCallback(closeEvent);
			});
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
				{
					ZO_CORE_INFO("Key Pressed");
					break;
				}
				case GLFW_RELEASE:
				{
					ZO_CORE_INFO("Key Released");
					break;
				}
				case GLFW_REPEAT:
				{
					ZO_CORE_INFO("Key Repeat");
					break;
				}
				}
			});
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
				{
					ZO_CORE_INFO("Mouse Pressed");
					break;
				}
				case GLFW_RELEASE:
				{
					ZO_CORE_INFO("Release Released");
					break;
				}
				}
			});
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				ZO_CORE_INFO("Scrolling: {0} - {1}", xOffset, yOffset);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				ZO_CORE_INFO("Cursor Moving: {0} - {1}", xPos, yPos);
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		m_Data.vSync = enabled;
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}
}