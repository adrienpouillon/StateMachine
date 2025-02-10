#pragma once
#include "States.h"
class FullState :public States
{
protected:

public:
	FullState(Gun* gun);

	virtual void Start();

	virtual void Update(float deltaTime);
};

