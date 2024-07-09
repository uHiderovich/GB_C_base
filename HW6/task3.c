/*
Задача 3. Количество 1
Дано натуральное число N. Посчитать количество «1» в двоичной записи
числа.
Данные на входе: Натуральное число
Данные на выходе: Целое число - количество единиц в двоичной записи
числа.
Пример №1
Данные на входе: 5
Данные на выходе: 2
Пример №2
Данные на входе: 255
Данные на выходе: 8
*/

#include <stdio.h>

int SumUnits(int num) {
  if (num / 2 == 0) {
    return num % 2;
  }

  return num % 2 + SumUnits(num / 2);
}

int main(int argc, char const* argv[]) {
  int num;
  scanf("%d", &num);

  printf("%d", SumUnits(num));

  return 0;
}