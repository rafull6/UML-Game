#include "State.h"
#include "../resource/GameResource.h"

DECLARE_SMART(MenuState, spMenuState);

class MenuState : public State{
public:
	spSprite _sprite;
	Tween::EASE _ease;
	spActor _easeGraph;

	static spMenuState instance;
	MenuState();

private:
	void onEvent(Event* ev);


};