/*
Задача 4. Отсортировать по последней цифре
Считать массив из 10 элементов и отсортировать его по последней цифре.
Данные на входе: 10 целых чисел через пробел
Этот же массив отсортированный по последней цифре
Пример №1
Данные на входе: 14 25 13 30 76 58 32 11 41 97
Данные на выходе: 30 11 41 32 13 14 25 76 97 58
Пример №2
Данные на входе: 109 118 100 51 62 73 1007 16 4 555
Данные на выходе: 100 51 62 73 4 555 16 1007 118 109
*/

#include <stdio.h>

enum Setups { ARRAY_SIZE = 10 };

void FillArray(int* array, enum Setups size) {
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
}

void SortArrayByLastNumber(int* array, enum Setups size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (array[i] % 10 < array[j] % 10) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

void PrintArray(int* array, enum Setups size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main(int argc, char const* argv[]) {
  int array[ARRAY_SIZE] = { 0 };

  FillArray(array, ARRAY_SIZE);

  SortArrayByLastNumber(array, ARRAY_SIZE);

  PrintArray(array, ARRAY_SIZE);

  return 0;
}
