#pragma once
#include "oxygine-framework.h"
#include "../resource/GameResource.h"
#include <string>

using namespace oxygine;

DECLARE_SMART(InputField, spInputField);

class InputField : public Sprite {
private:
	spTextField _text;
	void _init(const std::string& text);
public:
	InputField();
	InputField(const std::string &startText);
	void changeSize(const Vector2& size) const;
	spTextField getText() const;
};