#pragma once

enum class LootRarity { Usual = 0, Rare = 1, Legendary = 2, ENUM_COUNT = 3 };

class Loot
{

private:

    LootRarity rarity;
    int value;

    bool bCanRepeat;

public:
    Loot(LootRarity rarity, int value, bool bCanRepeat);
  
    Loot();

    bool GetCanRepeat();

    int GetValue();

    LootRarity GetRarity();

};

