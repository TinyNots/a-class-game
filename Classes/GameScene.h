#pragma once
#include "cocos2d.h"

class GameScene : public cocos2d::Scene
{
public:
	static Scene* createScene();
private:
	CREATE_FUNC(GameScene);
	virtual bool init() override;
	void menuCloseCallback(cocos2d::Ref* pSender);
	virtual void update(float dt) override;
};