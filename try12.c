#include <stdio.h>
#include "stdlib.h"
#include <string.h>

int Find(const char * filename, char *p)
{
	FILE *  fp;
	fp=fopen(filename,"r");
    if	(! filename) {
	 exit(-1);
	}
    int g=0;
	FILE *input_file;
	input_file=fopen("pol.txt","w+"); 
	char h;
	while( (h = fgetc(fp)) != EOF){
		if  ((h!=' ' && h!=',' && h!='\n' && h!='!' && h!='?' && h!='<' && h!='>' && h!='.') && (h!=EOF)) {
        putc (h, input_file); 
           	g=1;
		}
		else {
		if (g==1) {
		h=' ';
		putc (h, input_file); 
			}
			g=0;
		}
		}
   fclose(fp);
   fclose(input_file);
   FILE *input_file1;
   input_file1=fopen("pol.txt","r"); 
   int M,n=0,m=0,kh=0;
   char s[512];
   char zero[512];
   char w[512];
   int i,c =0 ;
   while(!feof(input_file1)) {
   int k=fscanf ( input_file1, "%s", s );
   for(i=0;i<strlen(s);i++)
		{
			if (s[i] <= 'Z' && s[i] >= 'A') {
				c++;
		}
				 else {
			c=0;
			break;
		}
		}
	if (s[c-1]!='A'){
		    c=0;
	}
	n=c;
	if (n-m>=0) {
			kh=n;
		}
	else {
			kh=m;
		}
	if (n>= kh) {
			M=n;
			m=kh;
			for ( int j=0; j<c; j++) {
				(w[j]=s[j]);
			}
			w[c]='\0';
		}
	for (int j=0; j<c; j++) {
		    s[j]=zero[j];
		}
	if (k==EOF)
		{
			break;
			}
		c=0;
		}
	if (M!=0) {
		  char * word=w;
		  printf("%s\n", w);
		
	}
	else{
		printf("There are not any words which you search\n");
		}
for (int j=0; j<c; j++) {
		    w[j]=zero[j];
		}
   fclose (input_file1);
   return 0;
}
   
int main(void)
{
  FILE * fp;
  fp=fopen("lizbon.txt","r");
    if	(! fp) {
	 printf("Can not find this file");
	 exit(-1);
	}
  Find("lizbon.txt", "Word"); 
	return 0;
}
