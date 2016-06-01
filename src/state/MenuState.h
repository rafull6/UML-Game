#include "State.h"
#include "../display/InputField.h"
#include "../resource/GameResource.h"

DECLARE_SMART(MenuState, spMenuState);

class MenuState : public State{
private:
	spSprite     _mainMenu;
	spTween      _mainMenuTween;
	spInputField _currentTF;
	spInputText  _input;

	void _initSettings(const std::string& playerName1, const std::string &playerName2);
	void _initMenu();
	void onClickTF(Event* ev);
	void onEvent(Event* ev);
	void onComplete(Event* ev);
	void onTweenDone(Event* ev);
public:
	MenuState();
	static spMenuState instance;
	Tween::EASE _ease;
	spActor _easeGraph;

	/*void _addTween(spTween tween)
	{
		tween->setEase(_ease);
		_sprite->addTween(tween);
	}
	int dur = 2000;
	//_addTween(createTween(Actor::TweenRotation(_sprite->getRotation() + (float)MATH_PI * 2), dur, 1));
	*/
};