void AddMonthRecord(struct month* months, int number, int t) {
  int currentMin = months[number].min;
  int currentMax = months[number].max;

  months[number].min = currentMin > t ? t : currentMin;
  months[number].max = currentMax < t ? t : currentMax;
  months[number].full += t;
  months[number].count++;
  months[number].avg = months[number].full / months[number].count;
}

void SetYearData(struct year* year, int t, int recordsCount) {
  int currentMin = year->min;
  int currentMax = year->max;

  year->min = currentMin > t ? t : currentMin;
  year->max = currentMax < t ? t : currentMax;
  year->full += t;
  year->avg = year->full / recordsCount;
}