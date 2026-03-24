#pragma once
#include <vector>
#include <list>
#include <algorithm>
#include "Loot.h"
#include "LootList.h"
#include <iostream>
#include <random>
using namespace std;

class LootSpawner
{


private:

    vector<Loot> lootUsualList;
    vector<Loot> lootRareList;

    list <LootList> LootLists;
    int previousLootValue = -1;

public:
    LootSpawner();
    
    void AddLootList(LootList list);
    void AddLootList(LootRarity rarity, int frequency, int minRoll, int maxRoll, int currentRoll);

    // Select item Category and spawn random item from list
    Loot LootSpawn();

    // Get random item from list 
    Loot GetRandomLoot(vector <Loot>& array);

    
};

