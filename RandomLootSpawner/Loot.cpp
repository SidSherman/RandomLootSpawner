#include "Loot.h"

Loot::Loot(LootRarity rarity, int value, bool bCanRepeat)
{

    this->rarity = rarity;
    this->value = value;

    this->bCanRepeat = bCanRepeat;
}

Loot::Loot()
{
}


bool Loot::GetCanRepeat()
{
    return bCanRepeat;
}

int Loot::GetValue()
{
    return value;
}
LootRarity Loot::GetRarity()
{
    return rarity;
}