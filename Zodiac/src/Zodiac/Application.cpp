#include "zopch.h"
#include "Application.h"
#include "Zodiac/Events/ApplicationEvent.h"
#include "Zodiac/Log.h"

namespace Zodiac {

		Application::Application() 
		{
		};
		Application::~Application() 
		{
		};

		void Application::Run() 
		{
			WindowResizeEvent e(720, 1280);
			ZO_CORE_TRACE(e);
			std::cout << "Welcome to Zodiac Engine!" << std::endl;
			std::cin.get();
		}
}