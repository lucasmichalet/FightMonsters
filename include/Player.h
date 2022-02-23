#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Creature.h"
#include "Monster.h"
#include "Potion.h"

class Player : public Creature
{
    private:
        int m_level{};

    public:
        Player(const std::string& name);

        int getLevel() const;
        bool hasWon() const;

        void drinkPotion(const Potion& potion);
        void levelUp();
};

std::ostream& operator<< (std::ostream& out, const Player& p);

#endif // PLAYER_H
