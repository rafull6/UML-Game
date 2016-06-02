#include "Unit.h"
#include "Pause.h"
#include "FightStage.h"
#include "../resource/GameResource.h"


//spSprite sp = new Sprite;

Unit::Unit(): _game(0), _dead(false){
	
}

void Unit::init(const Vector2& pos, float rotation, FightStage* game){
    //initialize base
    _game = game;

	_view = new Actor();
	_view->attachTo(game);
    _view->setPosition(pos);
	_view->setRotationDegrees(rotation);

    //adds to global units list
    _game->_units.push_back(this);
	
    //should be overloaded in inherited classes
    _init();


	/*
	sp->setResAnim(GameResource::ui.getResAnim("pause"));
	sp->setAnchor(Vector2(0.5f, 0.5f));
	sp->setScale(0);
	->addTween(Sprite::TweenScale(1.0f), 1);*/
}

const Vector2& Unit::getPosition() const{
    return _view->getPosition();
}

void Unit::setPosition(Vector2 newPosition) {
	this->_view->setPosition(newPosition);
}

void Unit::update(const UpdateState& us)
{
	const Uint8* keyDown = SDL_GetKeyboardState(0);
	spPause pause = new Pause();

	if (keyDown[_pauseKey])
		if (_lastPause + 300 < us.time){
			_lastPause = us.time;
			Unit::_isPaused = !_isPaused;
			if (Unit::_isPaused == true) {
				//pause->init(Point(0, 0), 0, _game);   ta linijka krzaczy
			}
	}

	if (_isPaused == false) {
		pause->pauseDie(Unit::_isPaused);
		_update(us);
	}


}

float Unit::getHeight() {
	return this->_view->getHeight();
}

float Unit::getWidth() {
	return this->_view->getWidth();
}

bool Unit::getIsPaused() {
	return this->_isPaused;
}