#include <ctype.h>  
#include <stdio.h>
#include <string.h>

// Выделить из строки подстроки, содержащие только латинские буквы и цифры

int search(char str[][50], int n, char str1[][50])
{
  int i,j,k=0,m=0;
  for(i=0; i<n; i++)
  {
    for(j=0;str[i][j]!='\0'; j++)
    {
      if (isalpha(str[i][j]) || isdigit(str[i][j])) 
      {
        str1[m][k]=str[i][j];
        k++;
        if(isalpha(str[i][j+1])==0 && isdigit(str[i][j+1])==0)
        {
          str1[m][k]='\0';
          m++;
          k=0;
        }
      }
    }
  str1[m][k]='\0';
  }
  return m;
}



//поиск самого длинного
int longest(char str1[][50], int n1) {
    int i, len_max=0, len, longest_num=-1;
    char *t;
    for(i=0; i<n1; i++) {
        t=str1[i];
        len=strlen(t);
        if(len>len_max) {
          len_max=len;
          longest_num=i;
        }
    }
    return longest_num;
}
//преобразование исходной строки
int delete_space(char *t) {
    int i, flag=0;
    char *t1;
    t1=t;
    while(*t&&*t==' ') {
        t++;
    }
    if(t1!=t) {
        flag=1;
        while(*t&&t1<(t+strlen(t))-(t-t1)) {
            *t1=*t;
            *t='\0';
            t++;
            t1++;
        }
    }
    return flag;
}


int main()
{ 
    char str[20][50], str1[40][50];
    int i=0, L, L1, p, longest_num, flag=0, num[40], m;
    float r;
    puts("Laboratory work 4\nPetrunina Maria\nTask 1\n");
    do {
        printf("Enter L: L>0 and L<=20:\n");
        p=scanf("%f", &r);
        L=(int)r;
        while(getchar()!='\n');
    } while(r>20||r<0||r!=L||!p);
    printf("Enter %d strings:\n", L);
    while(i<L&& gets(str[i]))
        i++;
    if(!i)
        puts("The array of strings is empty!\n");
    else {
        m = search(str, L, str1);
        if(m == 0)
            puts("There are no suitable substrings!");
        else {
            puts("\n Task1 \n Suitable substrings have been found:");
          int i;
          for(i=0;i<m;i++){ puts(str1[i]);}
            puts("Task 2");
            longest_num=longest(str1, m);
            puts("The longest substring:");
            puts(str1[longest_num]);
            puts("Task 3");
            puts("String that should be changed:");
            puts(str[longest_num]);
            if(delete_space(str[longest_num])) {
                puts("The string has been changed:");
                puts(str[longest_num]);
            }
            else
                puts("The string has not been changed");
        }
    }
    return 0;
}
