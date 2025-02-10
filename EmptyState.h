#pragma once
#include "States.h"
class EmptyState :public States
{
protected:

public:
	EmptyState(Gun* gun);

	virtual void Start();

	virtual void Update(float deltaTime);
};

