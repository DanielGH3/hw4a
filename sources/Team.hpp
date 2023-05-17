#pragma once
#include "character.hpp"
#include "cowboy.hpp"
#include "ninja.hpp"
#include "genericteam.hpp"
#include "Team2.hpp"
#include "SmartTeam.hpp"

namespace ariel
{
    class Team : public Genericteam
    {
        public:
            Team(){}
            Team(Character* cha);
            Team(Team const &) = default;
            Team(Team &&) = default;
            Team& operator=(Team const &) = default;
            Team& operator=(Team &&) = default;
            ~Team() override;
            void attack(Genericteam* team) override;
            string print() override;
    };     
}
