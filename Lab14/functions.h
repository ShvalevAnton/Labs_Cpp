#pragma once
#include "functions.h"
#include <iostream>
#include <string>
#include <tuple>
#include <vector>


using namespace std;
using Tuple = tuple<string, int, double>;

template<class T>
void sorting(T arr[], int size) {
   int j = 0;
   for (int i = 0; i < size; i++) {
      T x = arr[i];
      for (j = i - 1; j >= 0 && x < arr[j]; j--)
         arr[j + 1] = arr[j];
      arr[j + 1] = x;
   }
}

template<class Tuple>
void printTupleOfThree(Tuple t)
{
   cout << "("
      << get<0>(t) << ", "
      << get<1>(t) << ", "
      << get<2>(t) << ")" << endl;
}

template<class Tuple, std::size_t N>
struct TuplePrinter {
   static void print(const Tuple& t)
   {
      TuplePrinter<Tuple, N - 1>::print(t);
      cout << ", " << get<N - 1>(t);
   }
};

template<class Tuple>
struct TuplePrinter<Tuple, 1> {
   static void print(const Tuple& t)
   {
      cout << get<0>(t);
   }
};

template<class... Args>
void printTuple(const tuple<Args...>& t)
{
   cout << "(";
   TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
   cout << ")" << endl;
}

//// Шаблонный класс массива
//template<class T, class T1> class array
//{
//public:
//   array(int size);
//   T1 sum();
//   T average_value();
//   void show_array();
//   int add_value(T);
//private:
//   T* data;
//   int size;
//   int index;
//};
//
//// Конструктор
//template<class T, class T1> array<T, T1>::array(int size)
//{
//   data = new T[size];
//   if (data == NULL)
//   {
//      cerr << "Error memory ---- exit program" << endl;
//      exit(1);
//   }
//   array::size = size;
//   array::index = 0;
//}
//
//// Метод для вычисления суммы
//template<class T, class T1> T1 array<T, T1>::sum()
//{
//   T1 sum = 0;
//   for (int i = 0; i < index; i++) sum += data[i];
//   return(sum);
//}
//
//// Метод для вычисления среднего значения
//template<class T, class T1> T array<T, T1>::average_value()
//{
//   T1 sum_val = 0;
//   for (int i = 0; i < index; i++) sum_val += data[i];
//   return (sum_val / index);
//}
//
//// Метод для отображения массива
//template<class T, class T1> void array<T, T1>::show_array()
//{
//   for (int i = 0; i < index; i++) cout << data[i] << ' ';
//   cout << endl;
//}
//
//// Метод для добавления значения
//template<class T, class T1> int array<T, T1>::add_value(T value)
//{
//   if (index == size)
//      return(-1);
//   else
//   {
//      data[index] = value;
//      index++;
//      return(0);
//   }
//}
//

