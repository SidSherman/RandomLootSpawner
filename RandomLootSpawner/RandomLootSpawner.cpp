// RandomLootTestTask.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "LootSpawner.h"
#include <math.h>

using namespace std;

int main()
{

    cout << "Usual items startwith 1, rare startwith 2 \n";
   
    cout << endl;

    srand(time(NULL));
    int value = 1;
    LootSpawner* lootDropperComponent = new LootSpawner();

    int maxRoll = 0;
    int minRoll = 0;
    int MeanRoll = 0;
    float frequency = 0;
    cout << "Enter max roll count to drop rare item \n";
    cin >> maxRoll;
    cout << "Enter min roll count to drop rare item \n";
    cin >> minRoll;

    if (minRoll <= 0)
        frequency = 100;
    else
        frequency = round((100.f / (float) minRoll + 100.f / (float) maxRoll) / 2.f);

    cout << "item drop around " << frequency << " times in 100 rolls" << endl;

    lootDropperComponent->AddLootList(LootRarity::Usual, 0, 0, 0);
    lootDropperComponent->AddLootList(LootRarity::Rare, minRoll, maxRoll, 0);

    while (true)
    {
        cout << "Enter rolls count , Enter Zero to exit ";
        cin >> value;

        if (value == 0)
            break;
        int count = 0;


       for (int i = 0; i < value; i++)
        {
            cout << "Current roll " << count << endl << endl;
            lootDropperComponent->LootSpawn();
            count++;
           
        }
       
    }

}