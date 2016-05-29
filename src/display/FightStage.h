#pragma once
#include "oxygine-framework.h"
#include "AircraftFighter.h"
#include <list>

using namespace oxygine;

DECLARE_SMART(FightStage, spFightStage);

class FightStage : public Actor {
protected:
	friend class AircraftFighter; 
	friend class Rocket;
	friend class Unit;
	friend class Pickup;

	spAircraftFighter _af1;
	spAircraftFighter _af2;

	spSprite _bg;

	std::list<spUnit> _units;

	void doUpdate(const UpdateState& us);
	void _showMenu();

public:
	FightStage();
	~FightStage();

	void init();
	void onEvent(Event* ev);
};