#include "Enemy.h"
#include <cmath>

USING_NS_CC;

Enemy * Enemy::createEnemy(void)
{
	return Enemy::create();
}

Enemy::Enemy()
{
	_targetDirection = Vec2(0.0f, 0.0f);
	_player = Director::getInstance()->getRunningScene()->getChildByName("Player");

	this->setPosition(Vec2(0.0f, 360.f));

	_speed = 1.0f;
	auto distance = _player->getPosition() - this->getPosition();
	auto radian = atan2(distance.y, distance.x);
	_moveDirection.x = _speed * cos(radian);
	_moveDirection.y = _speed * sin(radian);
	this->setRotation(CC_RADIANS_TO_DEGREES(-radian));

	auto sprite = DrawNode::create();
	sprite->drawCircle(Vec2(0.0f, 0.0f), 10.0f, 0.0f, 40, true, Color4F::GREEN);

	this->addChild(sprite);
	this->scheduleUpdate();
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt)
{
	this->setPosition(this->getPosition() + _moveDirection);

	auto distance = _player->getPosition() - this->getPosition();
	auto newDegree = atan2(distance.y, distance.x);
	//_targetDirection = Vec2(cos(newRadian), sin(newRadian));

	auto degree = this->getRotation();
	auto oldRadian = CC_DEGREES_TO_RADIANS(degree);

	if (degree < newDegree)
	{
		degree++;
	}

	if (degree > newDegree)
	{
		degree--;
	}

	auto newRadain = CC_DEGREES_TO_RADIANS(degree);
	_moveDirection = Vec2(cos(newRadain), sin(newRadain));
}
