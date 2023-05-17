#include "genericteam.hpp"
#include <iostream>

using namespace ariel;

void Genericteam::add(Character *c)
{
    if(count == 10) return;

    for(size_t i = 0; i < count; i++){
        if(team[i] == c) throw runtime_error("Cant add same player twice");
    }

    team[(size_t)(count++)] = c;
}

Character* Genericteam::getClosestCharacter(Character* leader)
{
    Character* ret = nullptr;
    int maxdistance = 1000000;
    int tempdistance = 0;
    for (int i = 0; i < count; i++)
    {
        Character* temp = team[(size_t)i];
        tempdistance = temp->distance(leader);
        if(tempdistance < maxdistance && temp->isAlive()){
            ret = temp;
            maxdistance = tempdistance;
        }
    }
    return ret;
}

Character** ariel::Genericteam::getTeam()
{
    return team;
}

Character *ariel::Genericteam::getLeader()
{
    return leader;
}

int *ariel::Genericteam::getCount()
{
    return &count;
}

int Genericteam::stillAlive()
{
    int cnt = 0;
    for (int i = 0; i < count; i++)
    {
        if(team[(size_t)i]->isAlive()){
            cnt ++;
        }
    }
    return cnt;
}
