#include "Game.h"
#include "oxygine-framework.h"
#include "../resource/GameResource.h"
#include "../state/FightState.h"

using namespace oxygine;

Game::Game(const char* title) : title(title){
	this->iconPath = "../data/";
}

Game::~Game(){
}

void Game::init() {
	GameResource::load();

	// create all states
	FightState::instance = new FightState();

	// open state
	FightState::instance->show();
}

void Game::preinit() {

}

void Game::update() {

}

void Game::destroy() {
	GameResource::free();
}

/**
Load window image
*/
void Game::setWindowIcon(const char* bmpPath) {
	this->iconPath.append(bmpPath);

	SDL_Window* window = getStage()->getAssociatedWindow();
	SDL_Surface* surface = SDL_LoadBMP(this->iconPath.c_str());

	if (surface == NULL) {
		log::message("SDL can't load icon from: %s\n", SDL_GetError());
		SDL_FreeSurface(surface);
		return;
	}
	
	// The icon is attached to the window pointer
	SDL_SetWindowIcon(window, surface);

	SDL_FreeSurface(surface);
}

const char* Game::getTitle() {
	return this->title;
}

std::string Game::getWindowIcon() {
	return this->iconPath;
}