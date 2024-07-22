/*
Задача 3. Числа в массив
В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые
числа и иные символы. Требуется все числа, которые встречаются в строке,
поместить в отдельный целочисленный массив. Например, если дана строка
"data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести
массив по возрастанию в файл .txt.
Данные на входе: Строка из английских букв, цифр и знаков
препинания
Данные на выходе: Последовательность целых чисел
отсортированная по возрастанию
Пример
Данные на входе: data 48 call 9 read13 blank0a
Данные на выходе: 0 9 13 48
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_LEN 1000

int Compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int IsDigit(char c) {
  return c >= '0' && c <= '9';
}

int ExtractNumbers(char* str, int* numbers) {
  int index = 0;
  char* ptr = str;

  while (*ptr) {
    if (IsDigit(*ptr)) {
      numbers[index++] = strtol(ptr, &ptr, 10);
    }
    else {
      ptr++;
    }
  }
  return index;
}

int main() {
  setlocale(LC_ALL, "Rus");

  char str[MAX_LEN + 1];
  int numbers[MAX_LEN / 2];

  char* inputFilteName = "input.txt";
  char* outputFilteName = "output.txt";

  FILE* input = fopen(inputFilteName, "r");
  if (!input) {
    printf("Ошибка открытия файла %s.\n", inputFilteName);
    return 1;
  }
  fgets(str, MAX_LEN, input);
  fclose(input);

  int count = ExtractNumbers(str, numbers);
  qsort(numbers, count, sizeof(int), Compare);

  FILE* output = fopen(outputFilteName, "w");
  if (!output) {
    printf("Ошибка открытия файла %s.\n", outputFilteName);
    return 1;
  }
  for (int i = 0; i < count; i++) {
    fprintf(output, "%d ", numbers[i]);
  }
  fprintf(output, "\n");
  fclose(output);

  return 0;
}

