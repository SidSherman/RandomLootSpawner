#pragma once
#include <vector>
#include "Loot.h"

using namespace std;


class LootList
{
private:
    LootRarity rarity;


    int minRoll = 0;
    int maxRoll = 0;

    int currentRoll;

    vector<Loot> lootList;

public:

    LootList(vector<Loot> lootList, LootRarity rarity, int minRoll, int maxRoll, int currentRoll = 0);

    LootList();

    // return current roll after prev spawn
    int GetCurrentRoll();

    // return min roll after prev spawn
    int GetMinRoll();

    // return max roll after prev spawn
    int GetMaxRoll();

    void AddCurrentRoll();

    void ClearAddCurrentRoll();

    LootRarity GetRarity();

    vector<Loot> GetLootList();
   

};

// Comparator to sort Loot list by rarity
bool CompLootByRarity(LootList first, LootList second);