#pragma once
#include "Unit.h"

DECLARE_SMART(Obstacle, spObstacle);
class Obstacle: public Unit
{
public:

    void explode();

private:
    void _init();
    void _update(const UpdateState& us);
    int _hp;
};