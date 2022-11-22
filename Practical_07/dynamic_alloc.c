#include <stdio.h>
#include <stdlib.h>

// defining the functions 
// allocate the array
int *allocate_array(int n){
    int *p;
    p = (int *) malloc((n)*sizeof(int));
    if(p == NULL) printf("Error in allocating memory\n");
    return p;
}

// fill with ones
void fill_with_ones(int *array, int n){
    int i;   // loop indices
    for(i=0; i<n; i++) {

        array[i] = 1;
    }
}

// print the array
void print_array(int *array, int n){
    int i;   // loop indices
    for(i=0; i<n; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

// deallocate the array
void free_array(int *array){
    free(array);
}

int main()
{
    int n, *a;
    
    // entering length of the array
    printf("Enter the size of the array: \n");
    scanf("%d", &n);
    
    // calling the functions
    a = allocate_array(n);
    fill_with_ones(a, n);
    print_array(a, n);
    free_array(a);

    return 0;
}

