/*
Задача 4. Перевернуть число
Ввести целое число и «перевернуть» его, так чтобы первая цифра стала
последней и т.д.
Данные на входе: Целое неотрицательное число
Данные на выходе: Целое неотрицательное число наоборот
Пример №1
Данные на входе: 1234
Данные на выходе: 4321
Пример №2
Данные на входе: 782
Данные на выходе: 287
*/

#include <stdio.h>
#include <locale.h>

int main(int argc, char const* argv[])
{
  setlocale(LC_ALL, "Rus");

  int num;
  scanf("%d", &num);

  if (num < 0) {
    num *= -1;
  }

  int reversed = 0;
  while (num) {
    reversed *= 10;
    reversed += (num % 10);
    num /= 10;
  }
  printf("%d\n", reversed);

  return 0;
}