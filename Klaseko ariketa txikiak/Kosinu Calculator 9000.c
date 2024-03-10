/*
 */

#define PI 3.14159265358979323846
#define AMAITU 0.0005

#include <stdio.h>
#include <stdlib.h>

float degToRad(float _DEG);
float berretura(float _RAD, int _n);
float kalkulua(float _RAD);
int faktoriala(int _n);

int main(int argc, char** argv) {
    printf("#========================KOSINU CALCULATOR 9000========================#\n");
    fflush(stdout);
    
    float angeluaDEG = 0;
    float angeluaRAD = 0;
    float emaitza = 0.0;
    
    printf("\nEman angelua gradutan\n");
    fflush(stdout);
    
    //Windows-erako konpilagailuak kexu ugari ditu __fpurge funtzioaren inguruan.
    //__fpurge(stdin);
    scanf("%f",&angeluaDEG);
    
    angeluaRAD = degToRad(angeluaDEG);
	printf("ANGELUA RADIANETAN:\t%.4f\n", angeluaRAD);
	fflush(stdout);
    
    //printf("\n%f\n",angeluaRAD);
    //fflush(stdout);
    
    emaitza = kalkulua(angeluaRAD);
    //Dekorazio apur bat
    printf("#================================EMAITZA===============================#\n\n cos(%.2f) = %.4f\n\n#======================================================================#\n", angeluaDEG,emaitza);
    
    return (EXIT_SUCCESS);
}

float degToRad(float _DEG){
	
	//Hau guztia lehen bi koadranteetako balioak zuzentzeko da
	int _pisToRemove = 0;
    if(_DEG > 180 || _DEG < -180){
		_pisToRemove = (int)_DEG/180;
		printf("%d PI kendu behar ditugu<\n", _pisToRemove);
		_DEG = _DEG-(_pisToRemove*180);
		if(_pisToRemove%2 != 0){
			_DEG = -_DEG;
		}
	} 
	//
	
	return _DEG * PI /180;
}

float kalkulua(float _RAD){
	
	int zeinua = 1;
	float zenbakitzailea = 0.0;
	int izendatzailea = 0.0;
	float azkenEmaitza = 5;				//AMAITU baino altuagoa den edozein zenbaki balio du aldagai hau deklaratzean. Lehen iterazioan soilik sortuko lituzke arazoak.
	float emaitza = 0.0;
    for(int i = 0; azkenEmaitza > AMAITU; i++){
		
		//Atal positibo edo negatiboa dugun aukeratuko duen atala.
		if(i%2 == 0){
			zeinua = 1;
		}
		else{
			zeinua = -1;
		}
		//
				
		zenbakitzailea = berretura(_RAD, 2*i);
		izendatzailea = faktoriala(2*i);
		azkenEmaitza = (zenbakitzailea/izendatzailea);
				
		emaitza = emaitza + zeinua * azkenEmaitza;
		printf("%f\n", emaitza);
		fflush(stdout);
	}
	printf("\n %.2e Baino txikiagoa den atal batera heldu gara.\nHemendik aurrerako errorea baztergarria da!\n", AMAITU);
	fflush(stdout);
	return(emaitza);
}

//Gogoratu berretzaileak (n) *2 egin behar direla hona bidali baino lehen, emandako taylor seriearen arabera!
float berretura(float _RAD, int _n){
	float emaitza = 1;
	for(int i= 0; i<_n; i++){
		emaitza = emaitza * _RAD;
	}
	return (emaitza);
}

//Gogoratu faktoriala egiteko zenbakiak *2 egin behar direla hona bidali baino lehen, emandako taylor seriearen arabera!
int faktoriala(int _n){
	int emaitza = 1;
	for(int i = _n; i>0; i--){
		emaitza = emaitza * i;
	}
	return(emaitza);
}
