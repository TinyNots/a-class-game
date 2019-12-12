#pragma once
#include "cocos2d.h"

class Player : public cocos2d::Sprite
{
public:
	static Player* createPlayer();
	Player();
	~Player();
private:
	CREATE_FUNC(Player);
	void update(float dt);
};

