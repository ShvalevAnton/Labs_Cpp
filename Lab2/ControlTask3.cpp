#include <iostream>
#include <Windows.h>
using namespace std;

int ControlTask3()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   // Монетная система России (номиналы в копейках)
   int coins[] = { 1000, 500, 100, 50, 10, 5, 1 };
   int coin_count = sizeof(coins) / sizeof(coins[0]); // количество номиналов
   int amount;
   cout << "Введите сумму в копейках: "; cin >> amount;

   // Максимальное количество монет, которое может понадобиться (в худшем случае — все по 1 копейке)
   int result[10000]; // можно увеличить, если ожидается большая сумма
   int result_size = 0; // текущий размер результата

   for (int i = 0; i < coin_count; ++i) {
      while (amount >= coins[i]) {
         result[result_size++] = coins[i];
         amount -= coins[i];
      }
   }

   cout << "Набор монет:\n";
   for (int i = 0; i < result_size; ++i) {
      cout << result[i] << " ";
   }
   cout << endl;

   return 0;
  

   return 0;
}

