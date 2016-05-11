#pragma once
#include "Unit.h"

DECLARE_SMART(Obstacle, spObstacle);
class Obstacle: public Unit
{
public:

<<<<<<< HEAD
    void explode();
=======
    void hit(int damage);
>>>>>>> powerup-object

private:
    void _init();
    void _update(const UpdateState& us);
    int _hp;
<<<<<<< HEAD
=======
	void _die();
	
>>>>>>> powerup-object
};