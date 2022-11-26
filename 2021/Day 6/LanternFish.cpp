#include "LanternFish.h"
#include <iostream>

using namespace std;

void LanternFish::dayPass()
{
    age--;
}

void LanternFish::resetAge()
{
    this->age = 6;
}

LanternFish LanternFish::spawnNew()
{
    return LanternFish(8);
}

void LanternFish::print()
{
    cout << this->age << " ";
}