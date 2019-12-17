#pragma once
#include "cocos2d.h"

class Enemy : public cocos2d::Sprite
{
public:
	static Enemy* createEnemy();
	Enemy();
	~Enemy();
private:
	CREATE_FUNC(Enemy);
	void update(float dt);
	cocos2d::Node* _player;
	cocos2d::Vec2 _moveDirection;
	cocos2d::Vec2 _targetDirection;
	float _speed;
};

