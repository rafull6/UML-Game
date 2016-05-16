#include "State.h"

State::State() {
	this->_view = new Actor();
	this->_view->setSize(getStage()->getSize());
}

void State::changeState(spState next) {
	// hide current state
	hide();

	// show next state
	next->show();
}

void State::show(){
	//add scene view to root
	getStage()->addChild(_view);
	
	//and fade in
	this->_view->setAlpha(0);
	this->_view->addTween(Actor::TweenAlpha(255), 300);

	//call virtual method (overloaded in inherited classes)
	_show();
}

void State::hide(){
	spTween tween = _view->addTween(Actor::TweenAlpha(0), 300);
	
	//detach when done
	tween->setDetachActor(true);
	
	//and call Scene::hidden
	tween->addDoneCallback(CLOSURE(this, &State::onHidden));
}

void State::onHidden(Event* event) {
	HiddenEvent he(this);
	dispatchEvent(&he);
}