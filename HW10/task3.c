/*
Задача 3. Изменить расширение
В файле .txt записан полный адрес файла (возможно, без расширения).
Необходимо изменить его расширение на ".html" и записать результат в файл
.txt.
Данные на входе: Строка состоящая из символов: a-z, A-Z, 0-9, /
Данные на выходе: Исходная строка с измененным расширением.
Пример №1
Данные на входе: /DOC.TXT/qqq
Данные на выходе: /DOC.TXT/qqq.html
Пример №2
Данные на входе: /DOC.TXT/qqq.com
Данные на выходе: /DOC.TXT/qqq.html
*/


#include <stdio.h>
#include <locale.h>

#define MAX_LEN 1000

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


  FILE* output = fopen(outputFilteName, "w");
  fputs(str, output);
  fprintf(output, "\n");
  fclose(output);

  return 0;
}