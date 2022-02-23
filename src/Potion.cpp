#include "Potion.h"


Potion::Potion(PotionType type, PotionSize potionSize)
    : m_type{type}, m_size{potionSize}
{
}

Potion::PotionType Potion::getType() const { return m_type; }
Potion::PotionSize Potion::getSize() const { return m_size; }

const std::string& Potion::getPotionTypeName() const
{
    switch( static_cast<int>(m_type) )
    {
        case static_cast<int>(Potion::PotionType::health) :
            return  "Health";
        case static_cast<int>(Potion::PotionType::strength) :
            return  "Strength";
        case static_cast<int>(Potion::PotionType::poison) :
            return  "Poison";
        default:
            return  "Error";
    }
}

const std::string& Potion::getPotionSizeName() const
{
    switch( static_cast<int>(m_size) )
        case static_cast<int>(Potion::PotionSize::small) :
            return "Small";
        case static_cast<int>(Potion::PotionSize::medium) :
            return "Medium";
        case static_cast<int>(Potion::PotionSize::large) :
            return "Large";
        default:
            return "Error";
    }
}

int Potion::getPotionValue() const
{
    static const std::array<int, static_cast<std::size_t>(PotionSize::max_sizes)> healthPotionData{+2, +2, +5};
    static const std::array<int, static_cast<std::size_t>(PotionSize::max_sizes)> strengthPotionData{+1, +1, +1};
    static const std::array<int, static_cast<std::size_t>(PotionSize::max_sizes)> poisonPotionData{-1, -1, -1};

    switch(m_type){
        case PotionType::health:
            return healthPotionData.at(PotionSize::small);
        case PotionType::strength:
            return strengthPotionData.at(PotionSize::middle);
        case PotionType::poison:
            return poisonPotionData.at(PotionSize::large);
        default:
            return "Error";
    }
}


