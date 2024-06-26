/*
Задача 1. Сколько зерен на доске?
Когда создатель шахмат, древнеиндийский мудрец и математик Сисса бен
Дахир, показал своё изобретение Правителю страны, тому так понравилась
игра, что он позволил изобретателю право самому выбрать награду. Мудрец
попросил у Повелителя за первую клетку шахматной доски заплатить ему одно
зерно риса, за второе — два, за третье — четыре и т. д., удваивая количество
зёрен на каждой следующей клетке. Помоги повелителю сосчитать сколько
зерен на какой клетке лежит.
Необходимо составить функцию, которая определяет, сколько зерен попросил
положить на N-ую клетку изобретатель шахмат (на 1-ую – 1 зерно, на 2-ую – 2
зерна, на 3-ю – 4 зерна, …)
Данные на входе: Целое число от 1 до 64
Данные на выходе: Одно целое число. Количество зерен на данной
клетке.
Пример №1
Данные на входе: 3
Данные на выходе: 4
Пример №2
Данные на входе: 28
Данные на выходе: 134217728
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int GetNumberGrainsByCell(int cellNumber) {
  int result = 1;

  for (int i = 0; i < cellNumber - 1; i++) {
    result *= 2;
  }

  return result;
}

int main(int argc, char const* argv[]) {
  setlocale(LC_ALL, "Rus");

  int cellNumber;
  scanf("%d", &cellNumber);

  if (cellNumber < 1 || cellNumber > 64) {
    printf("Номер ячейки должен быть от 1 до 64\n");
  }
  else {
    printf("%d\n", GetNumberGrainsByCell(cellNumber));
  }

  return 0;
}
