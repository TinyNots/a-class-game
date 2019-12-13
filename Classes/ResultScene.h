#pragma once
#include "cocos2d.h"

class ResultScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
private:
	CREATE_FUNC(ResultScene);
	virtual bool init() override;
	void menuCloseCallback(cocos2d::Ref* pSender);
	virtual void update(float dt) override;
};