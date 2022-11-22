// defining the function that is called in main.c

void mat_mul(int n, int p, int q, double A[n][p], double B[p][q], double C[n][q])
{
    int i, j, k;	// looping indices
    
    // matrix multiplication C = AB
    for(i=0; i<n; i++) {
        for(j=0; j<q; j++) {
            for(k=0; k<p; k++){
               C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
