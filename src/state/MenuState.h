#include "State.h"
#include "../display/InputField.h"
#include "../resource/GameResource.h"

DECLARE_SMART(MenuState, spMenuState);

class MenuState : public State{
private:
	spSprite     _mainMenu;

	//animation special effects
	spSprite     _enginesAnimation;
	spSprite     _fireBottomAnimation;
	spSprite     _smokeLeftBottomAnimation;
	spSprite     _sparksTopRightAnimation;

	spTween      _mainMenuTween;
	spTween      _mainStateEffectsTween;
	spInputField _currentTF;
	spInputText  _input;

	void _initSettings(const std::string& playerName1, const std::string &playerName2);
	void _initMenu();
	void onClickTF(Event* ev);
	void onEvent(Event* ev);
	void onComplete(Event* ev);
	void onTweenDone(Event* ev);
	void _initEngineEffects();
	void _initFireBottomEffects();
	void _initSmokeBottomEffects();
	void _initSparksTopEffects();
public:
	MenuState();
	static spMenuState instance;
	Tween::EASE _ease;
	spActor _easeGraph;
};