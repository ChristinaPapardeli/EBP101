#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	char seq[ 100000 ];
	int len;
	int i , j;
	int start_codon = 0;
	int stop_codon = 0;
	int first_nucl = 0;
	int last_nucl = 0;


	printf("Enter the sequence: ");
	scanf("%s", seq);
	len = strlen( seq );
	if( len < 6 )
	{
		printf("Eisai boubounas!\n");
		exit(1);
	}
        for( i=0 ; i < len-5 ; i++ )
	{
		if(seq[ i ] == 'A' && seq[ i+1 ] == 'T' && seq[ i+2 ] == 'G' )
		  {
			start_codon = 1;
			first_nucl = i;

			for( j=i+3 ; j < len-2 ; j+=3)
			{
			     if((seq [ j ] == 'T' && seq [ j+1 ] == 'A' && seq [ j+2 ] == 'A') ||
				(seq [ j ] == 'T' && seq [ j+1 ] == 'A' && seq [ j+2 ] == 'G') ||
				(seq [ j ] == 'T' && seq [ j+1 ] == 'G' && seq [ j+2 ] == 'A')
			       )
				{
				stop_codon = 1;
				last_nucl = j + 2;
				break;
				}
			}

			break;
		  }

	}
	if( start_codon == 1 && stop_codon == 1 )
		{
		printf("The ORF found:\n");
		for(i = first_nucl; i <=last_nucl; i++)
			{
			putchar(seq[i]);
			}
		putchar('\n');
		}
	else
		{
		printf("No valid coding sequence found!\n");
		}

	return 0;

}