#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>

class Creature
{
    protected:
        std::string m_name{};
        char m_symbol{};
        int m_health{};
        int m_damage{};
        int m_gold{};

    public:
        Creature(const std::string& name, char symbol, int health, int damage, int gold);   // ou std::strng_view

        // getters
        const std::string& getName() const;
        char getSymbol() const;
        int getHealth() const;
        int getDamage() const;
        int getGold() const;

        // methods
        void addGold(int gold);
        void reduceHealth(int health);
        bool isDead() const;
};

#endif // CREATURE_H
