#pragma once

enum class LootRarity { Usual = 0, Rare = 1, ENUM_COUNT = 2 };

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

