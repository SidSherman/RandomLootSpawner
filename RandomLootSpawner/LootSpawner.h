#pragma once
#include <vector>
#include <list>
#include <algorithm>
#include "Loot.h"
#include "LootList.h"
#include <iostream>

using namespace std;

class LootSpawner
{


private:

    vector<Loot> lootUsualList;
    vector<Loot> lootRareList;
    vector<Loot> lootLegendaryList;
    list <LootList> LootLists;
    int previousLootValue = NULL;
    int previousLootIndex = 0;

public:
    LootSpawner();
    
    void AddLootList(LootList list);
    void AddLootList(LootRarity rarity, int minRoll, int maxRoll, int currentRoll);

    // Select item Category and spawn random item from list
    void LootSpawn();

    // Get random item from list 
    int GetRandomLoot(vector <Loot>& array);

    
};

