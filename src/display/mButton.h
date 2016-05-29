#include "Sprite.h"
using namespace oxygine;

DECLARE_SMART(MyButton, spMyButton);
class mButton : public Sprite
{
public:
	mButton();

private:
	void onEvent(Event*);
};