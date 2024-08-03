#include <stdint.h>
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
  printf("РЎС‚Р°С‚РёСЃС‚РёРєР° Р·Р° РіРѕРґ.\n");
  printf("РњРёРЅРёРјР°Р»СЊРЅР°СЏ С‚РµРјРїРµСЂР°С‚СѓСЂР°: %d\n", year->min);
  printf("РњР°РєСЃРёРјР°Р»СЊРЅР°СЏ С‚РµРјРїРµСЂР°С‚СѓСЂР°: %d\n", year->max);
  printf("РЎСЂРµРґРЅСЏСЏ С‚РµРјРїРµСЂР°С‚СѓСЂР°: %f\n", year->avg);
  printf("----------\n\n");
}

void PrintMonth(struct month* month, int number) {
  printf("РњРµСЃСЏС† %d\n", number);
  printf("РњРёРЅРёРјР°Р»СЊРЅР°СЏ С‚РµРјРїРµСЂР°С‚СѓСЂР°: %d\n", month->min);
  printf("РњР°РєСЃРёРјР°Р»СЊРЅР°СЏ С‚РµРјРїРµСЂР°С‚СѓСЂР°: %d\n", month->max);
  printf("РЎСЂРµРґРЅСЏСЏ С‚РµРјРїРµСЂР°С‚СѓСЂР°: %f\n", month->avg);
  printf("----------\n\n");
}

void PrintMonthsStat(struct month* monthsStat, int number) {
  if (number >= 1 && number <= MONTHS_COUNT) {
    printf("РЎС‚Р°С‚РёСЃС‚РёРєР° Р·Р° РІС‹Р±СЂР°РЅРЅС‹Р№ РјРµСЃСЏС†.\n");
    PrintMonth(&monthsStat[number + 1], number);
  }
  else {
    printf("РЎС‚Р°С‚РёСЃС‚РёРєР° РїРѕ РјРµСЃСЏС†Р°Рј.\n\n");
    for (int i = 0; i < MONTHS_COUNT; i++) {
      PrintMonth(&monthsStat[i], i + 1);
    }
  }
}