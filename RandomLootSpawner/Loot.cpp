#include "Loot.h"

Loot::Loot(LootRarity rarity, int value, bool bCanRepeat)
{

    this->rarity = rarity;
    this->value = value;

    this->bCanRepeat = bCanRepeat;
}

Loot::Loot()
{
    this->rarity = LootRarity::Usual;
    this->value = -1;

    this->bCanRepeat = true;
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