#include "Application.h"
#include <iostream>

namespace Zodiac {

		Application::Application() 
		{
		};
		Application::~Application() 
		{
		};

		void Application::Run() 
		{
			std::cout << "Welcome to Zodiac Engine!" << std::endl;
			std::cin.get();
		}
}