#pragma once
#include "cocos2d.h"

class Bullet : public cocos2d::Node
{
public:
	static Bullet* createBullet(void);
	Bullet();
	~Bullet();
private:
	static Bullet* create()
	{
		Bullet *pRet = new(std::nothrow) Bullet();
		if (pRet && pRet->init())
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			delete pRet;
			pRet = nullptr;
			return nullptr;
		}
	};
	void update(float dt);
	cocos2d::Vec2 _moveDirection;
	float _speed;
	cocos2d::MotionStreak* _trail;
};