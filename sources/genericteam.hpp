#pragma once

#include "character.hpp"
static constexpr int ARRSIZE = 10;

namespace ariel{
    class Genericteam
    {
        private:
            int count;
            Character** team = {};
            Character* leader;
        public:
            Genericteam() : count(0), team(new Character*[ARRSIZE]{0}), leader(nullptr){}
            Genericteam(Genericteam const &) = default;
            Genericteam(Genericteam &&) = default;
            Genericteam& operator=(Genericteam const &) = default;
            Genericteam& operator=(Genericteam &&) = default;
            virtual ~Genericteam() = default;
            void add(Character* cha);
            Character* getClosestCharacter(Character* leader);
            virtual void attack(Genericteam* team) = 0;
            virtual string print() = 0;

            int stillAlive();

            //getters
            Character** getTeam();
            Character* getLeader();
            int* getCount();
    };
}