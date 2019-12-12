#pragma once
#include "cocos2d.h"

class InputManager : public cocos2d::Node
{
public:
	static InputManager& getInstance(void);
	InputManager * GetPointer(void);
	void update(float dt) override;
	bool Getkey(cocos2d::EventKeyboard::KeyCode keyCode) const;
	bool GetkeyUp(cocos2d::EventKeyboard::KeyCode keyCode) const;
	bool GetKeyDown(cocos2d::EventKeyboard::KeyCode keyCode) const;
private:
protected:
	InputManager();
	~InputManager();
	bool _keyStates[256];
	bool _oldStates[256];
	static InputManager* _instance;
};