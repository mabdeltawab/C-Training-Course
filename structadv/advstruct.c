# include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void getString(FILE* f1, char *temp1);
char readChar(FILE*);
int main (void)
{
    typedef struct
    {
        char name[31];
        int age;
        char gender;
    }Studen;

    Studen lib[20];
    int n =0;
    char temp[31];
    FILE *in = fopen("list.txt","r");
    if(in == NULL)
    {
        printf("Unable to open the file");
        exit(0);
    }
    getString(in, temp);
    while (strcmp(temp, "END") != 0)
        {
            strcpy(lib[n].name, temp);
            fscanf(in, "%d", &lib[n].age);
            lib[n].gender = readChar(in);//fgetc(in);//
           // lib[n].gender = fgetc(in);//readChar(in);
            n++;
            getString(in, temp);
        }
        fclose(in);
        printf("can I terminate? Y/N\n");
        char res;
        scanf(&res);
        return(0);
}
/*
void getString(FILE* f1, char *temp1)
{
        char c;
        char brk = '0';
    int index = 0;
    while((index<= 30) && ((c) != ','))
    {
            *temp1 = fgetc(f1);
            c = *temp1;/// temporary variable just for debuging watch
            if(*temp1 != '\n')
            {
                temp1++;
                index++;
            }
            if (index == 3 && *(temp1-3)=='E'&& *(temp1-2)=='N'&& *(temp1-1)=='D')/// check for END word
            {
                brk= '1';
                break;
            }
     }
        *temp1 ='\0';
    while (index <=30 && brk=='0')
    {
        index++;
        temp1++;
        *temp1 ='2';
    }
}*/


void getString(FILE* f1, char *temp1)
{
        char c;
        char brk = '0';
    int index = 0;
    char delima;


    while(isspace(*temp1=fgetc(f1)));

    if(*temp1 =='EOF')   exit(0);
    delima = *temp1;
    while(((c=fgetc(f1)) !=delima)&& c !='EOF')
    {
        *temp1++ = c;

    }
}


char readChar(FILE* f2)
{
    char c;
    do
    {
    c = fgetc(f2);

    }
     while(!isalpha(c));
        return c;
}
