#include <iostream>
#include "Zodiac.h"

class Playground : public Zodiac::Application 
{
public:
	Playground() {};
	~Playground() {};
};

Zodiac::Application* Zodiac::CreateApplication() 
{
	return new Playground();
}