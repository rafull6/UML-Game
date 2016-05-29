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

	void _addTween(spTween tween)
	{
		tween->setEase(_ease);
		_sprite->addTween(tween);
	}
	int dur = 2000;
	//_addTween(createTween(Actor::TweenRotation(_sprite->getRotation() + (float)MATH_PI * 2), dur, 1));

private:
	void onEvent(Event* ev);


};