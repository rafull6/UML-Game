#include "FightStage.h"
#include "../resource/GameResource.h"
#include "Pickup.h"
#include "Pause.h"

FightStage::FightStage() {

}

FightStage::~FightStage() {
	//getStage()->removeEventListener(KeyEvent::KEY_DOWN);
}

void FightStage::init() {
	this->setSize(getStage()->getSize());

	// create background
	this->_bg = new Sprite();
	this->_bg->setResAnim(GameResource::ui.getResAnim("sky"));
	this->_bg->attachTo(this);

	spPickup pickup_pup0 = new Pickup("pup", 0);
	pickup_pup0->init(Vector2(scalar::randFloat(0, getWidth()), scalar::randFloat(0, getHeight())), 0, this);
	spPickup pickup_pup1 = new Pickup("pup", 1);
	pickup_pup1->init(Vector2(scalar::randFloat(0, getWidth()), scalar::randFloat(0, getHeight())), 0, this);
	spPickup pickup_wpn0 = new Pickup("wpn", 0);
	pickup_wpn0->init(Vector2(scalar::randFloat(0, getWidth()), scalar::randFloat(0, getHeight())), 0, this);
	spPickup pickup_wpn1 = new Pickup("wpn", 1);
	pickup_wpn1->init(Vector2(scalar::randFloat(0, getWidth()), scalar::randFloat(0, getHeight())), 0, this);

	
	pause = new Pause();
	pause->init(Point(0, 0), 0, this);


	// create aircrafts
	this->_af1 = new AircraftFighter();
	this->_af1->init(Vector2(0,0), 180, this);
	
	// update aircraft position
	this->_af1->setPosition(Vector2(this->getWidth() / 2 - this->_af1->getWidth() / 2, this->getHeight() - this->_af1->getHeight()));
	
	// add listeners
	//getStage()->addEventListener(KeyEvent::KEY_DOWN, CLOSURE(this, &FightStage::onEvent));
}

void FightStage::doUpdate(const UpdateState& us) {
	// update display objects
	const Uint8* keyDown = SDL_GetKeyboardState(0);

	if (keyDown[_pauseKey])
		if (_lastPause + 300 < us.time) {
			_lastPause = us.time;
			_isPaused = !_isPaused;
		}

	if (_isPaused == false) {
		pause->getView()->setVisible(false);
		for (std::list<spUnit>::iterator i = _units.begin(); i != _units.end(); ) {
			spUnit child = *i;
			child->update(us);

			if (child->isDead()) {
				//it is dead. Time to remove it from list
				i = _units.erase(i);
			}
			else {
				++i;
			}
		}
	} else {
		pause->getView()->setVisible(true);
	}
}

void FightStage::onEvent(Event* ev) {
	KeyEvent* ke = safeCast<KeyEvent*>(ev);
	
	if (ke->type == KeyEvent::KEY_DOWN) {
		switch (ke->data->keysym.scancode) {
		case SDL_SCANCODE_ESCAPE:
			log::messageln("escape down");
			break;
		default:
			log::messageln("other key pressed");
			//this->_af1->move(ke->data->keysym.scancode);
			break;
		}
	}
}

void FightStage::_showMenu() {

}