#pragma once
#include "oxygine_include.h"
#include "Unit.h"

using namespace oxygine;

DECLARE_SMART(AircraftFighter, spAircraftFighter);

class AircraftFighter : public Unit{
protected:
	const char*  _color;
	const char*  _name;
	float        _speed;
	float        _speedMultiplier =1.0f;
	float        _speedPickUpMultiplier[2] = { 0.0f, 0.0f };
	timeMS       _lastPickUp[4] = { 0,0,0,0 };
	timeMS		 _currentTime;
	bool         _isFrozen;
	int          _hp;
	int*         _keyMap;
	RectF        _bounds;
	timeMS       _lastBulletSpawn =0;
	spSprite     _ship;

	void _init();
	void _update(const UpdateState& us);
	void _setDefaultKeys();

public:
	AircraftFighter();
	AircraftFighter(const char* name, const char* color);
	bool changeSpeed(bool accelerate);
	void setKeys(int* keyMap);
	int hit(int damage);
	void pickupPup(int id);
	void pickupWpn(int id);
	void die();
};