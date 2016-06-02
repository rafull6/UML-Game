#include "Pause.h"
#include "../resource/GameResource.h"

void Pause::_init() {

	spSprite sprite = new Sprite;
	sprite->setResAnim(GameResource::ui.getResAnim("pause"));
	sprite->attachTo(_view);
	sprite->setAnchor(Point(0, 0));
	sprite->setScale(0);
}

void Pause::_update(const UpdateState& us) {
	//nothing to do
}

void Pause::pauseDie(bool pause) {
	
	if (pause == false) _die();
}

void Pause::_die() {
	//dead, hide it with alpha tween
	_dead = true;
	_view->addTween(Actor::TweenAlpha(0), 300)->setDetachActor(true);
}