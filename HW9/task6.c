/*
Задача 6. Заканчивается на a
В файле .txt дано предложение. Необходимо определить, сколько слов
заканчиваются на букву 'а'. Ответ записать в файл .txt.
Данные на входе: Строка из английских букв и пробелов не более 1000
символов.
Данные на выходе: Одно целое число
Пример
Данные на входе: Mama mila ramu
Данные на выходе: 2
*/


#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_LEN 1000

int FindCountEndA(char* str) {
  int counter = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ' && str[i - 1] == 'a') {
      counter++;
    }
  }

  return counter;
}

int main() {
  setlocale(LC_ALL, "Rus");

  FILE* input = fopen("input.txt", "r");
  FILE* output = fopen("output.txt", "w");

  if (!input || !output) {
    printf("Ошибка открытия файла.\n");
    return 1;
  }

  char str[MAX_LEN + 1];

  fgets(str, MAX_LEN, input);

  fprintf(output, "%d\n", FindCountEndA(str));

  fclose(input);
  fclose(output);

  return 0;
}
