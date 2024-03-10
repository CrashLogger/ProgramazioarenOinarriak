#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int lortuUrtea(void);
int lortuHilabetea(void);
int lortuEguna(void);

int main(int argc, char** argv) {
    
    int imprimUrtea = lortuUrtea();
    int imprimHilabetea = lortuHilabetea();
    int imprimEguna = lortuEguna();
    printf("%2d/%2d/%2d", imprimUrtea, imprimHilabetea, imprimEguna);
    fflush(stdout);

    return (EXIT_SUCCESS);
}

int lortuUrtea(){
    int urtea = 0;
    do{
        printf("Urtea aukeratu:\n");
        fflush(stdout);
    
        __fpurge(stdin);
        scanf("%d", &urtea);
    }
    while(urtea > 99 || urtea < 0);
    
    return urtea;
}

int lortuHilabetea(){
    int hilabetea = 0;
    do{
        printf("Hilabetea aukeratu:\n");
        fflush(stdout);
    
        __fpurge(stdin);
        scanf("%d", &hilabetea);
    }
    while((hilabetea > 12) || (hilabetea < 0));
        
    return (hilabetea);
}

int lortuEguna(){
    int eguna = 0;
    do{
        printf("Eguna aukeratu:\n");
        fflush(stdout);
    
        __fpurge(stdin);
        scanf("%d", &eguna);
    }
    //Bisiestoak eta abar paso
    while((eguna > 31) || (eguna < 0));
    return (eguna);
}