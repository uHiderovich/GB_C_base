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

  FILE* input = fopen("input.txt", "r");
  FILE* output = fopen("output.txt", "w");

  if (!input || !output) {
    printf("Ошибка открытия файла.\n");
    return 1;
  }

  char str[MAX_LEN + 1];
  char longest_word[MAX_LEN + 1];

  fgets(str, MAX_LEN, input);

  str[strcspn(str, "\n")] = '\0';

  FindLongestWord(str, longest_word);

  fprintf(output, "%s\n", longest_word);

  fclose(input);
  fclose(output);

  return 0;
}
