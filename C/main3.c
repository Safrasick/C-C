#include <stdio.h>
#include <limits.h>
#include <math.h>
#define lmax 10

void vv_matr(int a[][lmax], int *n, int *m)  
{ 
int i, j;

printf("n = ");  scanf("%d", n);
printf("m = ");  scanf("%d", m);
printf("Введите матрицу размером %d на %d \n",*n,*m);
for(i=0; i<*n; i++)
    for(j=0; j<*m; j++)
        scanf("%d", a[i]+j);
}

//передаем  n   по значению
void viv_matr(int a[][lmax], int n, int m)   
 {int i, j;

for(i = 0; i < n; i++)
     {
     for(j = 0; j < m; j++)
         printf("%4d", a[i][j]);
   printf("\n");
     }    
}

int z(int n,int m, int  b[][lmax])
{int min,max,*ui,*uj; //uj –указатель на начало столбца,
 //ui - на элемент матрицы

min=INT_MAX;
   for (uj=*b;uj<*b+n;uj++)
   {max=*uj;   
       for (ui=uj+lmax; ui<b[n-1] + m;ui+=lmax)
         if (abs(*ui)>abs(max)) 
          max=*ui;

          if (max<min)
          min=max;
  }
      return min;
   }

int main()
{int b[lmax][lmax], H, n, m;

vv_matr(b, &n, &m); //ввод матрицы
viv_matr(b, n, m); //вывод матрицы
H=z(n,m,b); //вычисления
printf("H =%10d",H);
return 0;
}
