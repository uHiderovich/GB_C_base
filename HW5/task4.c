/*
Задача 4. Сумма от 1 до N
Составить функцию, которая определяет сумму всех чисел от 1 до N и
привести пример ее использования.
Пример №1
Данные на входе: Одно целое положительное число N
Данные на выходе: Целое число - сумма чисел от 1 до N
Пример №2
Данные на входе: 100
Данные на выходе: 5050
*/

#include <stdio.h>
#include <locale.h>

int SumOfRange(int N) {
  int result = 0;

  for (int i = 1; i <= N; i++) {
    result += i;
  }

  return result;
}

int main(int argc, char const* argv[]) {
  setlocale(LC_ALL, "Rus");

  unsigned int num;
  scanf("%d", &num);

  printf("%d\n", SumOfRange(num));

  return 0;
}
