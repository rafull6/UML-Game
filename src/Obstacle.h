#pragma once
#include "Unit.h"

DECLARE_SMART(Obstacle, spObstacle);
class Obstacle: public Unit
{
public:

    void hit(int damage);

private:
    void _init();
    void _update(const UpdateState& us);
    int _hp;
	void _die();
	
};