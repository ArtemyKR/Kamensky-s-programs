#include <stdio.h>
#include "stdlib.h"


int printmass(int ** c,int n, int m);
int printmass(int ** c,int n, int m) {
  for (int i = 0; i < n; i++)  
	{
    for (int j = 0; j < m; j++)  
    {
      printf("%5d ", c[i][j]); 
    }
		printf("\n");
}
}


int main(void)
{
  int **a; 
  int *b;
  int **c;
  int i, j, n, m,sum=0,pr=0,sh=0;
  FILE*input_file;
  input_file=fopen("fili.txt","r"); 

  if (NULL == input_file){
    printf("There is no any file");
    exit(1);
	}

  fscanf(input_file, "%d", &n);
  fscanf(input_file, "%d", &m);
  if (n==0 || m==0) {
		printf("Something wrong!n or m could not equals 0");
		exit(2);
	}
  b=(int*)malloc(n * sizeof(int));
  a = (int**)malloc(n * sizeof(int*));
  c = (int**)malloc(n * sizeof(int*));

  for (i = 0; i<n; i++)  //создали два одинаковых двумерных массива
  {
    a[i] = (int*)malloc(m * sizeof(int));
    c[i] = (int*)malloc(m * sizeof(int));
    for (j = 0; j<m; j++) 
    {
      fscanf(input_file, "%d", &a[i][j]);
	  (c[i][j]=a[i][j]);
    }
  }

  printmass(c,n,m);
  printf("\n");
  for (int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      sum = sum + a[i][j];   //сумма всех элементов строки i
    }
		b[i]=sum;
		sum=0;
  }

  for(int j = m-1;  j>-1; j--){
      for (int i = 0; i < n; i++){
			 if (a[i][j]==(b[i]-(a[i][j]))/(m-1)){
				pr=pr+1;                          //смотрим сколько элементов столбца j удовлетворяет условию задачи
			 }
		}
		 if (pr==n) {
			    int f=j; 
  
                for (int p = 0; p < n; p++){   
                   for (int j=f; j < m-1 ; j++){
                      (c[p][j]) = (c[p][j+1]);
                   }
				}
			 sh=sh+1;
			 j=m-sh;
             for (i = 0; i < n; i++){
				(c[i][j])=0;  //столбец m-sh необходимо обнулить
			}
		pr=0;
	}
	}
    printmass(c,n,m);
	input_file=fopen("pol.txt","w+"); 
    for (int i = 0; i < n; i++)  
	{
    for (int j = 0; j < m; j++)  
    {
      fprintf (input_file, "%5d", c[i][j]); 
    }
		 putc ('\n', input_file);
}

	return 0;
}
