/*Даны целочисленная матрица A[0:N-1,0:M-1] и целочисленный
массив B[0:K-1]. Написать программу, которая обнуляет элементы
тех столбцов A, номера которых присутствуют в массиве B, и
вычисляет произведение элементов остальных столбцов. Вычисления
оформить в виде функции с параметрами.*/

#include <stdio.h>
#include <limits.h>
#define lmax 30

// функция для нахождения столбцов которые присутствуют в массиве В и обнуление элементов
void function_delete(int a[][lmax], int n, int m, int b[lmax],int k){
    int new_massive[lmax];
    for(int i = 0; i < k; i++){
        if(0 < b[i] && b[i] <= n){
            new_massive[b[i]-1] = 1;
        }
    }

  int answer = 1, counter = 0;
    for(int i = 0; i < m; i++){
        if(new_massive[i] == 1) {
            for(int j = 0; j < n; j++){
                a[j][i] = 0;
            }
        }
      else{
        for(int j = 0; j < n; j++){
          answer *= a[j][i];
          counter +=1;
      }
    }
    }
  printf("Answer \n");
  printf("Matrix: \n");
  for (int i = 0; i < n; ++i) {
      for (int j=0;j<m;j++) printf("%d ",a[i][j]);
      printf("\n");
  }
  if (counter == 0){
    printf("All elements matrix are 0\n");
  }
  else
    printf("Product of the remaining columns: %d\n", answer);
  
}

int main() {
  int a[lmax][lmax], b[lmax], m, n, k, b1, c1, c2, b2, x, y, b3;
  float el1, el2, check1, check2, check3;

  // ввод количества строк и столбцов матрицы с проверкой
  do{
  printf("Enter number of rows from 1 to %d \n", lmax);
        b1 = scanf("%f", &check1);
        n = (int) check1;
        while (getchar() != '\n');
    } while (n != check1 || n <= 0 || n > lmax || b1 != 1);

  do{
    printf("Enter number of columns from 1 to %d \n", lmax);
          b2 = scanf("%f", &check2);
          m = (int) check2;
          while (getchar() != '\n');
      } while (m <= 0 || m > lmax || b2 != 1 || m != check2);

  // ввод элементов матрицы с проверкой
  printf("Input elements of matrix A\n");
  for (int i = 0; i < n; i++){
    printf("Enter %d row\n", i+1);
    for (int j = 0; j < m; j++){
      do{
        c1 = scanf("%f", &el1);
        x = (int) el1;
        }
        while(x != el1 || c1 != 1 || x > INT_MAX);
      a[i][j] = x;
    }
  }

  // ввод элементов массива с проверкой
  do{
    printf("Enter amount of elements array B from 1 to %d \n", lmax);
      b3 = scanf("%f", &check3);
      k = (int) check3;
          while (getchar() != '\n');
      } while (k <= 0 || k > lmax || b3 != 1 || k != check3);

  printf("Input elements of array B\n");
  for (int i = 0; i < k; i++){
    do{
      c2 = scanf("%f", &el2);
      y = (int) el2;
    }
    while(y != el2 || y > INT_MAX || c2 != 1);
    b[i] = y;
  }
  function_delete(a, n, m, b, k);

  return 0;
}
