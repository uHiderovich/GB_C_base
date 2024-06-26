/*
Задача 4. Найти среднее арифметическое цифр
числа
На вход подается произвольное четырехзначное число
Нужно напечатать среднее арифметическое цифр
Данные на входе: Четырехзначное целое положительное число
Данные на выходе: Вещественное число в формате %.2f
Пример №1:
Данные на входе: 4351
Данные на выходе: 3.25
Пример №2:
Данные на входе: 1020
Данные на выходе: 1.50
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a;
  scanf("%d", &a);

  int thousandths = a / 1000;
  int hundredths = (a % 1000) / 100;
  int tenth = (a % 100) / 10;
  int other = a % 10;

  float average = (thousandths + hundredths + tenth + other) / 4.f;
  printf("%.2f\n", average);

  return 0;
}
