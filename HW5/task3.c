/*
Задача 3. Сумма цифр равна произведению
Составить логическую функцию, которая определяет, верно ли, что в заданном
числе сумма цифр равна произведению.
int is_happy_number(int n)
Данные на входе: Целое не отрицательное число
Данные на выходе: YES или NO
Пример №1
Данные на входе: 123
Данные на выходе: YES
Пример №2
Данные на входе: 528
Данные на выходе: NO
*/

#include <stdio.h>
#include <locale.h>

_Bool IsHappyNumber(int num) {
  int sum = 0;
  int mult = 1;

  while (num) {
    int head = num % 10;
    sum += head;
    mult *= head;
    num /= 10;
  }

  return sum == mult;
}

int main(int argc, char const* argv[]) {

  setlocale(LC_ALL, "Rus");

  unsigned int num;
  scanf("%d", &num);

  printf(IsHappyNumber(num) ? "YES\n" : "NO\n");

  return 0;
}
