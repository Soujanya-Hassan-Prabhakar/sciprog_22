#include <stdio.h>
#include <stdlib.h>
#include "magic_square.h"
#define MAX_FILE_NAME 100

int get_num_lines(char filename[MAX_FILE_NAME]) {
    FILE *fp;
    // open the file
    fp = fopen(filename,"r"); 
    
    int ch_read;
    int count = 0;
    
    // read the number of lines
    while((ch_read = fgetc(fp)) != EOF) { // EOF when we are done reading
        if (ch_read == '\n') {
            count++;
        }
    }
    
	printf("Number of lines is %d\n", count);
	fclose(fp);
	return count;
}

int main(void)
{
    FILE *f;
    char filename[MAX_FILE_NAME];
	printf("Enter the file name please: \n");
	scanf("%s", filename);
	
	// get number of lines
	int n = get_num_lines(filename);
	
	// open the file
	f = fopen(filename,"r");
    
    int i;
    // allocating the memory for the matrix
	int **magicsquare = malloc(n * sizeof(int *));
	for(i=0; i<n; i++) {
	    magicsquare[i] = malloc(n * sizeof(int *));
	}
	
	int j;
	// reading the matrix in from file
	for(i=0; i<n; i++) {
	    for(j=0; j<n; j++) {
	        fscanf(f, "%d", &magicsquare[i][j]);
	    }
	}

    // checking if my matix is a MagicSquare
    int flag = isMagicSquare(magicsquare, n);
    if(flag == 1) printf("This square is MagicSquare!\n");
    else printf("This square is not MagicSquare!\n");
    
    // deallocating the memory
    for (i=0; i<n; i++) {
        free(magicsquare[i]);
    }
    free(magicsquare);
    
    // closing the file
    fclose(f);
    
    return 0;
}
