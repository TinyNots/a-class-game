#include "Bullet.h"
#include "Player.h"
#include <math.h>

USING_NS_CC;

Bullet * Bullet::createBullet(void)
{
	return Bullet::create();
}

Bullet::Bullet()
{
	auto player = (Player*)Director::getInstance()->getRunningScene()->getChildByName("Player");

	_speed = 50.0f;
	auto radian = CC_DEGREES_TO_RADIANS(player->getRotation() + RandomHelper::random_real(-5.0f,5.0f));
	_moveDirection.x = _speed * cos(-radian);
	_moveDirection.y = _speed * sin(-radian);

	auto tmpSprite = DrawNode::create();
	tmpSprite->drawSolidCircle(Vec2::ZERO, 1.0f, 360.0f, 20, Color4F::WHITE);

	_trail = MotionStreak::create(0.3f, 1.0f, 2.0f, Color3B::WHITE, "HelloWorld.png");

	this->setPosition(player->getPosition());
	this->addChild(tmpSprite);
	this->scheduleUpdate();

	Director::getInstance()->getRunningScene()->addChild(this);
	Director::getInstance()->getRunningScene()->addChild(_trail);
}

Bullet::~Bullet()
{
}

void Bullet::update(float dt)
{
	this->setPosition(this->getPosition() + _moveDirection);
	_trail->setPosition(this->getPosition());

	auto pos = this->getPosition();
	auto visibleSize = Director::getInstance()->getVisibleSize();

	if (pos.x < 0.0f || pos.x > visibleSize.width ||
		pos.y < 0.0f || pos.y > visibleSize.height)
	{
		this->removeFromParent();
	}
}