#pragma once
#include <vector>

class States;

class Gun
{
public:
	enum State
	{
		//si max de ball
		Full,
		//si as des balls
		Loaded,
		//si vide de ball
		Empty,
		//si en tire
		Shooting,
		//si en rechargement
		Reloading,

		Count
	};
	static constexpr int StateCount = static_cast <int>(State::Count);

protected:
	int mAmmo;
	int mCapacity;

	std::vector<States*> mAllState;
	/*const char** mAllState;*/

	State mState = State::Full;

	int mTransition[StateCount][StateCount] =
	{
	//	Full,	Loaded,	Empty,	Shooting,	Reloading
		{	0,		0,		0,		1,		0 },//Full
		{	0,		0,		0,		1,		1 },//Loaded
		{	0,		0,		0,		0,		1 },//Empty
		{	0,		1,		1,		0,		0 },//Shooting
		{	1,		0,		0,		0,		0 }//Reloading
	};

public:
	Gun();

	void Init(int capacity, int reloadTime, int shootTime);

	void Update(float deltaTime);

	bool TransitionTo(State newState);

	void Shoot();

	void Reload();

	void SetAmmo(int ammo);

	void SetMaxAmmo();

	void AmmoLessLess();

	int GetAmmo();

	template<typename T>
	T* GetState();

	~Gun();
};

template<typename T>
inline T* Gun::GetState()
{
	for (int i = 0; i < mAllState.size(); ++i)
	{
		if (T* state = dynamic_cast<T*>(mAllState[i]))
		{
			return state;
		}
	}
	return nullptr;
}

