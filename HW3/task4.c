/*
Задача 4. Какое время года
Ввести номер месяца и вывести название времени года.
Данные на входе: Целое число от 1 до 12 - номер месяца.
Данные на выходе: Время года на английском: winter, spring, summer, autumn
Пример №1
Данные на входе: 4
Данные на выходе: spring
Пример №2
Данные на входе: 1
Данные на выходе: winter
*/

int main(int argc, char const *argv[])
{
  int a;
  scanf("%d", &a);

  if (a >= 3 && a <= 5)
    printf("spring\n");
  else if (a >= 6 && a <= 8)
    printf("summer\n");
  else if (a >= 9 && a <= 11)
    printf("autumn\n");
  else
    printf("winter\n");

  return 0;
}