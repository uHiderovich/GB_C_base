/*
Задача 4. Удалить повторяющиеся символы
В файле .txt строка из маленьких и больших английских букв, знаков
препинания и пробелов. Требуется удалить из нее повторяющиеся символы и
все пробелы. Результат записать в файл .txt.
Данные на входе: Строка из маленьких и больших английских букв,
знаков препинания и пробелов. Размер строки не более 1000 символов.
Данные на выходе: Строка из маленьких и больших английских
букв.
Пример
Данные на входе: abc cde def
Данные на выходе: abcdef
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_LEN 1000

void RemoveDuplicatesAndSpaces(char* str, char* result) {
  int seen[26] = { 0 };
  int index = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    char charValue = str[i];
    int charNumber = charValue - 'a';

    if (charValue != ' ' && !seen[charNumber]) {
      seen[charNumber] = 1;
      result[index++] = charValue;
    }
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

  RemoveDuplicatesAndSpaces(str, result);

  FILE* output = fopen(outputFilteName, "w");
  fputs(result, output);
  fclose(output);

  return 0;
}

