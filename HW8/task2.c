/*
Задача 2. Четные в начало
Написать только одну функцию, которая ставит в начало массива все четные
элементы, а в конец – все нечетные. Не нарушайте порядок следования чисел
между собой. Строго согласно прототипу:
void sort_even_odd(int n, int a[])
Данные на входе: Функция принимает на вход целые числа
Данные на выходе: Отсортированный исходный массив
Пример №1
Данные на входе: 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
Данные на выходе: 20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3
1
Пример №2
Данные на входе: 1 0 1 0 1
Данные на выходе: 0 0 1 1 1
*/

// #include <stdio.h>

void sort_even_odd(int n, int a[]) {
  int evenIndex = 0;
  int oddIndex = n - 1;

  while (evenIndex < oddIndex) {
    if (a[evenIndex] % 2 == 0) {
      evenIndex++;
    }
    else {
      int temp = a[oddIndex];
      a[oddIndex] = a[evenIndex];
      a[evenIndex] = temp;
      oddIndex--;
    }
  }
}


// int main() {
//   int array[] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//   int size = 20;

//   sort_even_odd(size, array);

//   for (int i = 0; i < size; ++i) {
//     printf("%d ", array[i]);
//   }

//   printf("\n");

//   return 0;
// }

