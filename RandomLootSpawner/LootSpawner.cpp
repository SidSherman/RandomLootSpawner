#include "LootSpawner.h"

LootSpawner::LootSpawner()
    {

        // Add some loot for tests
        // 
        // SHOULD BE REMOVED AFTER USER INPUT OR DATA SERIALIZATiON INPLEMENTATION
        //
        
        // Add usual loot
        lootUsualList.push_back(Loot(LootRarity::Usual, 1, false));
        /*lootUsualList.push_back(Loot(LootRarity::Usual, 11, true));
        lootUsualList.push_back(Loot(LootRarity::Usual, 12, false));
        lootUsualList.push_back(Loot(LootRarity::Usual, 13, false));
        lootUsualList.push_back(Loot(LootRarity::Usual, 14, true));
        lootUsualList.push_back(Loot(LootRarity::Usual, 15, false));
        lootUsualList.push_back(Loot(LootRarity::Usual, 16, false));
        lootUsualList.push_back(Loot(LootRarity::Usual, 17, false));
        lootUsualList.push_back(Loot(LootRarity::Usual, 18, false));
        lootUsualList.push_back(Loot(LootRarity::Usual, 19, false));*/


        // Add rare loot

        lootRareList.push_back(Loot(LootRarity::Rare, 2, false));
       /* lootRareList.push_back(Loot(LootRarity::Rare, 22, false));
        lootRareList.push_back(Loot(LootRarity::Rare, 23, false));
        lootRareList.push_back(Loot(LootRarity::Rare, 24, false));
        lootRareList.push_back(Loot(LootRarity::Rare, 25, false));*/

        // Add legendary loot
        
       // lootLegendaryList.push_back(Loot(LootRarity::Legendary, 31, false));
       // lootLegendaryList.push_back(Loot(LootRarity::Legendary, 32, false));
       // lootLegendaryList.push_back(Loot(LootRarity::Legendary, 33, false));

        // Summon different loot lists 

        //LootList(vector<lootList>, LootRarity, minRoll, maxRoll, currentRoll);

       // AddLootList(LootList(lootUsualList, LootRarity::Usual, 0, 0, 0));
       // AddLootList(LootList(lootRareList, LootRarity::Rare, 5, 9, 0));
       // AddLootList(LootList(lootLegendaryList, LootRarity::Legendary, 11, 16, 0));

        // sort list by rarity

        LootLists.sort(CompLootByRarity);
    }

void LootSpawner::AddLootList(LootList list)
{
    LootLists.push_back(list);
    LootLists.sort(CompLootByRarity);
}

void LootSpawner::AddLootList(LootRarity rarity, int minRoll,int maxRoll,int currentRoll)
{
    switch (rarity)
    {
    case LootRarity::Usual:
        LootLists.push_back(LootList(lootUsualList, LootRarity::Usual, minRoll, maxRoll, currentRoll));
        break;
    case LootRarity::Rare:
        LootLists.push_back(LootList(lootRareList, LootRarity::Rare, minRoll, maxRoll, currentRoll));
        break;
    case LootRarity::Legendary:
        LootLists.push_back(LootList(lootLegendaryList, LootRarity::Legendary, minRoll, maxRoll, currentRoll));
        break;
    case LootRarity::ENUM_COUNT:
        break;
    default:
        break;
    }
    LootLists.sort(CompLootByRarity);
   
}

int LootSpawner::GetRandomLoot(vector <Loot>& array)
{
    if (array.size() == 0)
        return -1;

    int lootIndex = 0;

    if (array.size() > 1)
    {
        int iterations = 0;
        while (true)
        {
            int randValue = std::rand() % array.size();
            lootIndex = randValue;

            // return random item if there is no prev item
            if (previousLootValue == NULL)
            {
                previousLootValue = array[lootIndex].GetValue();

                return array[lootIndex].GetValue();
            }

            // check the item was not returned for prev drop
            if (array[lootIndex].GetValue() == previousLootValue)
            {
                if (array[lootIndex].GetCanRepeat())
                {
                    previousLootValue = array[lootIndex].GetValue();
                    return array[lootIndex].GetValue();
                }

                iterations++;
                if (iterations > 100)
                {
                    cout << "iterations limit";
                    previousLootValue = array[lootIndex].GetValue();

                    return array[lootIndex].GetValue();
                }
            }
            else
            {

                previousLootValue = array[lootIndex].GetValue();
                return array[lootIndex].GetValue();
            }
        }
    }

    return array[0].GetValue();
}

void LootSpawner::LootSpawn()
{

    for (LootList& lootRarityCategory : LootLists)
    {
        // check the rarity category can spawn

        if (lootRarityCategory.GetCurrentRoll() >= lootRarityCategory.GetMinRoll())
        {
            // check the rarity category should spawn
            if (lootRarityCategory.GetCurrentRoll() >= lootRarityCategory.GetMaxRoll())
            {
                vector<Loot> CurrentList = lootRarityCategory.GetLootList();

                cout << "value " << GetRandomLoot(CurrentList) << "\n";

                lootRarityCategory.ClearAddCurrentRoll();

                break;
            }

            // spawn item with 50% percent chance

            int randValue = rand() % 2;
            if (randValue == 1)
            {
                vector<Loot> CurrentList = lootRarityCategory.GetLootList();

                cout << "value " << GetRandomLoot(CurrentList) << "\n";

                lootRarityCategory.ClearAddCurrentRoll();

                break;

            }
            else if (randValue == 0)
            {
                lootRarityCategory.AddCurrentRoll();
                continue;
            }
        }

        lootRarityCategory.AddCurrentRoll();
    }
}

