#pragma once
#include "Unit.h"

using namespace oxygine;

DECLARE_SMART(Pickup, spPickup);
class Pickup : public Unit{
protected:
	void _init();
	void _update(const UpdateState& us);
	void _die();
	std::string  _type; //wpn/pup
	int _id; //with one
	Vector2 _pos; //where

public:
	Pickup(std::string type, int id);
	~Pickup();
};

