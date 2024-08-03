#include <stdio.h>
#include <locale.h>
#include <stdint.h>
#include <conio.h>
// #include <unistd.h>
#include "temp_functions.h"



void AddMonthRecord(struct month* months, int number, int t) {
  int currentMin = months[number].min;
  int currentMax = months[number].max;

  months[number].min = currentMin > t ? t : currentMin;
  months[number].max = currentMax < t ? t : currentMax;
  months[number].full += t;
  months[number].count++;
  months[number].avg = (months[number].full / months[number].count);
}

void SetYearData(struct year* year, int t) {
  int currentMin = year->min;
  int currentMax = year->max;

  year->min = currentMin > t ? t : currentMin;
  year->max = currentMax < t ? t : currentMax;
  year->full += t;
  year->count++;
  year->avg = (year->full / year->count);
}

void PrintYear(struct year* year) {
  printf("Статистика за год.\n");
  printf("Минимальная температура: %d\n", year->min);
  printf("Максимальная температура: %d\n", year->max);
  printf("Средняя температура: %f\n", year->avg);
  printf("----------\n\n");
}

void PrintMonth(struct month* month, int number) {
  printf("Месяц %d\n", number);
  printf("Минимальная температура: %d\n", month->min);
  printf("Максимальная температура: %d\n", month->max);
  printf("Средняя температура: %f\n", month->avg);
  printf("----------\n\n");
}

void PrintMonthsStat(struct month* monthsStat, int number) {
  if (number >= 1 && number <= MONTHS_COUNT) {
    printf("Статистика за выбранный месяц.\n");
    PrintMonth(&monthsStat[number + 1], number);
  }
  else {
    printf("Статистика по месяцам.\n\n");
    for (int i = 0; i < MONTHS_COUNT; i++) {
      PrintMonth(&monthsStat[i], i + 1);
    }
  }
}

// int main(int argc, char const* argv[]) {
int main() {
  setlocale(LC_ALL, "Rus");

  char fileName[] = "temperature_small.csv";

  struct month monthsStat[MONTHS_COUNT];
  struct year yearStat = { 0, 0, 0, 0, 0.0 };
  int r, rowsCount;
  int Y, M, D, h, m, t;

  FILE* file = fopen(fileName, "r");
  if (!file) {
    printf("Can't open %s file.\n", fileName);
    return 1;
  };

  while ((r = fscanf(file, "%d;%d;%d;%d;%d;%d", &Y, &M, &D, &h, &m, &t)) > 0) {
    rowsCount++;
    if (r < COLUMNS_COUNT)
    {
      char s[20];
      fscanf(file, "%[^\n]", s);
      printf("Ошибка в строке %d: %s\n\n", rowsCount, s);
    }
    else {
      SetYearData(&yearStat, t);
      AddMonthRecord(monthsStat, M - 1, t);
    }
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
