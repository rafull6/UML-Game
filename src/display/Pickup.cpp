#include "Pickup.h"
#include "../resource/GameResource.h"
#include "AircraftFighter.h"
#include "FightStage.h"
#include "Unit.h"

Pickup::Pickup(std::string type, int id, int quantity, double diameter):_type(type),_id(id),_quantity(quantity),_diameter(diameter){
}


Pickup::~Pickup(){
}


void Pickup::_init(){
	spSprite sprite = new Sprite;
	std::string resName = _type+ "-" + std::to_string(_id);
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

void Pickup::_update(const UpdateState& us) {
	for (std::list<spUnit>::iterator i = _game->_units.begin(); i != _game->_units.end(); ++i) {
		spUnit unit = *i;
		//list of units has everything, but we need only Enemies
		spAircraftFighter player = dynamic_cast<AircraftFighter*>(unit.get());


		if (!player) {
			continue;
		}
		else {
			Vector2 d = unit->getPosition() - _pos;
			if (d.length() < _diameter) {

				if (_lastPickUp + 300 < us.time) {
					_lastPickUp = us.time;
					log::message("Taken  %s-%d\n", _type.c_str(), _id);
					if (!_type.compare("wpn")) {
						player->pickupWpn(_id);
					}
					else
					{
						player->pickupPup(_id);
					}

					if (_quantity > 0)
					{
						_quantity--;

						//new pos
						//pickup_wpn0->init(Vector2(scalar::randFloat(0, getWidth()), scalar::randFloat(0, getHeight())), 0, this);
						Vector2 newPos = Vector2(scalar::randFloat(0, 640), scalar::randFloat(0, 520));

						this->_view->setPosition(newPos);
						//this->setPosition(newPos);
						_pos = newPos;
					}
					
					else if (_quantity == 0) _die();

					return;


				}
			}
		}
	}
}



void Pickup::_die(){
	//dead, hide it with alpha tween
	_dead = true;
	_view->addTween(Actor::TweenAlpha(0), 300)->setDetachActor(true);
}