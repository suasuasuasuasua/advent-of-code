#pragma once

class LanternFish
{
public:
    int age;
    void dayPass();
    void resetAge();

    LanternFish(int age) : age(age) {}
    LanternFish spawnNew();
    void print();
};