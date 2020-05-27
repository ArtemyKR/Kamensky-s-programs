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
	return 0;
}


int main(void)
{
  int **a; 
  double *b;
  int **c;
  int i, j, n, m,pr=0,sh=0;
  double sum=0;
  FILE*input_file;
  input_file=fopen("fili.txt","r"); 

  if (NULL == input_file){
    printf("There is no any file");
    exit(1);
	}

  if ((fscanf(input_file, "%d", &n))!= 1) {
		printf("File is empty");
		exit(3);
	}
  fscanf(input_file, "%d", &m);
  if (n==0 || m==0) {
		printf("Something wrong!n or m could not equals 0");
		exit(2);
	}
  b=(double*)malloc(n * sizeof(double));
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
	if (a==0) {
		exit(45);
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

  for(int h = m-1;  h>-1; h--){
      for (int i = 0; i < n; i++){
			 if (a[i][h]==(b[i]-(a[i][h]))/(m-1)){
				pr=pr+1;                           //смотрим сколько элементов столбца j удовлетворяет условию задачи
			 }
		}
		 if (pr==n) {
			    int f=h; 
                  for (int p = 0; p < n; p++){   
                   for (int j=f; j < m-1 ; j++){
                      (c[p][j]) = (c[p][j+1]);
                   }
				}
			 sh=sh+1;
	}
		pr=0;
	}
    for (i = 0; i<n; i++) 
  {
    c[i] = (int*)realloc(c[i],(m-sh) * sizeof(int));
   }
    if (c==0) {
		exit(45);
	}

    printmass(c,n,m-sh);
	input_file=fopen("pol.txt","w+"); 
    for (int i = 0; i < n; i++)  
	{
    for (int j = 0; j < m-sh; j++)  
    {
      fprintf (input_file, "%5d", c[i][j]); 
    }
		 putc ('\n', input_file);
}

	return 0;
}
