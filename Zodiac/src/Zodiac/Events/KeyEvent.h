#pragma once

#include "Zodiac/Events/Event.h"
#include <string>
#include <sstream>

namespace Zodiac {
	class ZODIAC_API KeyEvent : public Event
	{
	public:
		KeyEvent(int keycode)
			:m_Keycode(keycode)
		{

		}

		int GetKeycode() const
		{
			return m_Keycode;
		}
	private:
		int m_Keycode;
	};

	class ZODIAC_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			:KeyEvent(keycode), m_RepeatCount(repeatCount)
		{}

		int GetRepeatCount() const
		{
			return m_RepeatCount;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << "key: " << GetKeycode() << " RepeatCount: " << m_RepeatCount;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);
	private:
		int m_RepeatCount;
	};

	class ZODIAC_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			:KeyEvent(keycode)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << "key: " << GetKeycode();
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);
	private:
	};

	class ZODIAC_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode)
			:KeyEvent(keycode)
		{

		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << "key: " << GetChar();
			return ss.str();
		}

		int GetChar() const
		{
			return GetKeycode();
		}

		EVENT_CLASS_TYPE(KeyTyped);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);
	};
}