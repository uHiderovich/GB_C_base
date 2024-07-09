/*
Задача 6. Чаще других
Дан массив из 10 элементов. Определить, какое число в массиве встречается
чаще всего. Гарантируется, что такое число ровно 1.
Данные на входе: 10 целых числе через пробел
Данные на выходе: Одно число, которое встречается чаще других.
Пример
Данные на входе: 4 1 2 1 11 2 34 11 0 11
Данные на выходе: 11
*/

#include <stdio.h>

enum Setups { ARRAY_SIZE = 10 };

void FillArray(int* array, enum Setups size) {
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
}

int FindMostly(int* array, enum Setups size) {
  static int maxValue = 0;
  static int maxCount = 0;
  static int currentIndex = 0;
  int currentMax = 0;

  if (currentIndex > size) {
    return maxValue;
  }

  for (int i = currentIndex; i < size; i++) {
    if (array[i] == array[currentIndex]) {
      currentMax++;
    }
  }

  if (maxCount < currentMax) {
    maxValue = array[currentIndex];
    maxCount = currentMax;
  }

  currentIndex++;
  return FindMostly(array, size);
}

int main(int argc, char const* argv[]) {
  int array[ARRAY_SIZE] = { 0 };

  FillArray(array, ARRAY_SIZE);

  FindMostly(array, ARRAY_SIZE);

  printf("%d\n", FindMostly(array, ARRAY_SIZE));

  return 0;
}
