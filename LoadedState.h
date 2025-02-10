#pragma once
#include "States.h"
class LoadedState :public States
{
protected:

public:
	LoadedState(Gun* gun);

	virtual void Start();

	virtual void Update(float deltaTime);
};

