#pragma once
#include "oxygine-framework.h"
#include "State.h"
#include "../display/FightStage.h"

using namespace oxygine;

DECLARE_SMART(FightState, spFightState);

class FightState : public State{
private:
	spFightStage _fightContainer;

	void onEvent(Event* event);

public:
	static spFightState instance;
	FightState();
};