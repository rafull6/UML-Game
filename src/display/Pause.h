#pragma once
#pragma once
#include "Unit.h"

DECLARE_SMART(Pause, spPause);
class Pause : public Unit
{
public:
	void pauseDie(bool pause);

private:
	void _init();
	void _update(const UpdateState& us);
	void _die();

};