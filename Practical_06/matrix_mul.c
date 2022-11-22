#include <stdio.h>

int main(void)
{
    // dimension of matrices
    int n=5, p=3, q=4;
    double A[n][p], B[p][q], C[n][q];
    int i, j, k;
    
    // computing values for matix A
    for(i=0; i<n; i++) {
        for(j=0; j<p; j++) {
            A[i][j] = i + j;
        }
    }
    
    // computing values for matix B
    for(i=0; i<p; i++) {
        for(j=0; j<q; j++) {
            B[i][j] = i - j;
        }
    }
    
    // initialising matrix C to zero
    for(i=0; i<n; i++) {
        for(j=0; j<q; j++) {
            C[i][j] = 0.0;
        }
    }
    
    // matrix multiplication C = AB
    for(i=0; i<n; i++) {
        for(j=0; j<q; j++) {
            for(k=0; k<p; k++){
               C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    // printing the matrix 
    // matrix A
    printf("Matrix A: \n");
    for(i=0; i<n; i++) {
        for(j=0; j<p; j++) {
            printf("%3.0f ", A[i][j]);
        }
        printf("\n");
    }
    
    // matrix B
    printf("Matrix B: \n");
    for(i=0; i<p; i++) {
        for(j=0; j<q; j++) {
            printf("%3.0f ", B[i][j]);
        }
        printf("\n");
    }
    
    // matrix C
    printf("Matrix C: \n");
    for(i=0; i<n; i++) {
        for(j=0; j<q; j++) {
            printf("%3.0f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

