#pragma once
#include <vector>
#include "Loot.h"

using namespace std;


class LootList
{
private:
    LootRarity rarity;

    int frequency = 0;
    int minRoll = 0;
    int maxRoll = 0;

    int currentRoll;

    vector<Loot> lootList;

public:

    LootList(vector<Loot> lootList, LootRarity rarity, int frequency, int currentRoll = 0);

    LootList();

    int GetFrequency();

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
   
    void SetCurrentRoll(int value);

};

// Comparator to sort Loot list by rarity
bool CompLootByRarity(LootList first, LootList second);