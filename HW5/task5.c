/*
Задача 5*. Скобки
Проверить строку состоящую из скобок "(" и ")" на корректность.
Данные на входе: На вход подается строка состоящая из символов '(', ')'
и заканчивающаяся символом '.'. Размер строки не более 1000 символов.
Данные на выходе: Необходимо напечатать слово YES если скобки
расставлены верно и NO в противном случае.
Пример №1
Данные на входе: (()()).
Данные на выходе: YES
Пример №2
Данные на входе: ()(.
Данные на выходе: NO
*/

#include <stdio.h>

int IsBalanced(char* string) {
  int counter = 0;

  for (int i = 0; string[i]; i++) {
    if (string[i] == '(')
      counter++;

    if (string[i] == ')')
      counter--;

    if (counter == -1)
      return 0;
  }

  return counter == 0;
}

int main(int argc, char const* argv[])
{
  char* string[100];
  scanf("%s", &string);

  if (string == NULL) {
    printf("Введите строку");
  }
  else {
    printf(IsBalanced(string) ? "YES\n" : "NO\n");
  }

  return 0;
}
