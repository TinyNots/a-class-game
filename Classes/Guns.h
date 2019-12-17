#pragma once
#include "cocos2d.h"

struct Gun
{
	bool automatic = false;
	float damage = 0.0f;
	float range = 0.0f;
	float fireRate = 0.0f;

	int maxAmmo = 0;
	int currentAmmo = 0;
	float reloadTime = 0.0f;
	bool isReloading = false;
	float nextTimeToFire = 0.0f;
};

class GunsHandler : public cocos2d::Node
{
public:
	GunsHandler();
	~GunsHandler();
	void Update(float dt);
private:
	void Reload(void);
	Gun currentGun;
	float _counter;
	float _reloadCounter;
	float SecToFrame(float second);
};