// RandomLootTestTask.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "LootSpawner.h"

using namespace std;

int main()
{

    cout << "Usual items startwith 1, rare startwith 2 \n";
   
    cout << endl;

    int value = 1;
    LootSpawner* lootDropperComponent = new LootSpawner();

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


    lootDropperComponent->AddLootList(LootRarity::Usual, 100);
    lootDropperComponent->AddLootList(LootRarity::Rare, frequency);

    while (true)
    {
        int success = 0;

        lootDropperComponent->ResetAllEntropy();

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