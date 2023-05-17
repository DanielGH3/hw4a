#pragma once
#include "character.hpp"
#include "cowboy.hpp"
#include "ninja.hpp"
#include "genericteam.hpp"

namespace ariel
{
    class SmartTeam : public Genericteam
    {
        public:
            SmartTeam(){}
            SmartTeam(Character* cha);
            SmartTeam(SmartTeam const &) = default;
            SmartTeam(SmartTeam &&) = default;
            SmartTeam& operator=(SmartTeam const &) = default;
            SmartTeam& operator=(SmartTeam &&) = default;
            ~SmartTeam() override;
            void attack(Genericteam* team) override;
            string print() override;
    };     
}
