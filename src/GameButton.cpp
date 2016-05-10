#include "GameButton.h"
#include "resources.h"

GameButton::GameButton()
{
    //pressed button should be RED
    addEventListener(TouchEvent::TOUCH_DOWN, CLOSURE(this, &GameButton::onEvent));
    addEventListener(TouchEvent::TOUCH_UP, CLOSURE(this, &GameButton::onEvent));
    addEventListener(TouchEvent::CLICK, CLOSURE(this, &GameButton::onEvent));
}

void GameButton::onEvent(Event* ev)
{
    TouchEvent* event = static_cast<TouchEvent*>(ev);
    if (ev->type == TouchEvent::TOUCH_DOWN)
        setColor(Color::Red);

    if (ev->type == TouchEvent::TOUCH_UP)
        setColor(Color::White);

    if (ev->type == TouchEvent::CLICK)
    {
        //clicked button should scale up and down
        setScale(1.0f);
        addTween(Actor::TweenScale(1.1f), 300, 1, true);
    }
}

void GameButton::setText(const string& txt)
{
    if (!_text)
    {
        //create TextField if it wasn't created yet
        TextStyle style;
        style.font = resources::ui.getResFont("normal")->getFont();
        style.vAlign = TextStyle::VALIGN_MIDDLE;
        style.hAlign = TextStyle::HALIGN_CENTER;

        //attach it to MyButton and set the same size as button
        //text would be centered
        _text = initActor(new TextField,
                          arg_style = style,
                          arg_size = getSize(),
                          arg_attachTo = this);
    }

    _text->setText(txt);
}