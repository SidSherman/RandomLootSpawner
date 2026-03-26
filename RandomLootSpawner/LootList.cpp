#include "LootList.h"

LootList::LootList(vector<Loot> lootList, LootRarity rarity, int frequency, int currentRoll)
{
    this->rarity = rarity;
    this->minRoll = minRoll;
    this->frequency = frequency;
    this->maxRoll = maxRoll;
    this->currentRoll = currentRoll;
    this->lootList = lootList;
}

LootList::LootList()
{
}


int LootList::GetFrequency()
{
    return frequency;
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
void LootList::ClearAddCurrentRoll()
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

void LootList::SetCurrentRoll(int value)
{
    currentRoll = value;
}

bool CompLootByRarity(LootList first, LootList second) {

    return first.GetRarity() > second.GetRarity();
}