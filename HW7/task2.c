/*
Задача 2. Найти минимум
Ввести с клавиатуры массив из 5 элементов, найти минимальный из них.
Данные на входе: 5 целых чисел через пробел
Данные на выходе: Одно единственное целое число
Пример №1
Данные на входе: 4 15 3 10 14
Данные на выходе: 3
Пример №2
Данные на входе: 1 2 3 4 -5
Данные на выходе: -5
*/

#include <stdio.h>

enum Setups { ARRAY_SIZE = 5 };

void FillArray(int* array, enum Setups size) {
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
}

void PrintMin(int* array, enum Setups size) {
  int min = array[0];

  for (int i = 1; i < size; i++) {
    if (min > array[i]) {
      min = array[i];
    }
  }

  printf("%d\n", min);
}

int main() {
  int array[ARRAY_SIZE] = { 0 };

  FillArray(array, ARRAY_SIZE);

  PrintMin(array, ARRAY_SIZE);

  return 0;
}
