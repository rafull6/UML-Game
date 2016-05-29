#include "MenuState.h"
#include "Sprite.h"
#include "initActor.h"
#include "../resource/GameResource.h"
#include "../display/mButton.h"
#include "FightState.h"

using namespace std;

spMenuState MenuState::instance;

MenuState::MenuState()
{
	//create background
	spSprite sky = new Sprite;
	sky->setResAnim(GameResource::ui.getResAnim("bg"));
	sky->attachTo(_view);

	//create logo
	spSprite logo = initActor(new Sprite,
		arg_resAnim = GameResource::ui.getResAnim("logotype"),
		arg_attachTo = _view);
	logo->setPosition(_view->getSize() - logo->getSize());

	//create menu block
	spSprite menu_bg = initActor(new Sprite,
		arg_resAnim = GameResource::ui.getResAnim("menu-bg"),
		arg_anchor = Vector2(0.5f, 0.5f),
		arg_attachTo = _view);
	menu_bg->setX(_view->getWidth() / 2);
	menu_bg->setY((_view->getHeight() / 2) + 80);

	//create play button
	spSprite play_n = initActor(new mButton,
		arg_name = "play-normal",
		arg_resAnim = GameResource::ui.getResAnim("play_n"),
		arg_anchor = Vector2(0.5f, 0.5f),
		arg_attachTo = menu_bg);

	play_n->setX(menu_bg->getWidth() / 2);
	play_n->setY(menu_bg->getHeight() - (menu_bg->getHeight() - play_n->getHeight()*2));

	//create settings button
	spSprite set_n = initActor(new mButton,
		arg_name = "set-normal",
		arg_resAnim = GameResource::ui.getResAnim("set_n"),
		arg_anchor = Vector2(0.5f, 0.5f),
		arg_attachTo = menu_bg);

	set_n->setX(menu_bg->getWidth() / 2);
	set_n->setY(menu_bg->getHeight() - (menu_bg->getHeight() - set_n->getHeight() * 3 - 10));

	//create git button
	spSprite git_n = initActor(new mButton,
		arg_name = "git-normal",
		arg_resAnim = GameResource::ui.getResAnim("git_n"),
		arg_anchor = Vector2(0.5f, 0.5f),
		arg_attachTo = menu_bg);

	git_n->setX(menu_bg->getWidth() / 2);
	git_n->setY(menu_bg->getHeight() - (menu_bg->getHeight() - git_n->getHeight() * 4 - 10));
}

void MenuState::onEvent(Event* ev)
{
	string id = ev->currentTarget->getName();
	if (id == "exit")
	{
		core::requestQuit();
	}

	if (id == "play")
	{
		//clicked to play button change scene
		changeState(FightState::instance);
	}
}