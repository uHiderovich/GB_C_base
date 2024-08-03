#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#define MONTHS_COUNT 12

struct month
{
  int min;
  int max;
  int full;
  int count;
  double avg;
};

struct year
{
  int min;
  int max;
  int full;
  int count;
  double avg;
};

void AddMonthRecord(struct month *months, int number, int t);

void SetYearData(struct year *year, int t);

void PrintYear(struct year *year);

void PrintMonth(struct month *month, int number);

void PrintMonthsStat(struct month *monthsStat, int number);

#endif /* TEMP_FUNCTIONS_H */
