# Belt Conveyor

```C
#include <stdio.h>
#include <stdlib.h>


struct Student{
char name[50];    // max capacity 50 char
char major[50];
int age;
double gpa;

};

int main()
{
    for(int i = 1; i <= 9; i++){
            printf("Poradi %d \n", i);
    }

    int tt = 10;

    int g = 0;

    // ***********************************
    // While
    while(g <= tt){

        printf("Poradi B: %d \n",g);
        g++;
    }


    do{
        printf("Porad C: %d \n",g);
        g++;

    }while(g <= tt);

    printf("Hello world!\n");


    // ***********************************
    // Switch Statements

    char grade = 'C';

    switch(grade){
    case 'A':
        printf("You did great");
        break;

    case 'B':
        printf("You did alright");
        break;

    case 'C':
        printf("You did poorly");
        break;

    case 'D':
        printf("You did bad");
        break;

    case 'F':
        printf("You did Failed");
        break;

    default:
        printf("Invalid Game");
    }

    // ***********************************
    // Struct


    struct Student student1;
    student1.age = 22;
    student1.gpa = 3.2;
    strcpy(student1.name, "Jim");
    strcpy(student1.name, "Business");

    printf("%f", student1.gpa);


    return 0;
}

```
