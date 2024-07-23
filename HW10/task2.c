/*
Задача 2. Удалить пробелы из текста
В файле .txt необходимо удалить все лишние пробелы (в начале предложения
и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
записать в .txt.
Данные на входе: Строка из английских букв, знаков препинания и
пробелов. Не более 1000 символов.
Данные на выходе: Строка из английских букв, знаков препинания и
пробелов.
Пример
Данные на входе: Hello world!
Данные на выходе: Hello world!
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_LEN 1000

void ClearUnnecessarySpaces(char* str, char* result) {
  int index = 0;
  _Bool currentIsSpace, nextIsSpace, isEndIndex;

  for (int i = 0; str[i] != '\0'; i++) {
    char current = str[i];
    char next = str[i + 1];

    currentIsSpace = current == ' ';
    nextIsSpace = next == ' ';
    isEndIndex = (i == strlen(str) - 1);

    if (currentIsSpace && (i == 0 || nextIsSpace || isEndIndex)) {
      continue;
    }

    result[index++] = current;
  }

  result[index] = '\0';
}

int main() {
  setlocale(LC_ALL, "Rus");

  char str[MAX_LEN + 1];
  char result[MAX_LEN + 1];

  char* inputFilteName = "input.txt";
  char* outputFilteName = "output.txt";

  FILE* input = fopen(inputFilteName, "r");
  if (!input) {
    printf("Ошибка открытия файла %s.\n", inputFilteName);
    return 1;
  }
  fgets(str, MAX_LEN, input);
  fclose(input);

  ClearUnnecessarySpaces(str, result);

  FILE* output = fopen(outputFilteName, "w");
  fputs(result, output);
  fclose(output);

  return 0;
}