#include "Pause.h"
#include "../resource/GameResource.h"
#include "AircraftFighter.h"
#include "FightStage.h"
#include "Unit.h"

Pause::Pause() {
}


Pause::~Pause() {
}


void Pause::_init() {
	//you could hit obstacle 3 times
	spSprite sprite = new Sprite;
	sprite->setResAnim(GameResource::ui.getResAnim("pause"));
	sprite->attachTo(_view);
	sprite->setAnchor(Vector2(0.5f, 0.5f));
}

void Pause::_update(const UpdateState& us) {
	/*
	const Uint8* keyDown = SDL_GetKeyboardState(0);

	if (_isPaused == false) {
		this->_view->setVisible(false);
	}
	else {
		this->_view->setVisible(true);
	}*/
}


void Pause::_die() {
	//dead, hide it with alpha tween
	_dead = true;
	_view->addTween(Actor::TweenAlpha(0), 300)->setDetachActor(true);
}