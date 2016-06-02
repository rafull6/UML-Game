#include "Config.h"

bool Config::loadConfig(const char* source) {
	file::buffer fileData;

	// read into the buffer if exists
	if(!file::exists(source)) {
		log::messageln("config file does not exist");
		return false;
	}
	
	// read file
	file::read(source, fileData);
	
	// parse file as json
	Json::Reader jreader;
	Json::Value  jvalue;
	
	jreader.parse((char*)&fileData.front(), (char*)&fileData.front() + fileData.size(), jvalue, false);

	// get data from file
	// game data
	this->_playerName1 = jvalue["game"]["playerName1"].asString();
	this->_playerName2 = jvalue["game"]["playerName2"].asString();

	// get player keys
	this->_playerKey1[0] = jvalue["player1"]["key_up"].asInt();
	this->_playerKey1[1] = jvalue["player1"]["key_right"].asInt();
	this->_playerKey1[2] = jvalue["player1"]["key_down"].asInt();
	this->_playerKey1[3] = jvalue["player1"]["key_left"].asInt();
	this->_playerKey1[4] = jvalue["player1"]["key_shot"].asInt();

	this->_playerKey2[0] = jvalue["player2"]["key_up"].asInt();
	this->_playerKey2[1] = jvalue["player2"]["key_right"].asInt();
	this->_playerKey2[2] = jvalue["player2"]["key_down"].asInt();
	this->_playerKey2[3] = jvalue["player2"]["key_left"].asInt();
	this->_playerKey2[4] = jvalue["player2"]["key_shot"].asInt();
	
	return true;
};

bool Config::saveConfig() {
	return false;
};

std::string Config::getPlayerName(int id) {
	if (id == 0) return _playerName1;
	return _playerName2;
}

int* Config::getPlayerKeys(int id) {
	if (id == 0) return _playerKey1;
	return _playerKey2;
};

std::string Config::toString(){
	std::string output;
	
	output.append("Aircraft Config\n\n[game]\n");
	output.append("Player1 name: ").append(this->_playerName1);
	output.append("\nPlayer2 name: ").append(this->_playerName2);
	output.append("\n\n[player 1]\n");
	output.append("key up: ").append(std::to_string(this->_playerKey1[0]));
	output.append("\nkey right: ").append(std::to_string(this->_playerKey1[1]));
	output.append("\nkey down: ").append(std::to_string(this->_playerKey1[2]));
	output.append("\nkey left: ").append(std::to_string(this->_playerKey1[3]));
	output.append("\nkey shot: ").append(std::to_string(this->_playerKey1[4]));
	output.append("\n\n[player 2]\n");
	output.append("key up: ").append(std::to_string(this->_playerKey2[0]));
	output.append("\nkey right: ").append(std::to_string(this->_playerKey2[1]));
	output.append("\nkey down: ").append(std::to_string(this->_playerKey2[2]));
	output.append("\nkey left: ").append(std::to_string(this->_playerKey2[3]));
	output.append("\nkey shot: ").append(std::to_string(this->_playerKey2[4]));

	return output;
};