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
	logo->setX(_view->getWidth() - logo->getWidth() - 20);
	logo->setY(_view->getHeight() - (_view->getHeight() - logo->getHeight()/4));

	//create menu block
	spSprite menu_bg = initActor(new Sprite,
		arg_resAnim = GameResource::ui.getResAnim("menu-bg"),
		arg_anchor = Vector2(0.5f, 0.5f),
		arg_attachTo = _view);
	menu_bg->setX(_view->getWidth() / 2);
	menu_bg->setY((_view->getHeight() / 2) + 80);

	//create play button
	spSprite playBtn = initActor(new mButton,
		arg_name = "play-normal",
		arg_resAnim = GameResource::ui.getResAnim("play_n"),
		arg_anchor = Vector2(0.5f, 0.5f),
		arg_attachTo = menu_bg);

	playBtn->setX(menu_bg->getWidth() / 2);
	playBtn->setY(menu_bg->getHeight() - (menu_bg->getHeight() - playBtn->getHeight()*2));

	//create settings button
	spSprite setBtn = initActor(new mButton,
		arg_name = "set-normal",
		arg_resAnim = GameResource::ui.getResAnim("set_n"),
		arg_anchor = Vector2(0.5f, 0.5f),
		arg_attachTo = menu_bg);
	setBtn->setX(menu_bg->getWidth() / 2);
	setBtn->setY(playBtn->getY()+ setBtn->getHeight()+10);

	//create git button
	spSprite gitBtn = initActor(new mButton,
		arg_name = "git-normal",
		arg_resAnim = GameResource::ui.getResAnim("git_n"),
		arg_anchor = Vector2(0.5f, 0.5f),
		arg_attachTo = menu_bg);
	gitBtn->setX(menu_bg->getWidth() / 2);
	gitBtn->setY(setBtn->getY() + gitBtn->getHeight() + 10);

	//create auth button
	spSprite authBtn = initActor(new mButton,
		arg_name = "auth-normal",
		arg_resAnim = GameResource::ui.getResAnim("auth_n"),
		arg_anchor = Vector2(0.5f, 0.5f),
		arg_attachTo = menu_bg);
	authBtn->setX(menu_bg->getWidth() / 2);
	authBtn->setY(gitBtn->getY() + authBtn->getHeight() + 10);

	//create auth button
	spSprite exitBtn = initActor(new mButton,
		arg_name = "exit-normal",
		arg_resAnim = GameResource::ui.getResAnim("exit_n"),
		arg_anchor = Vector2(0.5f, 0.5f),
		arg_attachTo = menu_bg);
	exitBtn->setX(menu_bg->getWidth() / 2);
	exitBtn->setY(authBtn->getY() + exitBtn->getHeight() + 10);
	
	/*spSprite _sprite = new Sprite();
	_sprite->attachTo(_view);
	_sprite->setAnchor(0.5f, 0.5f);
	_sprite->setResAnim(GameResource::ui.getResAnim("engines"));

	_sprite->setX(_view->getWidth() / 2 - 117);
	_sprite->setY(_view->getHeight() / 2 - 185);
	
	int dur = 2000;
	_addTween(createTween(TweenAnim(GameResource::ui.getResAnim("anim")), dur / 4, 10));
*/
}

void MenuState::onEvent(Event* ev)
{
	//string id = ev->currentTarget->getName();
	if (ev->currentTarget->getName() == "exit-normal")
	{
		core::requestQuit();
	}

	if (ev->currentTarget->getName() == "play-normal")
	{
		log::messageln("mode changed");
		//clicked to play button change scene
		changeState(FightState::instance);
	}
}