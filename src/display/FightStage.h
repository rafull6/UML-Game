#pragma once
#include "oxygine-framework.h"
#include "AircraftFighter.h"
#include <list>
#include "Unit.h"
#include "Pause.h"

using namespace oxygine;

DECLARE_SMART(FightStage, spFightStage);

class FightStage : public Actor {
protected:
	friend class AircraftFighter; 
	friend class Rocket;
	friend class Unit;
	friend class Pickup;
	bool		_isPaused = false;
	int			_pauseKey = SDL_SCANCODE_P;
	timeMS      _lastPause;

	spAircraftFighter _af1;
	spAircraftFighter _af2;

	spPause pause;

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