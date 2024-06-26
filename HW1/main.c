
#include <stdio.h>
#include <locale.h>

int main(void)
{
  setlocale(LC_ALL, "Rus");

  char *ladder[] = {"Let’s", "go", "to walk", NULL};

  // Задание 1
  printf("Hello world!\n");
  printf("--------\n");

  // Задание 2
  for (int i = 0; ladder[i]; i++)
  {
    for (int j = 0; j < i; j++)
    {
      printf("  ");
    }

    printf("%s\n", ladder[i]);
  }

  printf("--------\n");

  // Задание 3
  int init = 4;

  for (int i = 0; i < init; i++)
  {
    for (int j = init - 1; j > i; j--)
    {
      printf(" ");
    }

    for (int j = 0; j <= i + (i * 1); j++)
    {
      printf("*");
    }

    printf("\n");
  }

  printf(" HH HH\n");
  printf(" ZZZZZ\n");

  return 0;
}