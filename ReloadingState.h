#pragma once
#include "States.h"
class ReloadingState :public States
{
protected:
	float mReloadProgress;
	float mReloadTime;
public:
	ReloadingState(float reloadTime, Gun* gun);

	virtual void Start();

	virtual void Update(float deltaTime);

	void SetReloadProgress(float reloadingProgress);

};

