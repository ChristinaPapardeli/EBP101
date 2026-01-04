#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	char seq[ 1000 ];
	int len;
	int i;
	int GC = 0;

	scanf("%s", seq);
	len = strlen( seq );
	printf("The length was : %d \n", len);
	if( len < 0 )
	{
		printf("Eisai boubounas!\n");
		exit(1);
	}
	for( i=0 ; i < len ; i++ )
	{
		if(seq[ i ] == 'G' || seq[ i ] == 'C')
			{
				GC++;
			}

	}
		printf( "The GC content is : %f \n", 100.0 * GC/len);

}
