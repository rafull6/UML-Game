#include "Game.h"
#include "Player.h"
#include "resources.h"
#include "Obstacle.h"
<<<<<<< HEAD
=======
#include "Pickup.h"
>>>>>>> powerup-object

Game::Game()
{

}

Game::~Game()
{

}

void Game::init()
{
    //scene layer would have size of display
    setSize(getStage()->getSize());

    //create background
    spSprite sky = new Sprite;
    sky->setResAnim(resources::ui.getResAnim("sky"));
    sky->attachTo(this);

    //create separate layer for elements virtual joystick and other UI in future
    _ui = new Actor;
    _ui->attachTo(this);
    //it would be higher than other actors with default priority = 0
    _ui->setPriority(1);



    //create obstacles
    for (int i = 0; i < 10; ++i)
    {
        spObstacle obstacle = new Obstacle;
        obstacle->init(Vector2(scalar::randFloat(0, getWidth()), scalar::randFloat(0, getHeight())), this);
    }


<<<<<<< HEAD
=======
		spPickup pickup_pup0 = new Pickup("pup",0);
		pickup_pup0->init(Vector2(scalar::randFloat(0, getWidth()), scalar::randFloat(0, getHeight())), this);
		spPickup pickup_pup1 = new Pickup("pup", 1);
		pickup_pup1->init(Vector2(scalar::randFloat(0, getWidth()), scalar::randFloat(0, getHeight())), this);
		spPickup pickup_wpn0 = new Pickup("wpn", 0);
		pickup_wpn0->init(Vector2(scalar::randFloat(0, getWidth()), scalar::randFloat(0, getHeight())), this);
		spPickup pickup_wpn1 = new Pickup("wpn" ,1);
		pickup_wpn1->init(Vector2(scalar::randFloat(0, getWidth()), scalar::randFloat(0, getHeight())), this);

>>>>>>> powerup-object
    //create player ship
    _player = new Player("Player1");
    _player->init(getSize() / 2, this);



	//create player ship2
	_player2 = new Player("Player2");
	_player2->init(getSize() / 3, this);

}

void Game::doUpdate(const UpdateState& us)
{
    //update all units
    //ships, rockets and obstacles are in this list
    for (units::iterator i = _units.begin(); i != _units.end();)
    {
        spUnit unit = *i;
        unit->update(us);

        if (unit->isDead())
        {
            //it is dead. Time to remove it from list
            i = _units.erase(i);
        }
        else
        {
            ++i;
        }
    }
}