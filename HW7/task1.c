/*
Задача 1. Среднее арифметическое чисел
Ввести с клавиатуры массив из 5 элементов, найти среднее арифметическое
всех элементов массива.
Данные на входе: 5 целых ненулевых чисел через пробел
Данные на выходе: Одно число в формате "%.3f"
Пример №1
Данные на входе: 4 15 3 10 14
Данные на выходе: 9.200
Пример №2
Данные на входе: 1 2 3 4 5
Данные на выходе: 3.000
*/

#include <stdio.h>

enum ArraySize { ARRAY_SIZE = 5 };

void FillArray(int array[], enum ArraySize size) {
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
}

void PrintAverage(int array[], enum ArraySize size) {
  float sum = 0.0;

  for (int i = 0; i < size; i++) {
    sum += array[i];
  }

  printf("%.3f\n", sum / size);
}

int main() {
  int array[ARRAY_SIZE];

  FillArray(array, ARRAY_SIZE);

  PrintAverage(array, ARRAY_SIZE);

  return 0;
}