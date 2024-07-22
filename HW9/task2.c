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
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == 'a' || str[i] == 'A') {
      str[i] += 1;
    }
    else if (str[i] == 'b' || str[i] == 'B') {
      str[i] -= 1;
    }
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
  if (!output) {
    printf("Ошибка открытия файла %s.\n", outputFilteName);
    return 1;
  }
  fputs(str, output);
  fprintf(output, "\n");
  fclose(output);

  return 0;
}

