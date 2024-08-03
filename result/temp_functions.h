#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#define MONTHS_COUNT 12
#define COLUMNS_COUNT 6

typedef struct Record
{
  int8_t min;
  int8_t max;
  uint16_t count;
  double full;
  double avg;
} Record;

void SetRecordData(Record *record, int t);

void PrintYear(struct Record *year);

void PrintMonth(struct Record *month, int number);

void PrintMonths(struct Record *months);

int FillTempStatOfFile(char *fileName, struct Record *months, struct Record *year);

void PrintRecord(char *fileName, int monthNumber);

#endif /* TEMP_FUNCTIONS_H */
