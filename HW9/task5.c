/*
Задача 5. Самое длинное слово
В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное
слово и вывести его в файл .txt. Случай, когда самых длинных слов может быть
несколько, не обрабатывать.
Данные на входе: Строка из английских букв и пробелов. Не более
1000 символов.
Данные на выходе: Одно слово из английских букв.
Пример
Данные на входе: Hello beautiful world
Данные на выходе: beautiful
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_LEN 1000

void FindLongestWord(char* str, char* longestWord) {
  int maxLength = 0;
  int currentWordLength = 0;
  char currentStr[MAX_LEN + 1];

  for (int i = 0; str[i] != '\0'; i++) {
    char ch = str[i];
    if (ch != ' ') {
      currentStr[currentWordLength++] = ch;
    }
    else if (currentWordLength > maxLength) {
      strcpy(longestWord, currentStr);
      currentWordLength = 0;
    }
    else {
      currentWordLength = 0;
      memset(currentStr, 0, sizeof(currentStr));
    }
  }
}

int main() {
  setlocale(LC_ALL, "Rus");

  char str[MAX_LEN + 1];
  char longestWord[MAX_LEN + 1];

  char* inputFilteName = "input.txt";
  char* outputFilteName = "output.txt";

  FILE* input = fopen(inputFilteName, "r");
  if (!input) {
    printf("Ошибка открытия файла %s.\n", inputFilteName);
    return 1;
  }
  fgets(str, MAX_LEN, input);
  fclose(input);

  str[strcspn(str, "\n")] = '\0';
  FindLongestWord(str, longestWord);

  FILE* output = fopen(outputFilteName, "w");
  fprintf(output, "%s\n", longestWord);
  fclose(output);

  return 0;
}
