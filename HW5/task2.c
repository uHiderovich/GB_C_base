/*
Составить функцию, которая определяет наибольший общий делитель двух
натуральных и привести пример ее использования
https://younglinux.info/algorithm/euclidean
int nod(int a, int b)
Данные на входе: Два целых положительных числа
Данные на выходе: Одно целое число - наибольший общий делитель.
Пример №1
Данные на входе: 14 21
Данные на выходе: 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int nod(int a, int b) {
  while (a != 0 && b != 0) {
    if (a > b)
      a = a % b;
    else
      b = b % a;
  }

  return a + b;
}

int main(int argc, char const* argv[]) {
  setlocale(LC_ALL, "Rus");

  unsigned int a, b;
  scanf("%d %d", &a, &b);

  printf("%d\n", nod(a, b));

  return 0;
}
