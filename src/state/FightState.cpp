#include "FightState.h"

spFightState FightState::instance;

FightState::FightState() {
	_fightContainer = new FightStage();
	_fightContainer->init();
	_fightContainer->attachTo(this->_view);

	//_fightContainer->setClock(new Clock());


}

void FightState::onEvent(Event* event) {

	KeyEvent* ke = safeCast<KeyEvent*>(event);

	if (ke->type == KeyEvent::KEY_DOWN) {
		switch (ke->data->keysym.scancode) {
		case SDL_SCANCODE_P:
			_fightContainer->getClock()->pause();
			break;
		default:
			log::messageln("other key pressed");
			//this->_af1->move(ke->data->keysym.scancode);
			break;
		}
	}
	
}