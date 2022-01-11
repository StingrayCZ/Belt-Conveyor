#include <stdio.h>
#include <stdlib.h>

#include "Header.h"


void EnterValue(float array[], int *MENIC, float *cosVal)
{
    // Variables
    float L, S, alpha, mZ, km, v, d, mspec, nm;

    // Tech Variables
    int menic;

    /*
    ---------------------
    -------Legenda-------
    ---------------------
    L     - Osova vzdalenost bubnu (mm)
    S     - Sirka pasu (mm)
    alpha - Sklon dopravniku (°0)
    mZ    - Max. hmotnost nakladu (kg/m)
    km    - Koeficient pretizeni (-)
    v     - Rychlost posuvu (m/min)
    d     - Prumer bubnu (mm)
    mspec - Merna hmotnost pasu (kg/m2)
    nm    - Otacky elektromotoru (ot/min)
    ------------------------------------
    */

    // Tech Variables
    int grade, i;



    for(i = 1; i <= 9; i++)
    {

        grade = i;


        switch(grade)
        {

        case 1 : // Osova vzdalenost bubnu (mm)
            printf("Osova vzdalenost bubnu L = ? (mm)\n");
            scanf("%f", &L);
            system("cls");
            break;

        case 2 : //Sirka pasu (mm)
            printf("Sirka pasu = ? (mm) \n");
            scanf("%f", &S);
            system("cls");
            break;

        case 3 : //Sirka pasu (mm)
            printf("Uhel sklonu doravniku = ? (stupnu) \n");

            EnterAngle(&alpha, &(*cosVal));

            system("cls");
            break;

        case 4 : // Max. zatizeni dopravniku (kg/m)
            printf("Max. zatizeni dopravniku = ? (kg/m) \n");
            scanf("%f", &mZ);
            system("cls");
            break;

        case 5 : // Koeficient pretizeni (-)
            printf("Koeficient pretizeni = ? (-) \n");
            scanf("%f", &km);
            system("cls");
            break;

        case 6 : // Rychlost posuvu (m/min)
            UnitSelection(&v);
            break;

        case 7 : // Prumer bubnu (mm)
            printf("Prumer bubnu = ? (mm) \n");
            scanf("%f", &d);
            system("cls");
            break;

        case 8 : // Merna hmotnost pasu (kg/m2)
            printf("Merna hmotnost pasu = ? (kg/m2) \n");
            scanf("%f", &mspec);
            system("cls");
            break;

        case 9 : // Otacky elektromotoru (kg/m2)



            printf("Otacky elektromotoru = ? (ot/min) \n");
            scanf("%f", &nm);
            system("cls");

            FrequencChanger(&menic);

            if(menic == 1){

//                printf("Byl zvolen motor bez menice \n");
//                printf("Otacky elektromotoru = ? (ot/min) \n");
//                scanf("%f", &nm);
//                system("cls");

                *MENIC = menic;
            }

            else if(menic == 2){

//                printf("Byl zvolen motor s menicem \n");
//                printf("Otacky elektromotoru = ? (ot/min) \n");
//                scanf("%f", &nm);

                nm /= 2;

//                system("cls");

                *MENIC = menic;
            }

            break;

        }
    }

    system("cls");

    // Insert all values to array
    array[0] = L;
    array[1] = S;
    array[2] = alpha;
    array[3] = mZ;
    array[4] = km;
    array[5] = v;
    array[6] = d;
    array[7] = mspec;
    array[8] = nm;



    #ifdef PRINTEXEPT

    printf("**************************************\n");
    printf("********** Zadane Honoty *************\n");
    printf("**************************************\n");

    printf("Osova vzdalenost bubnu, L = %.2f mm \n", L);
    printf("Sirka pasu, S = %.2f mm \n", S);
    printf("Sklon dopravniku, alpha = %.2f %c \n", alpha, DEGREE);
    printf("Max. hmotnost nakladu, mZ = %.2f kg/m \n", mZ);
    printf("Koeficient pretizeni, km = %.2f \n", mZ);
    printf("Rychlost posuvu, v = %.2f m/min \n", v);
    printf("Prumer bubnu, d = %.2f mm \n", d);
    printf("Merna hmotnost pasu, mspec = %.2f kg/m2 \n", mspec);
    printf("Otacky elektromotoru, nm = %.2f ot/min \n", nm);

    #endif // PRINTEXEPT

}


void UnitSelection(float *v)
{

    int hodnota, TEST;
    float rychlost;

    do{
            printf("Rychlost posuvu, vyber jednotku stiskem cislice: \n");
            printf("------------------------------------------------ \n");
            printf("metr za minutu stiskni....... 1 \n");
            printf("metr za sekundu stiskni...... 2 \n");
            printf("milimetr za minutu stiskni... 3 \n");
            scanf("%d", &hodnota);
            system("cls");

    if(hodnota == 1){

            printf("Rychlost posuvu = ? (m/min) \n");
            scanf("%f", &rychlost);
            system("cls");

            *v = rychlost;

            TEST = 0;
    }

    else if(hodnota == 2){

            printf("Rychlost posuvu = ? (m/s) \n");
            scanf("%f", &rychlost);
            system("cls");

            *v = rychlost * 60;

            TEST = 0;
    }

        else if(hodnota == 3){

            printf("Rychlost posuvu = ? (mm/min) \n");
            scanf("%f", &rychlost);
            system("cls");

            *v = rychlost / 1000;

            TEST = 0;
    }

    else{

        JUMP
        printf("****** Klikas vedle, proved vyber znovu! ******\n");
        JUMP

        TEST = 1;
    }

    }while(TEST != 0);

}


void FrequencChanger(int *FCval){

    int hodnota, TEST;

    printf("Je pouzit frekvencni menic? \n");
    do{

            printf("ANO - stiskni 1: \n");
            printf("NE  - stiskni 2: \n");
            scanf("%d", &hodnota);
            system("cls");

            if(hodnota == 1){

                    *FCval = 2;

                    TEST = 0;
            }

            else if(hodnota == 2){

                    *FCval = 1;

                    TEST = 0;
            }

            else{

                    JUMP
                    printf("****** Spatny vyber ******\n");
                    JUMP
                    TEST = 1;
    }


    }while(TEST != 0);

}

void EnterAngle(float *angle, float *cosValue){

    int TEST;

    do{
       scanf("%f", &(*angle));

       if((*angle) >= 0 && (*angle) <= 89)TEST = 0;



       else if((*angle) == 90) TEST = 0;


       else{
            printf("****** Spatny vyber ****** \n");
            printf("Zvol cisla z intervalu 0-90%c \n", DEGREE);
            TEST = 1;
            }

       }while(TEST != 0);

}
