#include "SmartTeam.hpp"
#include "cowboy.hpp"
#include "ninja.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace ariel;

Character* findCowboyToFocus(Character** eteam){
    Character* focusedCowboy = nullptr;
    for (int i = 0; eteam[i] != nullptr && i < 10; i++)
    {
        if(eteam[i]->getType() == NINJA) continue;
        if(eteam[i]->isAlive() && ((focusedCowboy == nullptr) || (eteam[i]->getHealth() < focusedCowboy->getHealth()))){
            focusedCowboy = eteam[i];
        }
    }
    return focusedCowboy;
}

SmartTeam::SmartTeam(Character *c)
{
    Character** team = getTeam();
    int* count = getCount();
    *count = 1;
    team[0] = c;
}

SmartTeam::~SmartTeam()
{   
    Character** team = getTeam();
    int count = *getCount();
    
    for(int i = 0; i < count; i++){
        delete team[i];
    }
    
    delete team;
}

void SmartTeam::attack(Genericteam* enemyteam)
{
    Character** team = getTeam();
    int count = *getCount();

    if(team[0] == nullptr){
        throw runtime_error("Team is empty");
    }

    //LOGIC : 
    //forach chara:
    //if the enemy is a ninja and the chara is a cowboy:
    //  - the ninja doesnt show any immidiate threat : ignore it and shoot the same cowboy as the others
    //  - the ninja is close enough to be a threat : take its hp down to 40*[number of ninjas in the team] hp and trust the ninjas to finish them
    //ninjas:
    //  - run to the closest target

    //check if enemy team empty
    Character* enemy = enemyteam->getClosestCharacter(team[0]);
    if(enemy == nullptr){
        return;
    }

    Character** eteam = enemyteam->getTeam();

    //find a cowboy to focus
    Character* focusedCowboy = findCowboyToFocus(eteam);

    int ninjacount = 0;
    for(int i = 0; i < count; i++){
        if(team[i]->getType() == NINJA){
            ninjacount++;
        }
    }

    for (int i = 0; i < count; i++)
    {      
        Character* cha = team[i];
        switch (cha->getType())
        {
            case NINJA:
            enemy = enemyteam->getClosestCharacter(cha);
            if(enemy == nullptr) return;
            
            cha->attack(enemy);
                break;

            case COWBOY:
            enemy = enemyteam->getClosestCharacter(cha);
            if(enemy == nullptr) return;

            if(focusedCowboy == nullptr){
                cha->attack(enemy);
            }else if(enemy->getType() == NINJA && cha->distance(enemy) < 150 && enemy->getHealth() >= (ninjacount - 1) * 40){
                cha->attack(enemy);
            }else{
                cha->attack(focusedCowboy);
            }
                break;

            default:
                throw runtime_error("Unknown character type");
                break;
        }

        if(focusedCowboy != nullptr && !focusedCowboy->isAlive()){
            focusedCowboy = findCowboyToFocus(eteam);
        }
    }
}

string SmartTeam::print()
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
