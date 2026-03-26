#include "LootSpawner.h"

LootSpawner::LootSpawner() : rng(std::random_device{}())
    {

        // Add some loot for tests
        // 
        // SHOULD BE REMOVED AFTER USER INPUT OR DATA SERIALIZATiON INPLEMENTATION
        //
        
        // Add usual loot
        lootUsualList.push_back(Loot(LootRarity::Usual, 1, true));
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

        lootRareList.push_back(Loot(LootRarity::Rare, 2, true));
       /*lootRareList.push_back(Loot(LootRarity::Rare, 22, false));
        lootRareList.push_back(Loot(LootRarity::Rare, 23, false));
        lootRareList.push_back(Loot(LootRarity::Rare, 24, false));
        lootRareList.push_back(Loot(LootRarity::Rare, 25, false));*/


        // Summon different loot lists 

        //LootList(vector<lootList>, LootRarity, minRoll, maxRoll, currentRoll);

       // AddLootList(LootList(lootUsualList, LootRarity::Usual, 0, 0, 0));
       // AddLootList(LootList(lootRareList, LootRarity::Rare, 5, 9, 0));

        // sort list by rarity

        LootLists.sort(CompLootByRarity);
    }

void LootSpawner::AddLootList(LootList list)
{
    LootLists.push_back(list);
    LootLists.sort(CompLootByRarity);
}

void LootSpawner::AddLootList(LootRarity rarity, int frequency)
{
    std::uniform_int_distribution<int> dist(0, 99);
    int initialEntropy = dist(rng);

    switch (rarity)
    {
    case LootRarity::Usual:
        LootLists.push_back(LootList(lootUsualList, LootRarity::Usual, frequency, initialEntropy));
        break;
    case LootRarity::Rare:
        LootLists.push_back(LootList(lootRareList, LootRarity::Rare, frequency, initialEntropy));
        break;
    case LootRarity::ENUM_COUNT:
        break;
    default:
        break;
    }
    LootLists.sort(CompLootByRarity);
   
}

void LootSpawner::ResetAllEntropy()
{
    std::uniform_int_distribution<int> dist(0, 99);

    for (LootList& lootRarityCategory : LootLists)
    {
        // Обновляем энтропию только для списков, где шанс меньше 100% 
        // и которые не являются "обычным" лутом.
        if (lootRarityCategory.GetFrequency() < 100 && lootRarityCategory.GetRarity() != LootRarity::Usual)
        {
            int newInitialEntropy = dist(rng);
            lootRarityCategory.SetCurrentRoll(newInitialEntropy);

            // Опционально: можно вывести в консоль для дебага
            // std::cout << "Entropy for rarity reset to: " << newInitialEntropy << "\n";
        }
    }
}


Loot LootSpawner::GetRandomLoot(vector <Loot>& array)
{
    if (array.empty())
    {
        cout << "Loot list is empty\n";
        return Loot(); 
    }

    if (array.size() == 1)
    {
        return array[0];
    }

    
    std::uniform_int_distribution<int> dist(0, array.size() - 1);

    int lootIndex = 0;
    int iterations = 0;

    while (true)
    {
     
        lootIndex = dist(rng);

       
        if (previousLootValue == -1)
        {
            previousLootValue = array[lootIndex].GetValue();
            return array[lootIndex];
        }

        // check the item was not returned for prev drop
        if (array[lootIndex].GetValue() == previousLootValue)
        {
            if (array[lootIndex].GetCanRepeat())
            {
                previousLootValue = array[lootIndex].GetValue();
                return array[lootIndex];
            }

            iterations++;
            if (iterations > 100)
            {
                cout << "iterations limit\n";
                previousLootValue = array[lootIndex].GetValue();
                return array[lootIndex];
            }
        }
        else
        {
            previousLootValue = array[lootIndex].GetValue();
            return array[lootIndex];
        }
    }
}

Loot LootSpawner::LootSpawn()
{
    // Важно: подразумевается, что список отсортирован так, 
    // что редкие предметы (Rare) проверяются первыми.
    for (LootList& lootRarityCategory : LootLists)
    {

        if (lootRarityCategory.GetRarity() == LootRarity::Usual)
        {
            // Предмет выпал!
            vector<Loot> CurrentList = lootRarityCategory.GetLootList();
            Loot value = GetRandomLoot(CurrentList);

            return value;
        }

        int maxEntropyGain = lootRarityCategory.GetFrequency() * 2;
        std::uniform_int_distribution<int> fuzzyDist(0, maxEntropyGain);

        // Получаем случайный прирост энтропии
        int addedEntropy = fuzzyDist(rng);

        // Прибавляем к текущему счетчику
        int currentEntropy = lootRarityCategory.GetCurrentRoll() + addedEntropy;

        // 2. Проверяем, перевалило ли за 100%
        if (currentEntropy >= 100)
        {
            // Предмет выпал!
            vector<Loot> CurrentList = lootRarityCategory.GetLootList();
            Loot value = GetRandomLoot(CurrentList);

            // ВАЖНО: Вычитаем 100, а не сбрасываем в 0. Сохраняем "сдачу".
            // Для этого вам понадобится метод SetCurrentRoll в классе LootList
            lootRarityCategory.SetCurrentRoll(currentEntropy - 100);

            return value;
        }
        else
        {
            // Предмет не выпал, сохраняем накопленную энтропию до следующего броска
            lootRarityCategory.SetCurrentRoll(currentEntropy);
        }
    }

    // Ничего не выпало
    return Loot(); // Возвращаем пустой объект (без new)
}

