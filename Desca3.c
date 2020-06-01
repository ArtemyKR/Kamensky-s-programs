#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int n , int m);
int min(int n , int m) {
	int f;
	if ((n-m)>0) {
		f=m;
	}
	else {
		f=n;
	}
	return f;
}

int printmass(int ** c,int stroki, int * num);
int printmass(int ** c,int stroki, int * num) {
  for(int i = 0; i < stroki; i++){
		for(int j = 0; j < num[i]; j++){
    {
      printf("%5d ", c[i][j]); 
    }
		}
		printf("\n");

	}
	return 0;
} 

int cut(int **a, int stroki, int * num, int pr2);
int cut(int **a, int stroki, int * num, int pr2){
	for(int i = 0; i < stroki; i++){
		if (pr2!=num[i]) {
		for(int j = pr2; j < num[i]; j++){
			a[i][j] = a[i][j+1];
		}
		a[i]= (int*)realloc(a[i],(num[i]-1) * sizeof(int));
		num[i]=num[i]-1;
		}
		else {
			a[i][pr2]=0;
         a[i]= (int*)realloc(a[i],(num[i]-1) * sizeof(int));
		num[i]=num[i]-1;
	}
	}
	return 0;
}

int main(void) {
	int i = 0,stroki=0,k=0,n=0,pum=0,MIN;
	char x,x2='g';
	FILE*file, * input;
	int * num;
	int * sum;
	int **a;
	file = fopen("fili.txt", "r");
    if(!file){
        printf("Невозможно открыть файл\n");
        return 1;
}
	while(1){				
		x = fgetc(file);
		if((x == '\n' && x2 != '\n' && x2!='g') || x==EOF){
			++stroki;
		}
		if(x == EOF){
			break;
		}
		x2 = x;
	}
	rewind(file);
	int c;
	if (fscanf(file,"%d ",&c)!=1) {
		printf("Empty file");
	}
	rewind(file);
	num = (int*) malloc((stroki) * sizeof(int));
	sum = (int*) malloc((stroki) * sizeof(int));
	printf("\n");
	rewind(file);
	a = (int**)malloc(stroki * sizeof(int*));
	x2=' ';
	while(1){	
        x = fgetc(file);	
		if ((x!= ' ' && x!= '\n' && x!= EOF) && !isdigit(x2)) {
				++n;
			}
		if(x == '\n' || x== EOF){
			if (n!=0) {
			a[k] = (int*)malloc((n)*sizeof(int));
			num[k] = n;
			MIN=min(MIN,n);
		    ++k;	
			n = 0;	
			}
		}
		if(x == EOF){
			break;
		}
		x2=x;
	}
	rewind(file);
    for(int i = 0; i < stroki; i++){
		for(int j = 0; j < num[i]; j++){
			fscanf(file,"%d ",&(a)[i][j]);
			pum=pum+a[i][j];
		}
		sum[i]=pum;
		pum=0;
	}
	int pr2,pr1=0;
       for(int i = 0; i < stroki; i++){
		for(int j = 0; j < num[i]; j++){
			if ((a[i][j])*num[i]==sum[i] ) {
				pr2=min(pr2,j);
				pr1=1;
			}
					}
		}
     if (pr1==1) {
       cut(a, stroki, num, pr2);
	}
    printmass(a, stroki, num);
    fclose(file);
    input=fopen("pol.txt","w+"); 
   for(int i = 0; i < stroki; i++)
		{
		for(int j = 0; j < num[i]; j++)
    {
      fprintf (input, "%5d", a[i][j]); 
    }
		 putc ('\n', input);
}

  return 0;
}










