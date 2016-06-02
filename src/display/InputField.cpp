#include "InputField.h"

InputField::InputField() {
	_init("", true);
};

InputField::InputField(const std::string& startText, const bool& longField) {
	_init(startText, longField);
};

InputField::InputField(const int &keyCode, const bool &longField) {
	const char* keyName = SDL_GetScancodeName((SDL_Scancode)keyCode);
	_init(keyName, longField);
}

void InputField::_init(const std::string& startText, const bool& longField) {
	TextStyle style;

	// save initial text
	_startText = startText;

	_textField = new TextField();
	_textField->setTouchEnabled(false);

	// get system font
	const Font* systemFont = _textField->getFont();

	// set font style
	style.color     = Color(0, 255, 156);
	style.vAlign    = TextStyle::VALIGN_TOP;
	style.hAlign    = TextStyle::HALIGN_LEFT;
	style.multiline = false;
<<<<<<< HEAD
	style.font      = GameResource::ui.getResFont("normal")->getFont();
	style.fontSize2Scale = 14;
=======
	style.font      = systemFont;
	style.fontSize2Scale = 14;

	_textField->setPosition(15, 5);
	_textField->setStyle(style);
	_textField->setText(startText);
	_textField->attachTo(this);

	if (longField == true) {
		this->setResAnim(GameResource::ui.getResAnim("input_long"));
	}else{
		this->setResAnim(GameResource::ui.getResAnim("input_short"));
	}
}

void InputField::addLabel(const std::string &text) {
	this->addLabel(text, 12);
}
>>>>>>> bccb87eb560fc4ca989f5f48b1c5129e3f0fda55

void InputField::addLabel(const std::string &text, const int &size) {
	_labelField = new TextField();

	_labelField->setText(text);
	_labelField->setName("label");
	_labelField->setFontSize2Scale(size);
	_labelField->setPosition(15, -17);
	_labelField->attachTo(this);
	
	_isLabel = true;
}

bool InputField::removeLabel() {
	if (_isLabel) {
		this->removeChild(_labelField);
		return true;
	}

	_isLabel = false;
	return false;
}

void InputField::moveLabel(const Vector2 &position) {
	_labelField->setPosition(position);
}

void InputField::updateTextField() {
	if (_textField->getText() == "") {
		_textField->setText(_startText);
	}else{
		_startText = _textField->getText();
	}
}

<<<<<<< HEAD
	this->setResAnim(GameResource::ui.getResAnim("input_long"));
=======
void InputField::changeSize(const Vector2 &size) {
	_textField->setSize(size);
>>>>>>> bccb87eb560fc4ca989f5f48b1c5129e3f0fda55
}

spTextField InputField::getTextField() const {
	return _textField;
}

std::string InputField::getText() const {
	return this->_text;
}