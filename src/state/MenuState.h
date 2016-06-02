#include "State.h"
#include "../display/InputField.h"
#include "../resource/GameResource.h"

DECLARE_SMART(MenuState, spMenuState);

class MenuState : public State{
private:
	spSprite     _mainMenu;
	spSprite     _playerSettings;

	//animation special effects
	spSprite     _enginesAnimation;
	spSprite     _fireBottomAnimation;
	spSprite     _smokeLeftBottomAnimation;
	spSprite     _sparksTopRightAnimation;

	spTween      _mainMenuTween;
	spTween      _mainStateEffectsTween;
	spInputField _currentTF;
	spInputText  _input;

	int _nextState;

	void _initSettings(const std::string& playerName1, const std::string &playerName2, int* pKey1, int* pKey2);
	void _initMenu();
	void onClickTF(Event* ev);
	void onEvent(Event* ev);
	void onComplete(Event* ev);
	void onTweenDone(Event* ev);
	void onSettingsAction(Event* ev);
	void _initEngineEffects();
	void _initFireBottomEffects();
	void _initSmokeBottomEffects();
	void _initSparksTopEffects();
public:
	static const int MAIN_MENU     = 0;
	static const int SETTINGS_MENU = 1;

	MenuState();
	static spMenuState instance;
	Tween::EASE _ease;
	spActor _easeGraph;
};