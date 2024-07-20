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

#define MAX_LEN 1000

void RemoveDuplicatesAndSpaces(char* str, char* result) {
  int seen[256] = { 0 };
  int index = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    char ch = str[i];
    if (ch != ' ' && !seen[(unsigned char)ch]) {
      seen[(unsigned char)ch] = 1;
      result[index++] = ch;
    }
  }
  result[index] = '\0';
}

int main() {
  FILE* input = fopen("input.txt", "r");
  FILE* output = fopen("output.txt", "w");

  if (!input || !output) {
    printf("Ошибка открытия файла.\n");
    return 1;
  }

  char str[MAX_LEN + 1];
  char result[MAX_LEN + 1];

  fgets(str, MAX_LEN, input);

  RemoveDuplicatesAndSpaces(str, result);

  fputs(result, output);

  fclose(input);
  fclose(output);

  return 0;
}

