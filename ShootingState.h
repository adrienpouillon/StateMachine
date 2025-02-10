#pragma once
#include "States.h"
class ShootingState :public States
{
protected:
	float mShootProgress;
	float mShootTime;
public:
	ShootingState(float shootTime, Gun* gun);

	virtual void Start();

	virtual void Update(float deltaTime);

	void SetShootProgress(float shootProgress);

};

