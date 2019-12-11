#pragma once
#include "cocos2d.h"
#include "InputManager.h"

class GameScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
private:
	CREATE_FUNC(GameScene);
	virtual bool init() override;
	void menuCloseCallback(cocos2d::Ref* pSender);
	InputManager* test;
};