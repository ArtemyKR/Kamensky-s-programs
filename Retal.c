#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef
struct Student_{
    char Name[513];
    int Group;
    int Rating;
}Student;

int Input(Student* Sarra, FILE* file, int number);
int Output(Student* Sarra, int number);
void alt(Student* Sarra, int* number);

int Input(Student* Sarra, FILE* file, int number){
    int temp_Group = 0;
    char temp_Name[25];
    int temp_Rating = 0;

    for (int i = 0; i  < number; i++){

        fscanf(file, "%s", &temp_Name);
        fscanf(file, "%d", &temp_Group);
        fscanf(file, "%d", &temp_Rating);

        Sarra[i].Group = temp_Group;
        Sarra[i].Rating = temp_Rating;
        strcpy(Sarra[i].Name, temp_Name);

    }
    return 0;
}

int Output(Student* Sarra, int number){
    for (int i = 0; i < number; i++){
        printf("%s  %d  %d\n", Sarra[i].Name, Sarra[i].Group, Sarra[i].Rating);
		if ((i==number/10) || (i==9*number/10)) {
			printf("\n");
		}
    }
    return 0;
}
void alt(Student* Sarra, int*number){
	Student temp;
 for (int i = * number - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
			if((Sarra[j].Rating>Sarra[j+1].Rating)){
						temp = Sarra[j];
						Sarra[j]=Sarra[j+1];
						Sarra[j+1] = temp;
						}
					}
				}
			}

int main(void){
    FILE* input_file;
    Student* Sarra;
    int number = 0;
    char count_temp[512];

    input_file = fopen("77.txt", "r");
    if (!input_file){
        printf("Can not find file\n");
        exit(-1);
    }
    else{
	    while (fgets(count_temp, sizeof(count_temp), input_file) != NULL){
	        number++;
	    }
	    rewind(input_file);

	    Sarra= (Student*)malloc(number*sizeof(Student));
	    Input(Sarra, input_file, number);
	    alt(Sarra, &number);
	    Output(Sarra, number);
	    fclose(input_file);
	    free(Sarra);
		}
    return 0;
}
