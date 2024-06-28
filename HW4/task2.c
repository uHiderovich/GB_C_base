/*
Задача 2. Ровно три цифры
Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.
Данные на входе: Целое положительное число
Данные на выходе: Одно слово: YES или NO
Пример №1
Данные на входе: 123
Данные на выходе: YES
Пример №2
Данные на входе: 1234
Данные на выходе: NO
*/

#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
  setlocale(LC_ALL, "Rus");

  int num;
  scanf("%d", &num);

  if (num < 0)
    printf("Должно быть положительное число");
  else
  {
    int count = 3;
    while (count)
    {
      num /= 10;
      count--;
    }
    num ? printf("NO\n") : printf("YES\n");
  }

  return 0;
}