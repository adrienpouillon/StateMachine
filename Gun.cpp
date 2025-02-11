#include "Gun.h"
#include <iostream>
#include "ShootingState.h"
#include "ReloadingState.h"
#include "EmptyState.h"
#include "LoadedState.h"
#include "FullState.h"

Gun::Gun()
{
}

void Gun::Init(int capacity, int reloadTime, int shootTime)
{
	/*mAllState[] =
	{
		new FullState,
		new LoadedState,
		new EmptyState,
		new ReloadingState,
		new ShootingState
	};*/
	mAllState.push_back(new FullState(this));
	mAllState.push_back(new LoadedState(this));
	mAllState.push_back(new EmptyState(this));
	mAllState.push_back(new ReloadingState(reloadTime, this));
	mAllState.push_back(new ShootingState(shootTime, this));

	mCapacity = capacity;
	mAmmo = capacity;
}

void Gun::Update(float deltaTime)
{
	switch (mState)
	{
	case State::Shooting:
		if (ShootingState* shooting = GetState<ShootingState>())
		{
			shooting->Update(deltaTime);
		}
		break;
	case State::Reloading:
		if (ReloadingState* reloading = GetState<ReloadingState>())
		{
			reloading->Update(deltaTime);
		}
		break;
	}
}

bool Gun::TransitionTo(State newState)
{
	int currenteStateIndex = static_cast<int>(mState);
	int newStateIndex = static_cast<int>(newState);

	if (mTransition[currenteStateIndex][newStateIndex] == 0)
	{
		return false;
	}
	
	mState = newState;

	return true;
}

void Gun::Shoot()
{
	//si peut recharger
	if (TransitionTo(State::Shooting))
	{
		//tirer
		if (ShootingState* shooting = GetState<ShootingState>())
		{
			shooting->Start();
		}
		AmmoLessLess();
		std::cout << "Bang !" << std::endl;
	}
	else
	{
		std::cout << "..." << std::endl;
	}
}

void Gun::Reload()
{
	//si peut tirer
	if (TransitionTo(State::Reloading))
	{
		//recharger
		if (ReloadingState* reloading = GetState<ReloadingState>())
		{
			reloading->Start();
		}
		SetMaxAmmo();
		std::cout << "recharge de munition" << std::endl;
	}
	else
	{
		std::cout << "..." << std::endl;
	}
}

void Gun::SetAmmo(int ammo)
{
	mAmmo = ammo;
}

void Gun::SetMaxAmmo()
{
	SetAmmo(mCapacity);
}

void Gun::AmmoLessLess()
{
	SetAmmo(mAmmo - 1);
}

int Gun::GetAmmo()
{
	return mAmmo;
}
