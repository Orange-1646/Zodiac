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
		ZO_INFO("ExampleLaye::Updated");
	}

	void OnEvent(Zodiac::Event& e) override
	{
		ZO_TRACE("{0}", e);
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