#include "Guns.h"
#include "InputManager.h"
#include "Bullet.h"

USING_NS_CC;

GunsHandler::GunsHandler()
{
	Gun pistol;
	Gun shotgun;
	Gun submachineGun;

	pistol.automatic = true;
	pistol.maxAmmo = 30;
	pistol.currentAmmo = pistol.maxAmmo;
	pistol.damage = 20;
	pistol.fireRate = 15.0f;
	pistol.nextTimeToFire = 0.0f;
	pistol.reloadTime = 2.0f;

	currentGun = pistol;
	_counter = 0.0f;
	_reloadCounter = 0.0f;
}

GunsHandler::~GunsHandler()
{
}

void GunsHandler::Update(float dt)
{
	_counter += 1.0f;

	if (currentGun.isReloading)
	{
		Reload();
		return;
	}

	if (currentGun.currentAmmo <= 0)
	{
		currentGun.isReloading = true;
		log("Reloading...");
		return;
	}

	bool inputCheck = GET_KEY(EventMouse::MouseButton::BUTTON_LEFT);

	if (!currentGun.automatic)
	{
		inputCheck = GET_KEY_DOWN(EventMouse::MouseButton::BUTTON_LEFT);
	}

	if (inputCheck && _counter >= currentGun.nextTimeToFire)
	{
		for (int i = 0; i < 10; i++)
		{
			Bullet::createBullet();
		}

		currentGun.nextTimeToFire = _counter + SecToFrame(1.0f) / currentGun.fireRate;
		log("Shoot %d", currentGun.currentAmmo);
		currentGun.currentAmmo--;
	}
}

void GunsHandler::Reload(void)
{
	if (_reloadCounter < SecToFrame(currentGun.reloadTime - 1.0f))
	{
		_reloadCounter++;
	}
	else
	{
		_reloadCounter = 0;
		currentGun.isReloading = false;
		currentGun.currentAmmo = currentGun.maxAmmo;
		log("Reload Complete...");
	}
}

float GunsHandler::SecToFrame(float second)
{
	return second * 60.0f;
}
