/*
Задача 3. Все цифры четные
Ввести целое число и определить, верно ли, что все его цифры четные
Данные на входе: Одно целое число
Данные на выходе: YES или NO
Пример №1
Данные на входе: 2684
Данные на выходе: YES
Пример №2
Данные на входе: 2994
Данные на выходе: NO
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
  int num;
  scanf("%d", &num);

  while (num)
  {
    int current = num % 10;
    if (current % 2 != 0)
    {
      break;
    }
    num /= 10;
  }

  num ? printf("NO\n") : printf("YES\n");

  return 0;
}