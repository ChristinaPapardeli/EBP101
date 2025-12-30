#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	char seq[ 1000 ];
	int len;
	int i;
	int charge = 0;

	scanf("%s", seq);
	len = strlen( seq );
	if( len < 3 )
	{
		printf("Eisai boubounas!\n");
		exit(1);
	}
	if(seq[ 0   ] == 'A' &&
	   seq[ 1 ] == 'T' &&
	   seq[ 2 ] == 'C' )
		{
		printf( "ATC present!\n" );
		}
	else
		{
		printf("ATC _not_ present!\n");
		}

}
