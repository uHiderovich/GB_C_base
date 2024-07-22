/*
Задача 1. Пары соседних символов
В файле .txt записаны символы. Необходимо разработать функцию, которая
меняет местами пары соседних символов не обращая внимание на символы
пробел. Если количество символов нечетно (пробелы не считаем), то
последний символ не меняем. Результат записать в файл .txt.
Данные на входе: Строка из английских букв, пробелов и знаков
препинания. Не более 1000 символов.
Данные на выходе: Строка из английских букв, пробелов и знаков
препинания.
Пример №1
Данные на входе: Hello world!
Данные на выходе: eHllw orodl!
Пример №2
Данные на входе: abc def
Данные на выходе: bad cfe
*/

#include <stdio.h>
#include <locale.h>

#define MAX_LEN 1000

void SwapPairs(char* str) {
  char current, next;
  int currentIndex, nextIndex;

  for (currentIndex = 0; str[currentIndex] != '\0'; currentIndex = nextIndex + 1) {
    nextIndex = currentIndex + 1;

    current = str[currentIndex];
    next = str[nextIndex];

    if (next == ' ') {
      nextIndex++;
      next = str[nextIndex];
    }

    str[currentIndex] = next;
    str[nextIndex] = current;
  }
}

int main() {
  setlocale(LC_ALL, "Rus");

  char str[MAX_LEN + 1];

  char* inputFilteName = "input.txt";
  char* outputFilteName = "output.txt";

  FILE* input = fopen(inputFilteName, "r");
  if (!input) {
    printf("Ошибка открытия файла %s.\n", inputFilteName);
    return 1;
  }
  fgets(str, MAX_LEN, input);
  fclose(input);

  SwapPairs(str);

  FILE* output = fopen(outputFilteName, "w");
  fputs(str, output);
  fprintf(output, "\n");
  fclose(output);

  return 0;
}