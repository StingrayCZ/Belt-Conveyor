#include <stdio.h>
#include <stdlib.h>

#include "Header.h"

    /*
    ---------------------
    -------Legenda-------
    ---------------------
    L     - Osova vzdalenost bubnu (mm)
    S     - Sirka pasu (mm)
    alpha - Sklon dopravniku (°)
    mZ    - Max. hmotnost nakladu (kg/m)
    km    - Koeficient pretizeni (-)
    v     - Rychlost posuvu (m/min)
    d     - Prumer bubnu (mm)
    ------------------------------------

    ---------------------
    -------Vystupy-------
    ---------------------
    nB     - Otacky bubnu (1/min)
    iP     - Prevodovy pomer (-)
    nM     - Hmotnost nakladu (kg)
    mP     - Hmotnost pasu (kg)
    OC     - Celkovy odpor (N)
    OCr    - Celkovy odpor (zaokrouhlene) (N)
    M      - Vypocet momentu na hnacim bubnu (N*m)
    M      - Vypocet momentu na hnacim bubnu (zaokrouhlene) (N*m)
    Pc      - Vykon potrebny pro pohyb dopravniku (W)
    Pm      - Vykon pro rozjezd (W)

    ------------------------------------
    */

//---------------
// Variables
//---------------
float L, S, alpha, mZ, km, v, d, mspec, nm; // Inputs
float nB, iP, mN, mP, OC, OCr, M, Mr, Pc, Pm; // Outputs

//---------------
// Tech Variables
//---------------
//char MON;
int MENIC;

