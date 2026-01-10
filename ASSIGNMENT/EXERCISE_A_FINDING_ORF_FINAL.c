#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	char seq[ 100000 ];
	int len;
	int i , j;
	int start_codon, stop_codon;
	int first_nucl, last_nucl;
	int seq_dna, seq_rna;

	while(1)
	{
	printf("Enter the sequence: ");
	scanf("%s", seq);
	len = strlen( seq );
	if( len < 6 )
	{
		printf("The sequence is too sort! \n");
		continue;
	}
	seq_dna = 0;
	seq_rna = 0;
	start_codon = 0;
	stop_codon = 0;
	for( i=0 ; i <len; i++)
	{
		if (seq[i] == 'T')
			{
			seq_dna = 1;
			}
		else if (seq[i] == 'U')
			{
			seq_rna = 1;
			}
	}
	if(seq_dna && seq_rna)
		{
		printf("The sequence has T and U nucleotides! \n");
		exit(1);
		}
	if(seq_dna)
	{
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
		printf("DNA sequence found! \n");
		printf("Start codon found at: %d\n", i+1);
		printf("Stop codon found at: %d\n", j+1);
		printf("The ORF sequence is:\n");
		for(i = first_nucl; i <=last_nucl; i++)
			{
			putchar(seq[i]);
			}
		putchar('\n');
		printf("The ORF sequence has lenght:%d nucleotides\n", last_nucl - first_nucl + 1); 
		}
	else
		{
		printf("No valid coding sequence found!\n");
		}
	}
	if(seq_rna)
	{
	for( i=0 ; i < len-5 ; i++ )
	{
		if(seq[ i ] == 'A' && seq[ i+1 ] == 'U' && seq[ i+2 ] == 'G' )
		  {
			start_codon = 1;
			first_nucl = i;

			for( j=i+3 ; j < len-2 ; j+=3)
			{
			     if((seq [ j ] == 'U' && seq [ j+1 ] == 'A' && seq [ j+2 ] == 'A') ||
				(seq [ j ] == 'U' && seq [ j+1 ] == 'A' && seq [ j+2 ] == 'G') ||
				(seq [ j ] == 'U' && seq [ j+1 ] == 'G' && seq [ j+2 ] == 'A')
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
		printf("RNA sequence found! \n");
		printf("Start codon found at: %d\n", i+1);
		printf("Stop codon found at: %d\n", j+1);
		printf("The ORF sequence is:\n");
		for(i = first_nucl; i <=last_nucl; i++)
			{
			putchar(seq[i]);
			}
		putchar('\n');
		printf("The ORF sequence has lenght:%d nucleotides\n", last_nucl - first_nucl + 1);
		}
	else
		{
		printf("No valid coding sequence found!\n");
		}

	return 0;
	}
	}
}