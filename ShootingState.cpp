#include "ShootingState.h"

ShootingState::ShootingState(float shootTime, Gun* gun) : States(gun), mShootTime(shootTime), mShootProgress(shootTime)
{

}

void ShootingState::Start()
{
	SetShootProgress(mShootTime);
}

void ShootingState::Update(float deltaTime)
{
	mShootProgress -= deltaTime;
	if (mShootProgress < 0.f)
	{
		if (mGun->GetAmmo() <= 0)
		{
			mGun->TransitionTo(mGun->State::Empty);
		}
		else
		{
			mGun->TransitionTo(mGun->State::Loaded);
		}
	}
}

void ShootingState::SetShootProgress(float shootProgress)
{
	mShootProgress = shootProgress;
}
