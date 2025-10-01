#include <iostream>
#include <Windows.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int ControlTask4()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   // Инициализация генератора случайных чисел
   srand(static_cast<unsigned int>(time(0)));

   // Генерируем случайный центр мишени в пределах [-5, 5] для интереса
   double target_x = (rand() % 11 - 5) + static_cast<double>(rand()) / RAND_MAX;
   double target_y = (rand() % 11 - 5) + static_cast<double>(rand()) / RAND_MAX;

   cout << "Мишень спрятана! Стреляйте вслепую!" << endl;
   cout << "Центр мишени: (" << fixed << setprecision(2) << target_x << ", " << target_y << ")" << endl;
   cout << "Но вы не должны знать это! Удачи!" << endl << endl;

   const int TARGET_SCORE = 30;
   int total_score = 0;
   int shots = 0;

   cout << "Введите координаты выстрела (x y). Наберите " << TARGET_SCORE << " очков!" << endl;

   while (total_score < TARGET_SCORE) {
      double x, y;
      cout << "Выстрел #" << shots + 1 << ": ";
      cin >> x >> y;

      // Добавляем случайную помеху (например, от -0.5 до +0.5)
      double noise_x = (static_cast<double>(rand()) / RAND_MAX - 0.5) * 1.0; // ±0.5
      double noise_y = (static_cast<double>(rand()) / RAND_MAX - 0.5) * 1.0; // ±0.5

      double actual_x = x + noise_x;
      double actual_y = y + noise_y;

      cout << "Помеха! Фактический выстрел: (" << fixed << setprecision(2)
         << actual_x << ", " << actual_y << ")" << endl;

      // Расстояние от фактической точки до центра мишени
      double distance = sqrt((actual_x - target_x) * (actual_x - target_x) +
         (actual_y - target_y) * (actual_y - target_y));

      int score = 0;
      if (distance <= 1.0) {
         score = 10;
         cout << "Попадание в центр! +10 баллов!" << endl;
      }
      else if (distance <= 2.0) {
         score = 5;
         cout << "Попадание в мишень! +5 баллов!" << endl;
      }
      else {
         cout << "Мимо! 0 баллов." << endl;
      }

      total_score += score;
      shots++;

      cout << "Текущий счёт: " << total_score << " / " << TARGET_SCORE << endl << endl;
   }

   // Вывод результата
   cout << "Поздравляем!Вы набрали " << total_score << " очков за " << shots << " выстрелов!" << endl;

   // Определение уровня стрелка
   string level;
   if (shots <= 5) {
      level = "СНАЙПЕР";
   }
   else if (shots <= 10) {
      level = "ОПЫТНЫЙ СТРЕЛОК";
   }
   else if (shots <= 15) {
      level = "СТРЕЛОК";
   }
   else {
      level = "НОВИЧОК";
   }

   cout << "Ваш уровень: " << level << endl;

   return 0;
}

