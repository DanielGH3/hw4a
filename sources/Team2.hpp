#pragma once
#include "character.hpp"
#include "cowboy.hpp"
#include "ninja.hpp"
#include "genericteam.hpp"

namespace ariel
{
    class Team2 : public Genericteam
    {
        public:
            Team2(){}
            Team2(Character* cha);
            Team2(Team2 const &) = default;
            Team2(Team2 &&) = default;
            Team2& operator=(Team2 const &) = default;
            Team2& operator=(Team2 &&) = default;
            ~Team2() override;
            void attack(Genericteam* team) override;
            string print() override;
    };     
}
