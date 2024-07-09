/*
Задача 5. Вторая с конца ноль
Считать массив из 10 элементов и отобрать в другой массив все числа, у
которых вторая с конца цифра (число десятков) – ноль.
Данные на входе: 10 целых чисел через пробел.
Данные на выходе: Целые числа через пробел, у которых вторая с конца
цифра - ноль
Пример
Данные на входе: 40 105 203 1 14 1000 22 33 44 55
Данные на выходе: 105 203 1 1000
*/

#include <stdio.h>

enum Setups { ARRAY_SIZE = 10 };

void FillArray(int* array, enum Setups size) {
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
}

void FilterArray(int* array, int* resultArray, enum Setups size) {
  int index = 0;
  for (int i = 0; i < size; i++) {
    if (array[i] / 10 % 10 == 0) {
      resultArray[index] = array[i];
      index++;
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
  int resultArray[ARRAY_SIZE] = { 0 };

  FillArray(array, ARRAY_SIZE);

  FilterArray(array, resultArray, ARRAY_SIZE);

  PrintArray(resultArray, ARRAY_SIZE);

  return 0;
}
