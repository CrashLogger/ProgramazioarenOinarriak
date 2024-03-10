/*
 * Diru kantitatea billete eta txanponetan bihurtu
 */


#include <stdio.h>

int main()
{	
	float diruKop = 0.0;
	int zentimoKop = 0;
	
	printf("Sartu zure diru kantitatea: \n");
	fflush(stdout);
	
	__fpurge(stdin);
	scanf("%f", &diruKop);
	
	zentimoKop = diruKop*100;
	
	//printf("\n Zure dirua: %.2f da", (float)zentimoKop/100);
	
	//500€ billeteak
	int E500Kop = zentimoKop/50000;
	zentimoKop = zentimoKop%50000;
	
	//200€ billeteak
	int E200Kop = zentimoKop/20000;
	zentimoKop = zentimoKop%20000;
	
	//100€ billeteak
	int E100Kop = zentimoKop/10000;
	zentimoKop = zentimoKop%10000;
	
	//50€ billeteak
	int E050Kop = zentimoKop/5000;
	zentimoKop = zentimoKop%5000;
	
	//20€ billeteak
	int E020Kop = zentimoKop/2000;
	zentimoKop = zentimoKop%2000;
	
	//10€ billeteak
	int E010Kop = zentimoKop/1000;
	zentimoKop = zentimoKop%1000;
	
	//5€ billeteak
	int E005Kop = zentimoKop/500;
	zentimoKop = zentimoKop%500;
	
	//2€ Txanponak
	int Z200Kop = zentimoKop/200;
	zentimoKop = zentimoKop%200;
	
	//1€ Txanponak
	int Z100Kop = zentimoKop/100;
	zentimoKop = zentimoKop%100;
	
	//0.5€ Txanponak
	int Z050Kop = zentimoKop/50;
	zentimoKop = zentimoKop%50;
	
	//0.2€ Txanponak
	int Z020Kop = zentimoKop/20;
	zentimoKop = zentimoKop%20;
	
	//0.1€ Txanponak
	int Z010Kop = zentimoKop/10;
	zentimoKop = zentimoKop%10;
	
	//0.05€ Txanponak
	int Z005Kop = zentimoKop/5;
	zentimoKop = zentimoKop%5;
	
	//0.02€ Txanponak
	int Z002Kop = zentimoKop/2;
	zentimoKop = zentimoKop%2;
	
	//0.1€ Txanponak
	int Z001Kop = zentimoKop;
	
	// Billeteak inprimatzen lehenik
	printf("\n Zure %.2f hurrengo eran banatu daiteke:\n %6d x500€ \t %6d x200€ \t %6d x100€ \n %6d x 50€ \t %6d x 20€ \t %6d x 10€ \t %6d x 5€ " , diruKop, E500Kop, E200Kop, E100Kop, E050Kop, E020Kop, E010Kop, E005Kop);
	fflush(stdout);
	// Txanponak inprimatzen orain
	printf("\n %6d x  2€ \t %6d x  1€ \t %6d x50c \t %6d x20c \n %6d x10c \t %6d x 5c \t %6d x 2c \t %6d x 1c\n\n", Z200Kop, Z100Kop, Z050Kop, Z020Kop, Z010Kop, Z005Kop, Z002Kop, Z001Kop);
	fflush(stdout);
	
	return 0;
}
