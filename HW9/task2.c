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

#define MAX_LEN 1000

void ReplaceChars(char* str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == 'a') {
      str[i] = 'b';
    }
    else if (str[i] == 'b') {
      str[i] = 'a';
    }
    else if (str[i] == 'A') {
      str[i] = 'B';
    }
    else if (str[i] == 'B') {
      str[i] = 'A';
    }
  }
}

int main() {
  FILE* input = fopen("input.txt", "r");
  FILE* output = fopen("output.txt", "w");

  if (!input || !output) {
    printf("Ошибка открытия файла.\n");
    return 1;
  }

  char str[MAX_LEN + 1];

  fgets(str, MAX_LEN, input);

  ReplaceChars(str);

  fputs(str, output);

  fclose(input);
  fclose(output);

  return 0;
}

