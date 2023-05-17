#include "Team2.hpp"
#include "cowboy.hpp"
#include "ninja.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace ariel;

Team2::Team2(Character *c)
{
    Character** team = getTeam();
    int* count = getCount();

    *count = 1;
    team[0] = c;
}

Team2::~Team2()
{
    Character** team = getTeam();
    int count = *getCount();

    for(int i = 0; i < count; i++){
        delete team[i];
    }
    
    delete team;
}

void Team2::attack(Genericteam* enemyteam)
{
    Character** team = getTeam();
    Character* leader = getLeader();
    int count = *getCount();

    //set new leader if none
    if(leader == nullptr){
        leader = team[0];
    }

    //set new leader on death
    if(!leader->isAlive()){
        int distance = 1000000;
        int tempdistance = 0;
        for (int i = 0; i < count; i++)
        {
            Character* newleader = team[i];
            tempdistance = leader->distance(newleader);
            if(tempdistance < distance && newleader->isAlive()){
                leader = newleader;
                distance = tempdistance;
            }
        }
    }

    if(leader == nullptr){
        throw runtime_error("Team is empty");
    }

    //find closest enemy
    Character* enemy = enemyteam->getClosestCharacter(leader);

    if(enemy == nullptr){
        return;
    }

    for (int i = 0; i < count; i++)
    {      
        if(!enemy->isAlive()){
            enemy = enemyteam->getClosestCharacter(leader);
            if(enemy == nullptr){
                return;
            }
        }
        team[i]->attack(enemy);
    }
}

string Team2::print()
{
    Character** team = getTeam();
    int count = *getCount();

    string ret = "";
    for (int i = 0; i < count; i++)
    {      
        ret += team[i]->print() + "\n";
    }
    return ret;
}
