#include "Guns.h"
#include "InputManager.h"

USING_NS_CC;

GunsHandler::GunsHandler()
{
	Gun pistol;
	Gun shotgun;
	Gun submachineGun;

	pistol.automatic = true;
	pistol.maxAmmo = 12;
	pistol.currentAmmo;
	pistol.damage = 20;
	pistol.fireRate = 0.2f;
	pistol.nextTimeToFire = 0.0f;
	pistol.reloadTime = 2.0f;

	currentGun = pistol;
	_counter = 0.0f;
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

	if (currentGun.currentAmmo < 0)
	{
		return;
	}

	if (currentGun.automatic)
	{
		if (GET_KEY(EventMouse::MouseButton::BUTTON_LEFT) && _counter >= currentGun.nextTimeToFire)
		{
			currentGun.nextTimeToFire = _counter + 1.0f / currentGun.fireRate;
			log("Shoot");
		}
	}
	else
	{
		if (GET_KEY_DOWN(EventMouse::MouseButton::BUTTON_LEFT) && _counter >= currentGun.nextTimeToFire)
		{
			currentGun.nextTimeToFire = _counter + 1.0f / currentGun.fireRate;
			log("Shoot");
		}
	}
}

void GunsHandler::Reload(void)
{
	currentGun.isReloading = true;
	log("Reloading...");

	auto tmpCounter = 0;
	while (tmpCounter < currentGun.reloadTime * 60.0f)
	{
		tmpCounter++;
	}

	currentGun.currentAmmo = currentGun.maxAmmo;
	currentGun.isReloading = false;
	log("Reload Complete...");
}