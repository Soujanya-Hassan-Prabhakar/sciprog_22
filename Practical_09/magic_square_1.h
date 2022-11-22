// defining function for MagicSquare
int isMagicSquare(int **square, const int n) {
    // n cannot be a negative integer
    if(n < 0) return 0;
    
    // declarating variables 
    int magic_num = 0;
    int off_diag_sum = 0;
    int i,j;
    
    // checking off_diag_sum is equal to magic_num
    for(i=0; i<n; i++) {
        // sum of diagonal elements
        magic_num += square[i][i];
        // sum of non-diagonal elements
        off_diag_sum += square[i][n-i-1];
    }
    if(off_diag_sum != magic_num) {
	printf("off_diag_sum: %d and magic_num: %d\n", off_diag_sum, magic_num);
	return 0;
    }
    
    // checking row_sum & column_sum is equal to magic_num
    int row_sum = 0;
    int column_sum = 0;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            row_sum += square[i][j];
            column_sum += square[j][i];
        }
        if((row_sum != magic_num) || (column_sum != magic_num)) {
	   printf("row_sum: %d and column_sum: %d\n",row_sum, column_sum);
	   return 0;
	}
    }

    // return 1 for magic square
    return 1;
}
