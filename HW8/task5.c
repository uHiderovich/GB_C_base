/*
Задача 5. Поменять местами
Составить функцию, которая меняет в массиве минимальный и максимальный
элемент местами. Прототип функции
void change_max_min(int size, int a[])
Данные на входе: Функция принимает на вход размер массива и
массив чисел типа int
Данные на выходе: Функция не возвращает значения, измененный
массив сохраняется на месте исходного.
Пример
Данные на входе: 1 2 3 4 5 6 7 8 9 10
Данные на выходе: 10 2 3 4 5 6 7 8 9 1
*/

// #include <stdio.h>

void change_max_min(int size, int a[]) {
  int minIndex = 0;
  int maxIndex = 0;

  for (int i = 1; i < size; i++) {
    if (a[i] < a[minIndex]) {
      minIndex = i;
    }
    if (a[i] > a[maxIndex]) {
      maxIndex = i;
    }
  }

  int temp = a[minIndex];
  a[minIndex] = a[maxIndex];
  a[maxIndex] = temp;
}

// int main() {
//   int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//   int size = sizeof(arr) / sizeof(arr[0]);

//   change_max_min(size, arr);

//   for (int i = 0; i < size; ++i) {
//     printf("%d ", arr[i]);
//   }

//   return 0;
// }
