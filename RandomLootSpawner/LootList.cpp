#include "LootList.h"

LootList::LootList(vector<Loot> lootList, LootRarity rarity, int minRoll, int maxRoll, int currentRoll)
{
    this->rarity = rarity;
    this->minRoll = minRoll;
    this->maxRoll = maxRoll;
    this->currentRoll = currentRoll;
    this->lootList = lootList;
}


int LootList::GetCurrentRoll()
{
    return currentRoll;
}
int LootList::GetMinRoll()
{
    return minRoll;
}
int LootList::GetMaxRoll()
{
    return maxRoll;
}

void LootList::AddCurrentRoll()
{
    this->currentRoll++;
}
void LootList::LootList::ClearAddCurrentRoll()
{
    this->currentRoll = 0;
}

LootRarity LootList::GetRarity()
{
    return rarity;
}

vector<Loot> LootList::GetLootList()
{
    return lootList;
}

bool CompLootByRarity(LootList first, LootList second) {

    return first.GetRarity() > second.GetRarity();
}