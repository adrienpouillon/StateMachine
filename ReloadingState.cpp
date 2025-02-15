#include "ReloadingState.h"
#include "ShootingState.h"

ReloadingState::ReloadingState(float reloadTime, Gun* gun) : States(gun), mReloadTime(reloadTime), mReloadProgress(reloadTime)
{

}

void ReloadingState::Start()
{
	SetReloadProgress(mReloadTime);
}

void ReloadingState::Update(float deltaTime)
{
	mReloadProgress -= deltaTime;
	if (mReloadProgress < 0.f)
	{
		mGun->TransitionTo(mGun->State::Full);
	}
}

void ReloadingState::SetReloadProgress(float reloadProgress)
{
	mReloadProgress = reloadProgress;
}
