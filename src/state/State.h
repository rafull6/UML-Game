#pragma once
#include "oxygine-framework.h"

using namespace oxygine;

DECLARE_SMART(State, spState);

class State : public EventDispatcher {
protected:
	spActor _view;

	virtual void _show() {}
	virtual void _hidden() {}
	
	void onHidden(Event* event);

public:
	State();

	class HiddenEvent : public Event{
	public:
		//define unique int ID with makefourcc 'SHid' = SceneHidden
		enum { EVENT = makefourcc('S', 'H', 'i', 'd') };

		HiddenEvent(State* state_) : Event(EVENT), state(state_) {};
		State* state;
	};

	void show();
	void hide();
	void changeState(spState next);
	spActor getView() const { return this->_view; }
};