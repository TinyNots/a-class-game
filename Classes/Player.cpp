#include "Player.h"
#include "InputManager.h"

#define GetKey(keyCode)		InputManager::getInstance().Getkey(keyCode)
#define GetKeyUp(keyCode)	InputManager::getInstance().GetkeyUp(keyCode)
#define GetKeyDown(keyCode) InputManager::getInstance().GetkeyDown(keyCode)

USING_NS_CC;

Player * Player::createPlayer()
{
	return Player::create();
}

Player::Player()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	this->setPosition(visibleSize.width / 2.0f, visibleSize.height / 2.0f);

	auto circle = DrawNode::create();
	circle->drawCircle(Vec2(0,0), 10.0f, 360.0f, 20, false, Color4F::RED);
	this->addChild(circle);
	this->scheduleUpdate();
}

Player::~Player()
{
}

void Player::update(float dt)
{
	if (GetKey(EventKeyboard::KeyCode::KEY_D))
	{
		this->setPositionX(this->getPositionX() + 2.0f);
	}

	if (GetKey(EventKeyboard::KeyCode::KEY_A))
	{
		this->setPositionX(this->getPositionX() - 2.0f);
	}

	if (GetKey(EventKeyboard::KeyCode::KEY_W))
	{
		this->setPositionY(this->getPositionY() + 2.0f);
	}

	if (GetKey(EventKeyboard::KeyCode::KEY_S))
	{
		this->setPositionY(this->getPositionY() - 2.0f);
	}
}
