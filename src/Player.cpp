#include "Player.h"
#include "Game.h"
#include "resources.h"

#include "Rocket.h"
#include "SDL.h"
#include "SDL_keyboard.h"
Player::Player(std::string playerName) : _lastRocketSpawn(0), _playerName(playerName)
{

}

void Player::_init()
{
    //initialize player's ship
   // _view->setPosition(_game->getSize() / 2);

    _ship = new Sprite;
    _ship->setResAnim(resources::ui.getResAnim("ship"));
    _ship->attachTo(_view);
    _ship->setAnchor(Vector2(0.5f, 0.5f));

    _engine = new Sprite;
    _engine->setResAnim(resources::ui.getResAnim("shipengine"));
    _engine->attachTo(_ship);
    //animate engine's fire
    _engine->addTween(Sprite::TweenColor(Color::Red), 100, -1, true);
    //by default it is hidden
    //and would be visible only if ship moves
    _engine->setVisible(false);
//	player = initActor(new Sprite, arg_resAnim = gameResources.getResAnim("anim"), arg_scale = 0.5f, arg_pos = Vector2(x, y), arg_attachTo = getRoot());
	_loadKeys();
	_hp = 5;


}


void Player::_update(const UpdateState& us)
{
    _engine->setVisible(false);

	float speed = 10.0f * (us.dt / 1000.0f);
	
	Vector2 pos = _view->getPosition();
	float angle = _view->getRotation();
	float angleRadian=_view->getRotationDegrees();
	const Uint8* data = SDL_GetKeyboardState(0);
	Vector2 dir;
	dir.set(speed * 10* sin(angleRadian), speed * 10 * cos( angleRadian));
	//Left
	if (data[_keyScanCode[0]]) angle -= speed;
	//Right
	if (data[_keyScanCode[1]]) angle += speed;
	//Forward
	if (data[_keyScanCode[2]])
	{
		pos+= dir;		
		_engine->setVisible(true);
	}
	//Backward
	if (data[_keyScanCode[3]])
	{ 
		pos -= dir;
		_engine->setVisible(true);
	}
	//shot
	if (data[_keyScanCode[4]])
	{

		if (_lastRocketSpawn + 300 < us.time)
		{
			_lastRocketSpawn = us.time;

			dir.normalize();

			//create rocket
			spRocket rocket = new Rocket(dir, _playerName);
			rocket->init(_view->getPosition(), _game);
		}
	}

	//log::message("pos(%f, %f)", pos.x, pos.y);
	_view->setPosition(pos);
	_view->setRotation(angle);
   



}


void Player::_loadKeys()
{
	
	oxygine::file::buffer data;

	//read entire file into buffer with stdio flags "rb"
	
	file::read(_playerName.c_str(), data, ep_ignore_error);
	if (!data.empty())
	{
		log::message("Keys loaded: %d\n", data.getSize());
		//modify buffer
		_keyScanCode[0] = data[0];
		_keyScanCode[1] = data[1];
		_keyScanCode[2] = data[2];
		_keyScanCode[3] = data[3];
		_keyScanCode[4] = data[4];
		//write file back from buffer with stdio flags "wb"

	}
	else
	{
    if (_playerName == "Player2") {
			data.push_back(SDL_SCANCODE_LEFT);
			data.push_back(SDL_SCANCODE_RIGHT);
			data.push_back(SDL_SCANCODE_UP);
			data.push_back(SDL_SCANCODE_DOWN);
			data.push_back(SDL_SCANCODE_RSHIFT);
	}
	else {
		data.push_back(SDL_SCANCODE_A);
		data.push_back(SDL_SCANCODE_D);
		data.push_back(SDL_SCANCODE_W);
		data.push_back(SDL_SCANCODE_S);
		data.push_back(SDL_SCANCODE_SPACE);
	}
		oxygine::file::write(_playerName.c_str(), data);
		log::message("Ther was no key file\n created default");
		_loadKeys();
	}


}

<<<<<<< HEAD
void Player::hit()
{
	//hit by rocket
	_hp--;
	if (_hp == 0)
	{
		//dead, hide it with alpha tween
		_dead = true;
		_view->addTween(Actor::TweenAlpha(0), 300)->setDetachActor(true);
	}
=======
void Player::hit(int damage)
{
	//hit by rocket
	_hp -= damage;
	log::message("Rocket hit %s hp left: %d\n", _playerName.c_str(),_hp);
	if (_hp <= 0)
	{
		_die();
	}
}

void Player::pickup_wpn(int id)
{
	//hit by rocket
	switch (id)
	{
		case 0:
		{
			//equip wpn 0
			_hp--;
			break;
		}
		case 1:
		{
			//equip wpn 1
			_hp++;
			break;
		}
		default:
		{
			//equip default wpn;

		}
	}
	log::message("%s pickup a gun! hp left: %d\n", _playerName.c_str(), _hp);
}

void Player::pickup_pup(int id)
{
	switch (id)
	{
	case 0:
	{
		//equip pup 0
		_hp++;
		break;
	}
	case 1:
	{
		//equip pup 1
		_hp--;
		break;
	}
	default:
	{
		//equip default pup;

	}
	
	}
	log::message("%s pickup a powerup! hp left: %d\n", _playerName.c_str(), _hp);
}

void Player::_die()
{

	
		//dead, hide it with alpha tween
		_dead = true;
		_view->addTween(Actor::TweenAlpha(0), 300)->setDetachActor(true);
	
>>>>>>> powerup-object
}