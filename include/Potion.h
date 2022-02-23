#ifndef POTION_H
#define POTION_H

#include <iostream>
#include <string>
#include <array>

class Potion
{
   public:
        enum PotionType{
            health,
            strength,
            poison,

            max_types
        };

        enum PotionSize{
            small,
            medium,
            large,

            max_sizes
        };

    private:

        PotionType m_type{};
        PotionSize m_size{};


    public:

        Potion(PotionType type, PotionSize potionSize);

        PotionType getType() const;
        PotionSize getSize() const;

        const std::string& getPotionTypeName() const;
        const std::string& getPotionSizeName() const;
        int getPotionValue()  const;

        static int getRandomNumber(int min, int max);

        static Potion getRandomPotion()
        {
            return {
                static_cast<PotionType>(getRandomNumber(1, PotionType::max_types)),
                static_cast<PotionSize>(getRandomNumber(1, PotionSize::max_sizes))
            };
        }
};

int Potion::getRandomNumber(int min, int max)
{
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) }; // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}





#endif // POTION_H
