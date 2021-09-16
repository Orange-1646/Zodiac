#pragma once
#include "Zodiac/Input.h"

namespace Zodiac {
	class ZODIAC_API WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int keycode) override;
		virtual double GetMouseXImpl() override;
		virtual double GetMouseYImpl() override;
		virtual std::pair<double, double> GetMousePositionImpl() override;
	};
}