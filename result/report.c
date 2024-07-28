#include <stdio.h>
#include <locale.h>
#include <stdint.h>
// #include <unistd.h>
#include "temp_functions.h"

// void PrintFunctions() {
//   printf("-h Описание функционала приложения. Список ключей, которые обрабатывает данное приложение и их назначение\n");
//   printf("-f <filename.csv> входной файл csv для обработки\n");
//   printf("-m <номер месяца> если задан данный ключ, то выводится только статистика за указанный месяц\n");
// }

#define MONTHS_COUNT 12

void ReadFileData(char* filename) {
  struct month months[MONTHS_COUNT];
  struct year year;
  int r, counter, Y, M, D, h, m, t, yearMin, yearMax, yearAvg, yearFull = 0;

  FILE* file = fopen(filename, "r");
  if (!file) {
    printf("Ошибка открытия файла %s.\n", filename);
    return 1;
  };

  while ((r = fscanf(file, "%Y;%M;%D;%h;%m;%t", &Y, &M, &D, &h, &m, &t)) > 0) {
    SetYearData(year, t, counter++);
    AddMonthRecord(months, M - 1, t);
  }

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
