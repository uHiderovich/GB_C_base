#include <stdio.h>
#include <locale.h>
#include <stdint.h>
// #include <unistd.h>
#include "temp_functions.h"


// int main(int argc, char const* argv[]) {
int main() {
  setlocale(LC_ALL, "Rus");

  char fileName[] = "temperature_small.csv";

  struct month monthsStat[MONTHS_COUNT];
  struct year yearStat = { 0, 0, 0, 0, 0.0 };
  int r;
  int Y, M, D, h, m, t;

  FILE* file = fopen(fileName, "r");
  if (!file) {
    printf("Can't open %s file.\n", fileName);
    return 1;
  };

  while ((r = fscanf(file, "%d;%d;%d;%d;%d;%d", &Y, &M, &D, &h, &m, &t)) > 0) {
    SetYearData(&yearStat, t);
    AddMonthRecord(monthsStat, M - 1, t);
  }
  fclose(file);

  PrintYear(&yearStat);
  PrintMonthsStat(monthsStat, -1);


  // int res = 0;

  // while ((res = getopt(argc, argv, "hf:y:m:")) != -1) {
  //   switch (res) {
  //   printf("%s\n", optarg); break;
  //   printf("%s\n", optarg); break;
  //   case 'h': PrintFunctions(); break;
  //   default: PrintFunctions(); break;
  //   }
  // }

  return 0;
}
