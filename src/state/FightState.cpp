#include "FightState.h"

spFightState FightState::instance;

FightState::FightState() {
	_fightContainer = new FightStage();
	_fightContainer->init();
	_fightContainer->attachTo(this->_view);

	_fightContainer->setClock(new Clock());

}

void FightState::onEvent(Event* event) {
	
}