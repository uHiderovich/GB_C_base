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

void ReplaceFileExtensionOfPath(char* path, char* replacedPath) {
  for (int i = strlen(path) - 1; i > 0; i--) {
    if (path[i] == '/') {
      strcpy(replacedPath, path);
      strcat(replacedPath, ".html");
      break;
    }

    if (path[i] == '.') {
      memcpy(replacedPath, path, i);
      strcat(replacedPath, ".html");
      break;
    }
  }
}

int main() {
  setlocale(LC_ALL, "Rus");

  char path[MAX_LEN + 1];
  char replacedPath[MAX_LEN + 6];

  char* inputFilteName = "input.txt";
  char* outputFilteName = "output.txt";

  FILE* input = fopen(inputFilteName, "r");
  if (!input) {
    printf("Ошибка открытия файла %s.\n", inputFilteName);
    return 1;
  }
  fgets(path, MAX_LEN, input);
  fclose(input);

  ReplaceFileExtensionOfPath(path, replacedPath);

  FILE* output = fopen(outputFilteName, "w");
  fputs(replacedPath, output);
  fprintf(output, "\0");
  fclose(output);

  return 0;
}