#pragma once
#include "oxygine-framework.h"


using namespace oxygine;

class Game{
private:
	const char* title;
	std::string iconPath;

public:
	Game(const char* title);
	~Game();
	void preinit();
	void init();
	void destroy();
	void update();
	void setWindowIcon(const char* bmpSource);
	const char* getTitle();
	std::string getWindowIcon();
};
