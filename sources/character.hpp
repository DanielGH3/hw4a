#pragma once
#include "point.hpp"
#include <string>

using namespace std;

class Character
{
    private:
        int health;        
        string name;
        Point location;
        int type;
    public:
        Character();
        Character(Character const &) = default;
        Character(Character &&) = default;
        Character& operator=(Character const &) = default;
        Character& operator=(Character &&) = default;
        virtual ~Character() = default;
        Character(int health, string name, Point location, int type) : 
            health(health), name(std::move(name)), location(location), type(type) {}
        bool isAlive();
        double distance(Character* cha);
        void hit(int damage);
        virtual void attack(Character* enemy) = 0;
        string getName();
        Point getLocation();
        int getType();
        int getHealth();
        string print();
        
        //gettersetter 
        Point* getPtrLocation();
};