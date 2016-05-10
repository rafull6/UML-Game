#include "oxygine-framework.h"
#include "resources.h"
#include "Game.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "GameMenu.h"
using namespace oxygine;


void aircraft_preinit()
{
}

void aircraft_init()
{
    //load resources
    resources::load();

    //create all scenes
    GameMenu::instance = new GameMenu;
    GameScene::instance = new GameScene;
    MainMenuScene::instance = new MainMenuScene;

    //show main menu
    MainMenuScene::instance->show();
}

void aircraft_update()
{

}

void aircraft_destroy()
{
    MainMenuScene::instance = 0;
    GameScene::instance = 0;
    GameMenu::instance = 0;

    resources::free();
}