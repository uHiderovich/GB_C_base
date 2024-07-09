/*
Задача 3. Циклический сдвиг массива вправо на 4
Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4
элемента.
Данные на входе: 12 целых чисел через пробел
Данные на выходе: 12 целых чисел через пробел
Пример №1
Данные на входе: 4 -5 3 10 -4 -6 8 -10 1 0 5 7
Данные на выходе: 1 0 5 7 4 -5 3 10 -4 -6 8 -10
Пример №2
Данные на входе: 1 2 3 4 5 6 7 8 9 10 11 12
Данные на выходе: 9 10 11 12 1 2 3 4 5 6 7 8
*/

#include <stdio.h>

enum Setups { ARRAY_SIZE = 12, DIFF = 4 };

void FillArray(int* array, enum Setups size) {
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
}

void DiffArray(int* array, enum Setups size, enum Setups diff) {
  int tempArray[diff];

  // Сохраняем последние четыре элемента в вспомогательный массив
  for (int i = 0; i < diff; i++) {
    tempArray[i] = array[size - diff + i];
  }

  // Перемещаем первые восемь элементов на четыре позиции вправо
  for (int i = size - 1; i >= diff; i--) {
    array[i] = array[i - diff];
  }

  // Заполняем первые четыре позиции из доп массива
  for (int i = 0; i < diff; i++) {
    array[i] = tempArray[i];
  }
}

void PrintArray(int* array, enum Setups size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int array[ARRAY_SIZE] = { 0 };

  FillArray(array, ARRAY_SIZE);

  DiffArray(array, ARRAY_SIZE, DIFF);

  PrintArray(array, ARRAY_SIZE);

  return 0;
}