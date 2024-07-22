/*
Задача 1. По одному разу
В файле .txt даны два слова не более 100 символов каждое, разделенные
одним пробелом. Найдите только те символы слов, которые встречаются в
обоих словах только один раз. Напечатайте их через пробел в файл .txt в
лексикографическом порядке.
Данные на входе: Два слова из маленьких английских букв через
пробел. Длинна каждого слова не больше 100 символов.
Данные на выходе: Маленькие английские буквы через пробел.
Пример №1
Данные на входе: hello world
Данные на выходе: o
Данные на входе: aabcd bcef
Данные на выходе: b c
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_LEN 100
#define SYMBOLS_MAX_COUNT 26

void SortChars(char* chars, int count) {
  for (int i = 0; i < count - 1; i++) {
    for (int j = i + 1; j < count; j++) {
      if (chars[i] > chars[j]) {
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
      }
    }
  }
}

void CalcSymbolsCount(char* word, int* count) {
  for (int i = 0; word[i] != '\0'; i++) {
    count[word[i] - 'a']++;
  }
}

void FindUniqueChars(char* word1, char* word2, char* result) {
  int count1[SYMBOLS_MAX_COUNT] = { 0 };
  int count2[SYMBOLS_MAX_COUNT] = { 0 };
  int index = 0;

  CalcSymbolsCount(word1, count1);

  CalcSymbolsCount(word2, count2);

  for (int i = 0; i < SYMBOLS_MAX_COUNT; i++) {
    if (count1[i] == 1 && count2[i] == 1) {
      result[index++] = (char)(i + 97);
    }
  }

  result[index] = '\0';

  SortChars(result, index);
}

int main() {
  setlocale(LC_ALL, "Rus");

  char* inputFilteName = "input.txt";
  char* outputFilteName = "output.txt";

  char word1[MAX_LEN + 1], word2[MAX_LEN + 1], result[MAX_LEN + 1];

  FILE* input = fopen(inputFilteName, "r");
  if (!input) {
    printf("Ошибка открытия файла %s.\n", inputFilteName);
    return 1;
  }
  fscanf(input, "%s %s", word1, word2);
  fclose(input);

  FindUniqueChars(word1, word2, result);

  FILE* output = fopen(outputFilteName, "w");
  if (!output) {
    printf("Ошибка открытия файла %s.\n", outputFilteName);
    return 1;
  }
  for (int i = 0; result[i] != '\0'; i++) {
    fprintf(output, "%c ", result[i]);
  }
  fprintf(output, "\n");
  fclose(output);

  return 0;
}

