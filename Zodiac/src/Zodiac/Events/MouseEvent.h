#pragma once

#include "Zodiac/Events/Event.h"
namespace Zodiac {
	class ZODIAC_API MouseButtonPressedEvent : public Event
	{
	public:
		MouseButtonPressedEvent(int button)
			:m_MouseButton(button)
		{}

		int GetMouseButton() const
		{
			return m_MouseButton;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << "button: " << m_MouseButton;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);
	private:
		int m_MouseButton;
	};

	class ZODIAC_API MouseButtonReleasedEvent : public Event
	{
	public:
		MouseButtonReleasedEvent(int button)
			:m_MouseButton(button)
		{}

		int GetMouseButton() const
		{
			return m_MouseButton;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << "button: " << m_MouseButton;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);
	private:
		int m_MouseButton;
	};

	class ZODIAC_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			:m_X(x), m_Y(y)
		{}

		float GetX() const
		{
			return m_X;
		}

		float GetY() const
		{
			return m_Y;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << "x: " << m_X << "y: " << m_Y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);
	private:
		float m_X;
		float m_Y;
	};

	class ZODIAC_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float offsetX, float offsetY)
			:m_OffsetX(offsetX), m_OffsetY(offsetY)
		{}

		float GetOffsetX() const
		{
			return m_OffsetX;
		}

		float GetOffsetY() const
		{
			return m_OffsetY;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << "OffsetX: " << m_OffsetX << " OffsetY: " << m_OffsetY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);
	private:
		float m_OffsetX;
		float m_OffsetY;
	};
}