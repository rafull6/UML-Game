#pragma once
#include "Unit.h"

DECLARE_SMART(Player, spPlayer);

class Player: public Unit
{
public:
     Player(std::string playerName);
	 void hit(int damage);
	 void _die();
	 std::string getPlayerName()
	 {
		 return _playerName;
	 };
	 void pickup_pup(int id);
	 void pickup_wpn(int id);

private:
    void _init();
    void _update(const UpdateState& us);
    spSprite _engine;
    spSprite _ship;
    timeMS _lastRocketSpawn;
	int _keyScanCode[5];
	std::string _playerName;
	void _loadKeys();
	int _hp;
};
