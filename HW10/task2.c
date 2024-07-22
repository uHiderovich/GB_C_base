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