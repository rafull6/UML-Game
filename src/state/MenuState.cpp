#include "MenuState.h"
#include "Sprite.h"
#include "initActor.h"
#include "../resource/GameResource.h"
#include "../display/mButton.h"
#include "../core/Config.h"
#include "FightState.h"

using namespace std;

spMenuState MenuState::instance;

MenuState::MenuState(){
	//create background
	spSprite sky = new Sprite;
	sky->setResAnim(GameResource::ui.getResAnim("bg"));
	sky->attachTo(_view);

	// create engine
	spSprite engine = new Sprite();
	engine->attachTo(_view);
	engine->setAnchor(0.5f, 0.5f);
	engine->setResAnim(GameResource::ui.getResAnim("engines"));
	engine->setPosition(_view->getWidth() / 2.0f, _view->getHeight() / 2);

	engine->setX(_view->getWidth() / 2 - 117);
	engine->setY(_view->getHeight() / 2 - 185);

	//create logo
	spSprite logo = initActor(new Sprite,
		arg_resAnim = GameResource::ui.getResAnim("logotype"),
		arg_attachTo = _view);
	logo->setX(_view->getWidth() - logo->getWidth() - 20);
	logo->setY(_view->getHeight() - (_view->getHeight() - logo->getHeight()/4));

	//create menu block
	_mainMenu = initActor(new Sprite,
		arg_resAnim = GameResource::ui.getResAnim("menu-bg"),
		arg_anchor = Vector2(0.5f, 0.5f),
		arg_attachTo = _view);
	_mainMenu->setX(_view->getWidth() / 2);
	_mainMenu->setY((_view->getHeight() / 2) + 80);

	
	this->_initSettings(Config::getInstance().getPlayerName(0), Config::getInstance().getPlayerName(1));
	this->_initMenu();
	//int dur = 2000;
	//_addTween(createTween(TweenAnim(GameResource::ui.getResAnim("anim")), dur / 4, 10));
	
	// add events to menu
	_mainMenu->setName("Main Menu");
	_mainMenu->addEventListener(TouchEvent::CLICK, CLOSURE(this, &MenuState::onEvent));
}

void MenuState::_initMenu() {
	spActor menuClip = new Actor();
	menuClip->setSize(_mainMenu->getWidth(), _mainMenu->getHeight());
	menuClip->attachTo(_mainMenu);
	menuClip->setName("menuClip");

	//create play button
	spSprite playBtn = initActor(new mButton,
		arg_name = "play-normal",
		arg_resAnim = GameResource::ui.getResAnim("play_n"),
		arg_anchor = Vector2(0.5f, 0.5f),
		arg_attachTo = menuClip);
		playBtn->setX(menuClip->getWidth() / 2);
		playBtn->setY(menuClip->getHeight() - (menuClip->getHeight() - playBtn->getHeight() * 2));

		//create settings button
		spSprite setBtn = initActor(new mButton,
			arg_name = "set-normal",
			arg_resAnim = GameResource::ui.getResAnim("set_n"),
			arg_anchor = Vector2(0.5f, 0.5f),
			arg_attachTo = menuClip);
		setBtn->setX(menuClip->getWidth() / 2);
		setBtn->setY(playBtn->getY() + setBtn->getHeight() + 10);

		//create git button
		spSprite gitBtn = initActor(new mButton,
			arg_name = "git-normal",
			arg_resAnim = GameResource::ui.getResAnim("git_n"),
			arg_anchor = Vector2(0.5f, 0.5f),
			arg_attachTo = menuClip);
		gitBtn->setX(menuClip->getWidth() / 2);
		gitBtn->setY(setBtn->getY() + gitBtn->getHeight() + 10);

		//create auth button
		spSprite authBtn = initActor(new mButton,
			arg_name = "auth-normal",
			arg_resAnim = GameResource::ui.getResAnim("auth_n"),
			arg_anchor = Vector2(0.5f, 0.5f),
			arg_attachTo = menuClip);
		authBtn->setX(menuClip->getWidth() / 2);
		authBtn->setY(gitBtn->getY() + authBtn->getHeight() + 10);

		//create auth button
		spSprite exitBtn = initActor(new mButton,
			arg_name = "exit-normal",
			arg_resAnim = GameResource::ui.getResAnim("exit_n"),
			arg_anchor = Vector2(0.5f, 0.5f),
			arg_attachTo = menuClip);
		exitBtn->setX(menuClip->getWidth() / 2);
		exitBtn->setY(authBtn->getY() + exitBtn->getHeight() + 10);
}

void MenuState::_initSettings(const std::string& playerName1, const std::string &playerName2) {
	spActor settingsParent = new Actor();
	settingsParent->setSize(_mainMenu->getWidth(), _mainMenu->getHeight());

	_input = new InputText();
	_input->addEventListener(Event::COMPLETE, CLOSURE(this, &MenuState::onComplete));

	spTextField playerNameLabel = initActor(new TextField,
		arg_attachTo = settingsParent,
		arg_text = "Player 1:"
	);

	spInputField playerNameInput = new InputField(playerName1);
	playerNameInput->setAnchor(Vector2(0.5f, 0.5f));
	playerNameInput->setX(settingsParent->getWidth() / 2);
	playerNameInput->setY(settingsParent->getHeight() - (settingsParent->getHeight() - playerNameInput->getHeight() * 2));
	playerNameInput->attachTo(settingsParent);
	playerNameInput->addEventListener(TouchEvent::CLICK, CLOSURE(this, &MenuState::onClickTF));

	settingsParent->setName("settings");
	settingsParent->attachTo(_mainMenu);
	settingsParent->setAlpha(0);
};

void MenuState::onEvent(Event* ev) {
	const std::string target = ev->target->getName();

	// exit app
	if (target == "exit-normal") {
		core::requestQuit();
	}
	else if (target == "play-normal") {
		log::messageln("mode changed");
		//clicked to play button change scene
		changeState(FightState::instance);
	}
	else if (target == "set-normal") {
		_mainMenuTween = _mainMenu->addTween(Actor::TweenY(-300), 300);
		_mainMenuTween->setName("open-settings");
		_mainMenuTween->setDoneCallback(CLOSURE(this, &MenuState::onTweenDone));

		log::messageln("show settings");
	}
}

void MenuState::onClickTF(Event* ev) {
	log::messageln("tf clicked");
	if (_currentTF) {
		_currentTF->setColor(Color::White);
	}
	_currentTF = safeSpCast<InputField>(ev->currentTarget);
	_input->start(_currentTF->getText());
	log::messageln("input start");
	//_currentTF->setColor(Color::Red);
};

void MenuState::onComplete(Event * ev) {
	if (_currentTF) {
		_currentTF->setColor(Color::White);
	}
	_currentTF = 0;
	InputText::stopAnyInput();
};

void MenuState::onTweenDone(Event* ev) {
	log::message("tween done");

	log::messageln("%s", ev->target->getName().c_str());
	//if (ev->currentTarget->getName() == "open-settings"){
	_mainMenu->getChild("menuClip")->setAlpha(0);
	_mainMenu->getChild("settings")->setAlpha(255);
		
	_mainMenu->addTween(Actor::TweenY((_view->getHeight() / 2) + 80), 300, 1, false, 500);
	//}
}