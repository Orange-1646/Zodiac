#include "zopch.h"
#include "WindowsWindow.h"
#include "Zodiac/Core.h"

namespace Zodiac {

	static bool s_GLFWInitialized = false;

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
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
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