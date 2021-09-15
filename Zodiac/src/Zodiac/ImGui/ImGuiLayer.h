#pragma once
#include "Zodiac/Layer.h"
#include "Zodiac/Events/Event.h"
#include "Zodiac/Events/ApplicationEvent.h"
#include "Zodiac/Events/MouseEvent.h"
#include "Zodiac/Events/KeyEvent.h"

namespace Zodiac {
	class ZODIAC_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate() override;
		void OnEvent(Event& e) override;
		void OnAttach() override;
		void OnDetach() override;
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnWindowResizedEvent(WindowResizedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);

	private:
		float m_Time = 0.0f;
	};
}