#include "InputField.h"

InputField::InputField() {
	_init("");
};

InputField::InputField(const std::string& startText) {
	_init(startText);
};

void InputField::_init(const std::string& startText) {
	TextStyle style;

	_text = new TextField();
	_text->setTouchEnabled(false);

	style.color     = Color(0, 255, 156, 0);
	style.vAlign    = TextStyle::VALIGN_TOP;
	style.hAlign    = TextStyle::HALIGN_LEFT;
	style.multiline = false;
	style.font      = GameResource::ui.getResFont("normal")->getFont();
	style.fontSize2Scale = 16;

	_text->setStyle(style);
	_text->setText(startText);
	_text->attachTo(this);

	this->setResAnim(GameResource::ui.getResAnim("auth_n"));
}

void InputField::changeSize(const Vector2 &size) const {
	_text->setSize(size);
}

spTextField InputField::getText() const {
	return _text;
}