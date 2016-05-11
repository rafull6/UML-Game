#pragma once
#include "oxygine-framework.h"
#include <list>
using namespace oxygine;

DECLARE_SMART(Player, spPlayer);
DECLARE_SMART(Game, spGame);
DECLARE_SMART(Rocket, spRocket);
DECLARE_SMART(Unit, spUnit);
DECLARE_SMART(Pickup, spPickup);

class Game: public Actor
{
public:
    Game();
    ~Game();

    void init();

protected:
    friend class Rocket;
    friend class Player;
    friend class Unit;
	friend class Pickup;

    void doUpdate(const UpdateState& us);

    spActor _ui;

    spPlayer _player;
	spPlayer _player2;
    typedef std::list<spUnit> units;
    units _units;
};