/*
Задача 6. Больше среднего
Определить количество положительных элементов квадратной матрицы,
превышающих по величине среднее арифметическое всех элементов главной
диагонали. Реализовать функцию среднее арифметическое главной
диагонали.
Данные на входе: 5 строк по 5 целых чисел через пробел
Данные на выходе: Одно целое число
Пример
Данные на входе: 1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5
Данные на выходе: 10
*/

#include <stdio.h>

const int size = 5;

float mean_diagonal(int matrix[size][size]) {
  int sum = 0;

  for (int i = 0; i < size; i++) {
    sum += matrix[i][i];
  }

  return (float)sum / size;
}

int count_greater_than_mean(int matrix[size][size], float mean) {
  int count = 0;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (matrix[i][j] > mean && matrix[i][j] > 0) {
        count++;
      }
    }
  }

  return count;
}

void input_matrix(int matrix[size][size]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

// int main() {
//   int matrix[size][size];

//   input_matrix(matrix);

//   float mean = mean_diagonal(matrix);

//   int count = count_greater_than_mean(matrix, mean);

//   printf("%.3f %d", mean, count);

//   return 0;
// }

