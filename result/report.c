#include <stdio.h>
#include <locale.h>
// #include <unistd.h>
#include "temp_functions.h"

// void PrintFunctions() {
//   printf("-h Описание функционала приложения. Список ключей, которые обрабатывает данное приложение и их назначение\n");
//   printf("-f <filename.csv> входной файл csv для обработки\n");
//   printf("-m <номер месяца> если задан данный ключ, то выводится только статистика за указанный месяц\n");
// }

void ReadFileData(char* filename) {
  FILE* file = fopen(filename, "r");
  if (!file) {
    printf("Ошибка открытия файла %s.\n", filename);
    return 1;
  }
  // fgets(str, MAX_LEN, input);
  fclose(file);
}

int main(int argc, char const* argv[]) {
  setlocale(LC_ALL, "Rus");

  char fileName[] = "temperature_big.csv";

  ReadFileData(fileName);

  // int res = 0;

  // while ((res = getopt(argc, argv, "hf:m:")) != -1) {
  //   switch (res) {
  //   printf("%s\n", optarg); break;
  //   printf("%s\n", optarg); break;
  //   case 'h': PrintFunctions(); break;
  //   default: PrintFunctions(); break;
  //   }
  // }

  return 0;
}
