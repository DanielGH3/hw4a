#include "cowboy.hpp"
#include <iostream>
void Cowboy::shoot(Character* enemy)
{
    if(enemy == this){
        throw runtime_error("Character cant attack himself");
    }

    if(isAlive()){
        if(hasBullets()){
            enemy->hit(10);
            bullets --;
        }else{
            reload();
        }
    }
}

bool Cowboy::hasBullets()
{
    return bullets > 0;
}

void Cowboy::reload()
{
    bullets = 6;
}

void Cowboy::attack(Character* enemy)
{
    shoot(enemy);
}
