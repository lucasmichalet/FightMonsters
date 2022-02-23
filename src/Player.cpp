#include "Player.h"

Player::Player(const std::string& name)
    : Creature(name, '@', 10, 1, 0), m_level{1}
{

}

int Player::getLevel() const {return m_level;}
bool Player::hasWon() const { return (m_level >= 20); }


void Player::levelUp()
{
    ++m_level;
    ++m_damage;
    std::cout << "You are now level " << m_level << ".\n";
}

void Player::drinkPotion(const Potion& potion)
{
    std::cout <<  "You drank a "<< potion.getPotionSizeName() << " potion of " << potion.getPotionSizeName() << ".\n";
    switch( static_cast<int>(potion.getType()))
    {
    case static_cast<int>(Potion::PotionType::health) :
        m_health += potion.getPotionValue();
        break;
    case static_cast<int>(Potion::PotionType::strength) :
        m_damage += potion.getPotionValue();
        break;
    case static_cast<int>(Potion::PotionType::poison) :
        m_health += potion.getPotionValue();
        break;
    }
}



std::ostream& operator<< (std::ostream& out, const Player& p)
{
    out << "Welcome, " << p.getName() << '\n';
    out << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold \n\n";
    return out;
}

