#pragma once
#include "Unit.h"

DECLARE_SMART(Player, spPlayer);

class Player: public Unit
{
public:
     Player(std::string playerName);
	 void hit();

	 std::string getPlayerName()
	 {
		 return _playerName;
	 };
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
