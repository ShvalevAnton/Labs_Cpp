#pragma once

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