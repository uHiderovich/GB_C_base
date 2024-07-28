#ifndef _TEMP_FUNCTIONS_H_
#define __TEMP_FUNCTIONS_H_

struct month
{
  uint16_t min;
  uint16_t max;
  uint16_t full;
  uint16_t avg;
  uint8_t count;
};

struct year
{
  uint16_t min;
  uint16_t max;
  uint16_t full;
  uint16_t avg;
};

void AddMonthRecord(struct month *months, int number, int t);

void SetYearData(struct year *year, int t, int recordsCount);

#endif /* _TEMP_FUNCTIONS_H_ */
