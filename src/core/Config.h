#pragma once
#include "oxygine-framework.h"
#include "json/json.h"
#include <string>

using namespace oxygine;

class Config {
private:
	std::string _playerName1;
	std::string _playerName2;
	int         _playerKey1[5];
	int			_playerKey2[5];

	Config() {};

public:
	static Config& getInstance(){
		static Config instance; // Guaranteed to be destroyed.
							    // Instantiated on first use.
		return instance;
	}
	Config(Config const&) = delete;
	void operator=(Config const&) = delete;
	
	bool saveConfig();
	bool loadConfig(const char* source);
	std::string getPlayerName(int id);
	int* getPlayerKeys(int id);
	std::string toString();
};