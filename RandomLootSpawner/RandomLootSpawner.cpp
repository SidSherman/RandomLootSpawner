// RandomLootTestTask.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "LootSpawner.h"
#include <math.h>
#include <cmath>

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
    float frequency = 0;

    cout << "Enter averange chance from 0 to 100 to drop rare item \n";
    cin >> frequency;

    if (frequency>100)
    {
        frequency = 100;
    }
    if (frequency < 0)
    {
        frequency = 0;
    }

    cout << "Enter upper chance variance to drop rare item \n";
    cin >> maxRoll;

    maxRoll = frequency - maxRoll;



    if (maxRoll > frequency)
    {
        maxRoll = frequency;
        maxRoll = round(100 / frequency);
    }
    else if (maxRoll <= 0)
    {
        maxRoll = 0;
    }
    else
    {
        maxRoll = round(100 / maxRoll);
    }

    cout << "Enter below chance variance to drop rare item \n";
    cin >> minRoll;

    minRoll = frequency + minRoll;

    if (minRoll > 100)
    {
        minRoll = 100;
        minRoll = round(100 / frequency);
    }
    if (minRoll < frequency)
    {
        minRoll = frequency;
        minRoll = round(100 / frequency);
    }
    else
    {
        minRoll = round(100 / minRoll);
    }



    cout << "item will be dropped around " << frequency << " times in 100 rolls" << endl;

    lootDropperComponent->AddLootList(LootRarity::Usual, 100, 0, 0, 0);
    lootDropperComponent->AddLootList(LootRarity::Rare, frequency, minRoll, maxRoll, 0);

    while (true)
    {
        int success = 0;

        cout << "Enter rolls count , Enter Zero to exit ";
        cin >> value;

        if (value == 0)
            break;
        int count = 0;


       for (int i = 0; i < value; i++)
        {
            cout << "Current roll " << count << endl << endl;
            
            Loot temp = lootDropperComponent->LootSpawn();
            cout << "value " << temp.GetValue() << endl;

            if (temp.GetRarity() == LootRarity::Rare)
                success++;

            count++;
           
        }

       cout << "Rare items drop " << success << endl;
       
    }

}