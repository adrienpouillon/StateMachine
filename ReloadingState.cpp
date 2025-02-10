#include "ReloadingState.h"
#include "ShootingState.h"

ReloadingState::ReloadingState(float reloadTime, Gun* gun) : States(gun), mReloadTime(reloadTime)
{

}

void ReloadingState::Start()
{
	SetShootProgress(mReloadTime);
}

void ReloadingState::Update(float deltaTime)
{
	mReloadProgress -= deltaTime;
	if (mReloadProgress < 0.f)
	{
		mGun->TransitionTo(mGun->State::Full);
	}
}

void ReloadingState::SetShootProgress(float reloadProgress)
{
	mReloadProgress = reloadProgress;
}
