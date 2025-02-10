#pragma once
#include "Gun.h"

class States
{
protected:
	Gun* mGun;
public:
	States(Gun* gun);

	virtual void Start() = 0;

	virtual void Update(float deltaTime) = 0;
};

