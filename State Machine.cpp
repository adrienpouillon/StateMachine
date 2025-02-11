#include <iostream>
#include <chrono>
#include <conio.h>
#include "Gun.h"


bool Action(Gun* gun)
{
    std::cout << "appuyer sur 'T' pour tirer ou sur 'R' pour recharger" << std::endl;
    char chara = _getch();
    switch (chara)
    {
    case 't':
        gun->Shoot();
        break;
    case 'r':
        gun->Reload();
        break;
    case 'q':
        return true;
        break;
    }
    return false;
}

int main()
{
    float dt = 0;

    Gun* gun = new Gun();
    gun->Init(3, 5, 3);

    bool endGame = false;

    while (!endGame)
    {
        auto start = std::chrono::high_resolution_clock::now();

        gun->Update(dt);
        //std::cout << dt << std::endl;
        endGame = Action(gun);

        

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        dt = duration.count();
    }
    std::cout << "Hello World!\n";
}