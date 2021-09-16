#pragma once

#include "Zodiac/Window.h"
#include "GLFW/glfw3.h"
#include "Zodiac/Events/ApplicationEvent.h"
#include "Zodiac/Events/KeyEvent.h"
#include "Zodiac/Events/MouseEvent.h"
#include "Zodiac/Log.h"

namespace Zodiac {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		uint32_t GetWidth() const override { return m_Data.Width; };
		uint32_t GetHeight() const override { return m_Data.Height; };

		void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; };
		void SetVSync(bool enabled) override;
		bool IsVSync() const override { return m_Data.vSync; };

		inline virtual void* GetNativeWindow() const { return m_Window; };

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* m_Window;
		
		struct WindowData {
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool vSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;

	};
}