#include "Pickup.h"
#include "../resource/GameResource.h"
#include "AircraftFighter.h"
#include "FightStage.h"
#include "Unit.h"

Pickup::Pickup(std::string type, int id) :_type(type), _id(id) {
}


Pickup::~Pickup(){
}


void Pickup::_init(){
	//you could hit obstacle 3 times
	spSprite sprite = new Sprite;
	std::string resName = _type + "-" + std::to_string(_id);
	sprite->setResAnim(GameResource::ui.getResAnim(resName));
	sprite->attachTo(_view);
	sprite->setAnchor(Vector2(0.5f, 0.5f));

	//it random scale and rotation
	sprite->setRotation(scalar::randFloat(0, MATH_PI * 2));
	//sprite->setScale(scalar::randFloat(0.15f, 0.22f));

	//it is rotating by tween with random speed
	float dest = MATH_PI * 2;
	if (rand() % 2 == 0) dest *= -1;
	dest += sprite->getRotation();
	sprite->addTween(Sprite::TweenRotation(dest), rand() % 12000 + 10000, -1);
	_pos = _view->getPosition();
}


void Pickup::_update(const UpdateState& us){
	
	for (std::list<spUnit>::iterator i = _game->_units.begin(); i != _game->_units.end(); ++i){
		spUnit unit = *i;
		//list of units has everything, but we need only Enemies
		spAircraftFighter player = dynamic_cast<AircraftFighter*>(unit.get());


		if (!player) {
			continue;
		} else {
			Vector2 d = unit->getPosition() - _pos;
			if (d.length() < 20){
				log::message("Taken %s-%d\n", _type.c_str(), _id);
				if (!_type.compare("wpn")){
					player->pickupWpn(_id);
				}
				else
				{
					player->pickupPup(_id);
				}
				_die();
				return;
			}
		}
	}
}


void Pickup::_die(){
	//dead, hide it with alpha tween
	_dead = true;
	_view->addTween(Actor::TweenAlpha(0), 300)->setDetachActor(true);
}