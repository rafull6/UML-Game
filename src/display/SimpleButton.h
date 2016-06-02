#include "oxygine-framework.h"
#include "../resource/GameResource.h"

using namespace oxygine;

DECLARE_SMART(SimpleButton, spSimpleButton);
class SimpleButton : public Button{
protected:
	spTextField _textField;
	
	void _init(const char* textureName);
	void onEvent(Event* ev);

public:
	static const int BUTTON_LEFT   = 0;
	static const int BUTTON_CENTER = 1;
	static const int BUTTON_RIGHT  = 2;

	SimpleButton();
	SimpleButton(const char* textureName);

	void changeColor(const Color &c);
	void setText(const char* text);
	void setText(const char* text, const int &position);
	std::string getText() const;
};