#include <iostream>
#include "Zodiac.h"

class ExampleLayer : public Zodiac::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{
	}

	void OnEvent(Zodiac::Event& e) override
	{
	}

	void OnAttach() override
	{
		ZO_INFO("ExampleLayer::Attached");
	}

	void OnDetach() override
	{
		ZO_INFO("ExampleLayer::Detached");
	}
};

class Playground : public Zodiac::Application 
{
public:
	Playground() {
		PushLayer(new  ExampleLayer());
		PushOverlay(new Zodiac::ImGuiLayer());
	};
	~Playground() {};
};

Zodiac::Application* Zodiac::CreateApplication() 
{
	return new Playground();
}