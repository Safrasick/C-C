/*Дана матрица X[0:N-1,0:N-1] вещественного типа. Написать
программу, которая сортирует по возрастанию методом установки
главную диагональ матрицы, если сумма элементов под побочной
диагональю положительная. Вычисления оформить в виде функции с
параметрами.*/

#include <stdio.h>
#include <limits.h>
#define lmax 30

//функция проверки 

void f(int n, float a[][lmax]) {
    float sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i+j>n-1) sum += a[i][j];
        }
    }
  // изменение если сумма больше 0
    if(sum>0) {
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if(a[i][i]>a[j][j]) {
                    float c = a[i][i];
                    a[i][i] = a[j][j];
                    a[j][j] = c;
                }
            }
        }
    }
}
int main() {
  int n, c1;
  float x[lmax][lmax], b1, check;
  // ввод количества элементов матрицы
  do{
    printf("Enter number of row and columns from 1 to %d \n", lmax);
      b1 = scanf("%f", &check);
      n = (int) check;
          while (getchar() != '\n');
      } while (n <= 0 || n > lmax || b1 != 1 || n != check);
  // ввод элементов матрицы
  printf("Input elements of matrix A\n");
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      do{
        b1 = scanf("%f", &x[i][j]);
      }
        while(b1 != 1);
    }
  }
  //вызов функции
  f(n,x);
  printf("Answer:\n");
  for (int i = 0; i < n; ++i) {
      for (int j=0;j<n;j++) printf("%.1f ",x[i][j]);
      printf("\n");
  }

    return 0;
}
