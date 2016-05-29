#include "mButton.h"

mButton::mButton()
{
	addEventListener(TouchEvent::TOUCH_DOWN, CLOSURE(this, &mButton::onEvent));
	addEventListener(TouchEvent::TOUCH_UP, CLOSURE(this, &mButton::onEvent));
}

void mButton::onEvent(Event* ev)
{
	TouchEvent* event = static_cast<TouchEvent*>(ev);
	if (ev->type == TouchEvent::TOUCH_DOWN)
		setColor(Color::DarkCyan);

	if (ev->type == TouchEvent::TOUCH_UP)
		setColor(Color::White);
}