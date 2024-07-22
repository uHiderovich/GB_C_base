/*
Задача 2. Заменить a на b
В файле .txt дана символьная строка не более 1000 символов. Необходимо
заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и
строчные. Результат записать в .txt.
Данные на входе: Строка из маленьких и больших английских букв,
знаков препинания и пробелов.
Данные на выходе: Строка из маленьких и больших английских
букв, знаков препинания и пробелов.
Пример
Данные на входе: aabbccddABCD
Данные на выходе: bbaaccddBACD
*/

#include <stdio.h>
#include <locale.h>

#define MAX_LEN 1000

void ReplaceChars(char* str) {
  _Bool isA;
  _Bool isB;
  int diff;

  for (int i = 0; str[i] != '\0'; i++) {
    isA = str[i] == 'a' || str[i] == 'A';
    isB = str[i] == 'b' || str[i] == 'B';

    diff = isA ? 1 : isB ? -1 : 0;

    str[i] += diff;
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

  ReplaceChars(str);

  FILE* output = fopen(outputFilteName, "w");
  fputs(str, output);
  fprintf(output, "\n");
  fclose(output);

  return 0;
}

