#pragma once
#include "Unit.h"


DECLARE_SMART(Pickup, spPickup);
class Pickup :
	public Unit
{
public:
	Pickup(std::string type,  int id);
	~Pickup();
protected:
	void _init();
	void _update(const UpdateState& us);
	void _die();
	std::string  _type; //wpn/pup
	int _id; //with one
	Vector2 _pos; //where


};

