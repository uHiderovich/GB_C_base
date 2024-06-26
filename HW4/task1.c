/*
Задача 1. Сумма квадратов маленьких чисел
Ввести два целых числа a и b (a ? b) и вывести сумму квадратов всех чисел от a
до b.
Данные на входе: Два целых числа по модулю не больше 100
Данные на выходе: Сумма квадратов от первого введенного числа до
второго
Пример №1
Данные на входе: 4 10
Данные на выходе: 371
Пример №2
Данные на входе: 1 5
Данные на выходе: 55
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char const* argv[]) {
  setlocale(LC_ALL, "Rus");

  int a, b;
  scanf("%d %d", &a, &b);

  if (a > b) {
    printf("a должно быть <= b\n");
  }
  else if ((abs(a) > 100 || abs(b) > 100)) {
    printf("a и b должны быть меньше 100\n");
  }
  else {
    int result = 0;
    for (int i = a; i <= b; i++) {
      result += (i * i);
    }
    printf("%d\n", result);
  }

  return 0;
}