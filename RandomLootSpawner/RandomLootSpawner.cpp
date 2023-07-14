// RandomLootTestTask.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "LootSpawner.h"

using namespace std;

int main()
{

    cout << "There are 18 items in the chest: 10 usual, 5 rare and 3 legendary \n";
    cout << "Usual startwith 1, rare startwith 2, legendary startwith 3 \n";
    cout << endl;

    srand(time(NULL));
    int value = 1;
    LootSpawner* lootDropperComponent = new LootSpawner();

    while (true)
    {
        cout << "Enter Zero to exit, any value to spawn ";
        cin >> value;
        if (value == 0)
            break;
       lootDropperComponent->LootSpawn();
    }

}