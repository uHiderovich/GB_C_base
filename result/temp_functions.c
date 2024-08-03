#include "temp_functions.h"

void SetRecordData(Record* record, int t) {
  int currentMin = record->min;
  int currentMax = record->max;

  record->min = currentMin > t ? t : currentMin;
  record->max = currentMax < t ? t : currentMax;
  record->full += t;
  record->count++;
  record->avg = (record->full / record->count);
}

void PrintYear(Record* year) {
  printf("Статистика за год.\n");
  printf("Минимальная температура: %d\n", year->min);
  printf("Максимальная температура: %d\n", year->max);
  printf("Средняя температура: %f\n", year->avg);
  printf("----------\n\n");
}

void PrintMonth(Record* month, int number) {
  printf("Месяц %d\n", number);
  printf("Минимальная температура: %d\n", month->min);
  printf("Максимальная температура: %d\n", month->max);
  printf("Средняя температура: %f\n", month->avg);
  printf("----------\n\n");
}

void PrintMonths(struct Record* months) {
  printf("Статистика по месяцам.\n");
  for (int i = 0; i < MONTHS_COUNT; i++) {
    PrintMonth(&months[i], i + 1);
  }
}

int FillTempStatOfFile(char* fileName, struct Record* months, struct Record* year) {
  int r, rowsCount;
  int Y, M, D, h, m, t;

  FILE* file = fopen(fileName, "r");
  if (!file) {
    printf("Ошибка открытия файла %s.\n", fileName);
  }
  else {
    while ((r = fscanf(file, "%d;%d;%d;%d;%d;%d", &Y, &M, &D, &h, &m, &t)) > 0) {
      rowsCount++;
      if (r < COLUMNS_COUNT)
      {
        char s[20];
        fscanf(file, "%[^\n]", s);
        printf("Ошибка в строке %d: %s\n\n", rowsCount, s);
      }
      else {
        SetRecordData(year, t);
        SetRecordData(&months[M - 1], t);
      }
    }
    fclose(file);
    return 0;
  }
}

void PrintRecord(char* fileName, int monthNumber) {
  Record months[MONTHS_COUNT];
  Record year = { 0, 0, 0.0, 0, 0.0 };

  for (int i = 0; i < 12; ++i) {
    months[i].min = 0;
    months[i].max = 0;
    months[i].full = 0.0;
    months[i].count = 0;
    months[i].avg = 0.0;
  }

  int readResult = FillTempStatOfFile(fileName, months, &year);

  if (readResult == 0) {
    if (monthNumber >= 1 && monthNumber <= MONTHS_COUNT) {
      PrintMonth(&months[monthNumber], monthNumber);
    }
    else {
      PrintYear(&year);
      PrintMonths(months);
    }
  }
}