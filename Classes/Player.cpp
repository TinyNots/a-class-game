#include "Player.h"
#include "InputManager.h"
#include <math.h>

USING_NS_CC;

Player * Player::createPlayer()
{
	return Player::create();
}

Player::Player()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	this->setPosition(visibleSize.width / 2.0f, visibleSize.height / 2.0f);

	// player image
	auto circle = DrawNode::create();
	circle->drawCircle(Vec2::ZERO, 20.0f, 360.0f, 40, false, Color4F::RED);
	circle->drawLine(Vec2(20.0f, 0.0f), Vec2(35.0f, 0.0f), Color4F::RED);

	this->addChild(circle);
	this->scheduleUpdate();
}

Player::~Player()
{
}

void Player::update(float dt)
{
	if (GET_KEY(EventKeyboard::KeyCode::KEY_D))
	{
		this->setPositionX(this->getPositionX() + 2.0f);
	}

	if (GET_KEY(EventKeyboard::KeyCode::KEY_A))
	{
		this->setPositionX(this->getPositionX() - 2.0f);
	}

	if (GET_KEY(EventKeyboard::KeyCode::KEY_W))
	{
		this->setPositionY(this->getPositionY() + 2.0f);
	}

	if (GET_KEY(EventKeyboard::KeyCode::KEY_S))
	{
		this->setPositionY(this->getPositionY() - 2.0f);
	}

	Rotation();
}

void Player::Rotation(void)
{
	auto distance = GET_CURSOR_POS() - this->getPosition();
	auto radian = atan2(distance.y, distance.x);
	auto degree = CC_RADIANS_TO_DEGREES(-radian);

	this->setRotation(degree);
}
