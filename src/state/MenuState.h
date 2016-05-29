#include "State.h"

DECLARE_SMART(MenuState, spMenuState);

class MenuState : public State{
public:
	static spMenuState instance;
	MenuState();

private:
	void onEvent(Event* ev);
};