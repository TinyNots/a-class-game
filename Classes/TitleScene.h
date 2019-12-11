#pragma once
#include "cocos2d.h"

class TitleScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
private:
	CREATE_FUNC(TitleScene);
	virtual bool init() override;
	void menuCloseCallback(cocos2d::Ref* pSender);
};