#pragma once
#include "oxygine-framework.h"
#include "Unit.h"

DECLARE_SMART(Rocket, spRocket);
class Rocket: public Unit{
protected:
	void _init();
	void _update(const UpdateState& us);
	void explode();

	std::string _senderName;
	Vector2 _dir;

public:
    Rocket(const Vector2& dir, std::string senderName);
};