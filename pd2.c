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
	if(seq[ len-3 ] == 'T' &&
	   seq[ len-2 ] == 'A' &&
	   seq[ len-1 ] == 'A' )
		{
		printf( "Last plate is TAA!\n" );
		}
	else
		{
		printf("Last plate is _not_ TAA!\n");
		}

}
