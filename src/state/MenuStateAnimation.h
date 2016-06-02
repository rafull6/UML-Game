#include "ColorRectSprite.h"
#include "../resource/GameResource.h"
#include <typeinfo>

using namespace oxygine;
using namespace std;

class MenuStateAnimation
{
public:
	spSprite _sprite;
	Tween::EASE _ease;
	spActor _easeGraph;

   void _addTween(spTween tween)
    {
        tween->setEase(_ease);
        _sprite->addTween(tween);
        tween->addEventListener(TweenEvent::DONE, CLOSURE(this, &TweensTest::tweenDone));
    }


	void clicked(string id)
	{
		int dur = 2000;

		if (id == "TweenAnim")
		{
			//_addTween(createTween(TweenAnim(GameResource.getResAnim("anim")), dur / 4, 10));
		}

		if (id == "TweenRotation")
		{
			_addTween(createTween(Actor::TweenRotation(_sprite->getRotation() + (float)MATH_PI * 2), dur, 1));
		}

		if (id == "TweenRotationGlobalEase")
		{
			spTween tween = _sprite->addTween(
				Actor::TweenRotation(_sprite->getRotation() + (float)MATH_PI * 2),
				TweenOptions(500).loops(10).globalEase(_ease));
			tween->addEventListener(TweenEvent::DONE, CLOSURE(this, &TweensTest::tweenDone));
		}

		if (id == "TweenPosition")
		{
			_addTween(createTween(Actor::TweenPosition(_sprite->getPosition() + Vector2(0, -200)), dur, 1, true));
		}
		if (id == "TweenScale")
		{
			_addTween(createTween(Actor::TweenScale(2, 2), dur, 1, true));
		}
		if (id == "TweenColor")
		{
			_addTween(createTween(Sprite::TweenColor(Color(255, 0, 0, 255)), dur, 1, true));
		}
		if (id == "TweenAlpha")
		{
			_addTween(createTween(Actor::TweenAlpha(0), dur, 1, true));
		}
		if (id == "TweenDummy")
		{
			_addTween(createTween(TweenDummy(), dur, 1, true));
		}

		if (id == "TweenDelay")
		{
			_addTween(createTween(Actor::TweenRotation(_sprite->getRotation() + (float)MATH_PI * 2), dur, 2, false, 1000));
		}

		if (id == "TweenQueue")
		{
			spTweenQueue queue = new TweenQueue();
			queue->add(TweenAnim(resources.getResAnim("anim")), 500, 1);
			queue->add(Actor::TweenRotation(_sprite->getRotation() + (float)MATH_PI * 2.0f), 500, 1, false, 1000);
			queue->add(Actor::TweenScale(2), 500, 1, true);
			_addTween(queue);
		}

		if (id == "complete")
		{
			_sprite->removeTweens(true);
		}

	}

}
//
//class TweensTest : public Test
//{
//public:
//	spSprite _sprite;
//	Tween::EASE _ease;
//	spActor _easeGraph;