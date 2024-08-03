#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#define MONTHS_COUNT 12
#define COLUMNS_COUNT 6

typedef struct Month
{
  int min;
  int max;
  int full;
  int count;
  double avg;
} Month;

typedef struct Year
{
  int min;
  int max;
  int full;
  int count;
  double avg;
} Year;

void SetMonthData(Month *months, int number, int t);

void SetYearData(struct Year *year, int t);

void PrintYear(struct Year *year);

void PrintMonth(struct Month *month, int number);

void PrintMonthsStat(struct Month *monthsStat, int number);

int FillTempStatOfFile(char *fileName, struct Month *monthsStat, struct Year *yearStat);

#endif /* TEMP_FUNCTIONS_H */
