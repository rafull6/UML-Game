#pragma once
#include "oxygine-framework.h"
using namespace oxygine;
using namespace std;

DECLARE_SMART(GameButton, spGameButton);
class GameButton: public Sprite
{
public:
    GameButton();

    void setText(const string& txt);

private:
    void onEvent(Event*);

    spTextField _text;
};