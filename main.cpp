#include <iostream>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"

#include <cstdlib>
#include <ctime>
#include <cctype>

constexpr int maxLevel{20};


void attackPlayer(const Monster& m, Player& p)
{
    p.reduceHealth( m.getDamage());
    std::cout << "The " << m.getName() << " hit you for " << m.getDamage()<< " damage.\n\n";
}

void attackMonster(Player& p, Monster& m)
{
    m.reduceHealth(p.getDamage());
    std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";

    if(m.isDead())
    {
        std::cout << "You killed the " << m.getName() << ".\n";
        p.levelUp();
        std::cout << "You found " << m.getGold() << " gold.\n \n";
        p.addGold(m.getGold());
    }
}

void fightMonster(Player& p)
{
    Monster m{ Monster::getRandomMonster() };
	std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";
    char choice{};

    while (!m.isDead() && !p.isDead())
    {
        do
        {
            std::cout << "(R)un or (F)ight :";
            std::cin >> choice;
            choice = toupper(choice);
        }
        while( choice != 'R' && choice != 'F');

        if(choice == 'F')
        {
            attackMonster(p,m);
            if(!m.isDead())
            {
                attackPlayer(m,p);
            }
        }

        if(choice == 'R')
        {
            if(getRandomNumber(0,1) == 1)
            {
                std::cout << "You failed to flee.\n";
                attackPlayer(m,p);
                continue;
            }
            else
            {
                std::cout << "You successfully fled.\n \n";
                return;
            }
        }
    }
}

/////////////////////////////////////////////////////////
int main()
{
    // Randomness setup
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::rand();                                               // get rid of first result

	// Start
	std::cout << "Enter your name : ";
	std::string name{};
	std::cin >> name;
	Player p{name};
	std::cout << p;

	while( !p.isDead() && p.getLevel() < maxLevel)
    {
        fightMonster(p);
    }

    if( p.isDead() )
    {
        std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
        std::cout << "Too bad you can t take it with you!\n";
    }
    else
    {
        std::cout << "YOU WON !\n";
        std::cout << "You are now level " << p.getLevel() << " and you earned " << p.getGold() << " gold.\n";
    }


	return 0;
}
