
#include <stdio.h>

int main()
{
	int lerro, zutabe;
	int tamaina = 8;
	
	for(lerro = 1; lerro <= tamaina; lerro++)
	{
		for(zutabe = 1; zutabe <= lerro; zutabe++)
		{
			printf("*");
			fflush(stdout);	
		}
		printf("\n");
		fflush(stdout);	
	}
	
	return 0;
}

