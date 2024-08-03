#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include "temp_functions.h"

void PrintMenu() {
  printf("-h Описание функционала приложения\n");
  printf("-f <filename.csv> входной файл csv для обработки\n");
  printf("-m <номер месяца> если задан данный ключ, то выводится только статистика за указанный месяц\n");
}

int main(int argc, char const* argv[]) {
  setlocale(LC_ALL, "Rus");

  int res = 0;
  int monthNumber = -1;
  char fileName[50] = "temperature_big.csv";
  _Bool printRecord = 0;

  while ((res = getopt(argc, argv, "hf:m:")) != -1) {
    printRecord = 1;
    switch (res) {
    case 'f':
      strcpy(fileName, optarg); break;
    case 'm':
      monthNumber = atoi(optarg); break;
    case 'h':
      PrintMenu();
      break;
    }
  }

  if (printRecord) {
    PrintRecord(fileName, monthNumber);
  }
  else {
    PrintMenu();
  }


  return 0;
}
