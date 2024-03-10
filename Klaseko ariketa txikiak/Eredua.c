/*
 * Eredua.c
 * 
 * Copyright 2022 Erlantz "CrashLogger" Alonso <erlantz.alonso@live.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
// KOnstanteetarako baliagarria baina ez beharrezkoa:
#define PI 3.1415
#define URTE_LUZEERA 365

char karak = 'B';
int adina = 19;

float zenbakifroga = 25.428732;

char newLine = '\n';
char tab = '\t';

int main()
{
	printf("Hello World! \n%c, %4d \n", karak, adina);
	// Lehenengoak 8 atal hartuko ditu, baina bakarrik dezimal bat.
	// Bigarren zenbakiak 3 hartuko ditu, bi dezimalak izanda.
	printf("%8.1f \t \t %3.2f\n", zenbakifroga, PI);
	// & Erabiliz lor daiteke aldagai baten helbidea memorian.
	printf("Mesedez sartu zure adina urteetan:\n\n");
	scanf("%d", &adina);
	
	printf("%d \n %d egunez bizi izan zara! Woah!", adina,URTE_LUZEERA*adina);
	return(0);
}
