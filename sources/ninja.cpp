#include "ninja.hpp"
#include <iostream>

void Ninja::move(Character* enemy)
{
    Point* location = getPtrLocation();
    *location = Point::moveTowards(*location, enemy->getLocation(), speed);
}  

void Ninja::slash(Character* enemy)
{
    if(enemy == this){
        throw runtime_error("Character cant attack himself");
    }

    double dist = distance(enemy);
    if(isAlive()){
        if(dist < 1){
            enemy->hit(40);
        }else{
            move(enemy);
        }
    }
}

void Ninja::attack(Character* enemy)
{
    slash(enemy);
}
