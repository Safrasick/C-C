Задание 1
    #include <stdio.h>
    #include <locale.h>
    #define lmax 100
    int main()
    {
        setlocale(LC_ALL, "Russian");
        int n, m, k, i, j, a1, b1, c1, cmax, cmin, maxi, mini, com, flagchange, flag1 = 0, flag2 = 0, l, c[lmax][lmax], a[lmax];
        printf("Лабораторная работа №2\nЗадание №1 вариант 5\nВведите длину массива А от 1 до %d:\n", lmax);
      do {
          b1 = scanf("%d", &k);
          while (getchar() != '\n');
      } while (k <= 0 || k >= lmax || b1 != 1);
      printf("Введите количество строк матрицы C от 1 до %d:\n", lmax);
      do {
            a1 = scanf("%d", &n);
            while (getchar() != '\n');
        } while (n <= 0 || n >= lmax || a1 != 1);
      printf("Введите количество столбцов матрицы C от 1 до %d:\n", lmax);
      do {
            c1 = scanf("%d", &m);
            while (getchar() != '\n');
        } while (m <= 0 || m >= lmax || c1 != 1);
        printf("Введите элементы массива А:\n");
        for (i = 0; i < k; i++) {
            scanf("%d", &a[i]);
        }
      printf("Введите матрицу С:\n");
      for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) {
              scanf("%d", &c[i][j]);
          }
      }
        flagchange = 0;
        for (j = 0; j < m; j++) {
            cmax = -100;
            cmin = 100;
            flag1 = 0;
            flag2 = 0;
            for (i = 0; i < n; i++) {
                if (c[i][j] >= cmax) {
                    cmax = c[i][j];
                    maxi= i;
                }
                if (c[i][j] < cmin) {
                    cmin = c[i][j];
                    mini = i;
                }
            }
            l = 0;
            do {
                if (cmax == a[l]) {
                    flag1 = 1;
                }
                l = l + 1;
            } while (l < k && flag1 == 0);
            l = 0;
            do {
                if (cmin == a[l]) {
                    flag2 = 1;
                }
                l = l + 1;
            } while (l < k && flag2 == 0);
            if (flag2 == 1 && flag2 == 1) {
                com = c[maxi][j];
                c[maxi][j] = c[mini][j];
                c[mini][j] = com;
                flagchange = 1;
            }
        }
        if (flagchange == 0) {
            printf("Матрица не изменилась:\n");
        }
        else {
            printf("Вывод измененной матрицы:\n");
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }

        return 0;
    }
Задание 2
#include <stdio.h>
#include <math.h>
#define Lmax 200

int main() {
  printf("Задание №2 вариант 1\n");
  setlocale(0, "");
  int n = 0, m = 0, k = 0, A[Lmax], B[Lmax], b1;
  do {
    printf("Введите длину массива A от 1 до %d\n", Lmax);
  do {
      b1 = scanf("%d", &k);}
      while (getchar() != '\n');
  } while (k <= 0 || k >= Lmax || b1 != 1);
  printf("Введите массив А:\n");
  for (int i = 0; i < k; i++) {
      scanf("%d", &A[i]);
  }
  for (int i = 0; i < k; i++) {
    B[i] = 0;
    if (A[i] < 0)
      A[i] = -A[i];
    while (A[i] > 0) {
      B[i] += A[i] % 10;
      A[i] /= 10;
    }
  }
  
  printf("Вывод массива суммы цифр исходного массива:\n");
  for (int i = 0; i < k; i++) {
    printf("%d ", B[i]);
  }
  return 0;
}
