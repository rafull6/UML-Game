#include "Obstacle.h"
#include "resources.h"

void Obstacle::_init()
{
    //you could hit obstacle 3 times
    _hp = 3;

    spSprite sprite = new Sprite;
    sprite->setResAnim(resources::ui.getResAnim("shield"));
    sprite->attachTo(_view);
    sprite->setAnchor(Vector2(0.5f, 0.5f));

    //it random scale and rotation
    sprite->setRotation(scalar::randFloat(0, MATH_PI * 2));
    sprite->setScale(scalar::randFloat(0.15f, 0.22f));

    //it is rotating by tween with random speed
    float dest = MATH_PI * 2;
    if (rand() % 2 == 0)
        dest *= -1;
    dest += sprite->getRotation();
    sprite->addTween(Sprite::TweenRotation(dest), rand() % 12000 + 10000, -1);
}

void Obstacle::_update(const UpdateState& us)
{
    //nothing to do
}

void Obstacle::explode()
{
    //hit by rocket
    _hp--;
    if (_hp == 0)
    {
        //dead, hide it with alpha tween
        _dead = true;
        _view->addTween(Actor::TweenAlpha(0), 300)->setDetachActor(true);
    }
}