//---------------
// MAIN
//---------------
int main()
{


    #ifdef ZADAVACI

    float cargo[7];

    EnterValue(cargo, &MENIC);

    L = cargo[0];
    S = cargo[1];
    alpha = cargo[2];
    mZ = cargo[3];
    km = cargo[4];
    v = cargo[5];
    d = cargo[6];
    mspec = cargo[7];
    nm = cargo[8];

    #endif // ZADAVACI

    #ifdef TESTOVACI

    L = 3500;
    S = 1100;
    alpha = 90;
    mZ = 5;
    km = 1.5;
    v = 8;
    d = 63;
    mspec = 5;
    nm = 1400;

    #endif // TESTOVACI

    printf("************************************\n");
    printf("********** ZADANE HODNOTY *********\n");
    printf("************************************\n");

    printf("Osova vzdalenost bubnu, L = %.2f mm \n", L);
    printf("Sirka pasu, S = %.2f mm \n", S);

    // SKLON DOPRAVNIKU
    if(alpha == 0){

        printf("Dopravnik je v rovinne poloze. Nulovy uhel sklonu. \n");
    }

    else if(alpha == 90){

        printf("Dopravnik miri stremhlav, sklon dopravniku je 90%c. \n", DEGREE);
    }

    else{
        printf("Sklon dopravniku, alfa = %.0f%c \n", alpha, DEGREE);
    }



    printf("Max. hmotnost nakladu, mZ = %.2f kg/m \n", mZ);
    printf("Koeficient pretizeni, km = %.2f \n", km);
    printf("Rychlost posuvu, v = %.2f m/min (%.2f m/s) \n", v, (v / 60));
    printf("Prumer bubnu, d = %.2f mm \n", d);
    printf("Merna hmotnost pasu, mspec = %.2f kg/m2 \n", mspec);

    if(MENIC == 1){
        printf("Otacky elektromotoru bez menice, nm = %.0f ot/min \n", nm);
    }


    else if(MENIC == 2){
            printf("Otacky elektromotoru (zadane), %.0f ot/min \n", nm*2);
            printf("Menicem redukovane otacky elektromotoru, nm = %.0f ot/min \n", nm);
    }




    JUMP
    printf("Doplnujici hodnoty (pevne zadane): \n");
    printf("Gravitacni zrychleni, g = %.2f (m/s) \n", (float)GFORCE);
    printf("Soucinitel treni [pas/kluzna deska], f = %.1f (-) \n", (float)FRIC);
    printf("Koeficient pro rozjezd, kr = %.1f (-) \n", (float)KR);

    JUMP

    // VYPOCET
    FormulaA(&v, &d, &nB);

    FormulaB(&nm, &nB, &iP);

    FormulaC(&mZ, &L, &km, &mN);

    FormulaD(&L, &S, &mspec, &mP);

    FormulaE(&mN, &mP, &alpha, &OC);

    RoundAppA(&OC, &OCr);

    FormulaF(&OCr, &d, &M);

    RoundAppB(&M, &Mr);

    FormulaG(&Mr, &nB, &Pc);

    FormulaH(&Pc, &Pm);


    // VYSLEDKY
    JUMP
    printf("************************************\n");
    printf("********* VYSLEDNE HODNOTY *********\n");
    printf("************************************\n");

    printf("Otacky hnaciho bubnu nB = %.1f ot/min \n", nB);
    printf("Prevodovy pomer prevodovky iP = %.1f (-) \n", iP);
    printf("Hmotnost nakladu mN = %.2f kg \n", mN);
    printf("Hmotnost pasu mP = %.2f kg \n", mP);
    printf("Celkovy odpor OC = %.2f = %.0f N \n",OC, OCr);
    printf("Moment na hnacim bubnu M = %.2f = %.1f N*m \n", M, Mr);
    printf("Vykon potrebny pro pohyb dopravniku P' = %.0f W \n", Pc);
    printf("Vykon  pro rozjezd P = %.0f W \n", Pm);

    JUMP
    JUMP

//    Month(&MON);
//
//    printf("Mesic je %s \n", MON);

    // Make a file

    FILE * fPointer;

    fPointer = fopen("Report - Belt Conveyor.txt", "w");

    fprintf(fPointer, "************************************\n");
    fprintf(fPointer, "********** ZADANE HODNOTY *********\n");
    fprintf(fPointer, "************************************\n");

    fprintf(fPointer, "\n");
    fprintf(fPointer, "Osova vzdalenost bubnu, L = %.2f mm \n", L);
    fprintf(fPointer, "Sirka pasu, S = %.2f mm \n", S);


    // SKLON DOPRAVNIKU
    if(alpha == 0){

        fprintf(fPointer, "Dopravnik je v rovinne poloze. Nulovy uhel sklonu. \n");
    }

    else if(alpha == 90){

        fprintf(fPointer, "Dopravnik miri stremhlav, sklon dopravniku je 90%c. \n", DEGREE);
    }

    else{
        fprintf(fPointer, "Sklon dopravniku, alfa = %.0f° \n", alpha);
    }

    fprintf(fPointer, "Max. hmotnost nakladu, mZ = %.2f kg/m \n", mZ);
    fprintf(fPointer, "Koeficient pretizeni, km = %.2f \n", km);
    fprintf(fPointer, "Rychlost posuvu, v = %.2f m/min (%.2f m/s) \n", v, (v / 60));
    fprintf(fPointer, "Prumer bubnu, d = %.2f mm \n", d);
    fprintf(fPointer, "Merna hmotnost pasu, mspec = %.2f kg/m2 \n", mspec);


    if(MENIC == 1){
        fprintf(fPointer, "Otacky elektromotoru bez menice, nm = %.0f ot/min \n", nm);
    }


    else{
        fprintf(fPointer, "Otacky elektromotoru (zadane), %.0f ot/min \n", nm*2);
        fprintf(fPointer, "Menicem redukovane otacky elektromotoru, nm = %.0f ot/min \n", nm);
    }


    fprintf(fPointer, "\n");
    fprintf(fPointer, "Doplnujici hodnoty (pevne zadane): \n");
    fprintf(fPointer, "Gravitacni zrychleni, g = %.2f (m/s) \n", (float)GFORCE);
    fprintf(fPointer, "Soucinitel treni [pas/kluzna deska], f = %.1f (-) \n", (float)FRIC);
    fprintf(fPointer, "Koeficient pro rozjezd, kr = %.1f (-) \n", (float)KR);

    fprintf(fPointer, "\n");
    fprintf(fPointer, "\n");

    fprintf(fPointer, "************************************\n");
    fprintf(fPointer, "********* VYSLEDNE HODNOTY *********\n");
    fprintf(fPointer, "************************************\n");

    fprintf(fPointer, "\n");
    fprintf(fPointer, "Otacky hnaciho bubnu nB = %.1f ot/min \n", nB);
    fprintf(fPointer, "Prevodovy pomer prevodovky iP = %.1f (-) \n", iP);
    fprintf(fPointer, "Hmotnost nakladu mN = %.2f kg \n", mN);
    fprintf(fPointer, "Hmotnost pasu mP = %.2f kg \n", mP);
    fprintf(fPointer, "Celkovy odpor OC = %.2f = %.0f N \n",OC, OCr);
    fprintf(fPointer, "Moment na hnacim bubnu M = %.2f = %.1f N*m \n", M, Mr);
    fprintf(fPointer, "Vykon potrebny pro pohyb dopravniku P' = %.0f W \n", Pc);
    fprintf(fPointer, "Vykon  pro rozjezd P = %.0f W \n", Pm);

    fclose(fPointer);

    system("pause");


    return 0;
}
