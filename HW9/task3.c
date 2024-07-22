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

  FILE* input = fopen("input.txt", "r");
  FILE* output = fopen("output.txt", "w");

  if (!input || !output) {
    printf("Ошибка открытия файла.\n");
    return 1;
  }

  char str[MAX_LEN + 1];
  int numbers[MAX_LEN / 2];

  fgets(str, MAX_LEN, input);

  int count = ExtractNumbers(str, numbers);

  qsort(numbers, count, sizeof(int), Compare);

  for (int i = 0; i < count; i++) {
    if (i > 0) fprintf(output, " ");
    fprintf(output, "%d", numbers[i]);
  }
  fprintf(output, "\n");

  fclose(input);
  fclose(output);

  return 0;
}

