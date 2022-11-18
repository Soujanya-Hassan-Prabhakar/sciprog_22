#include<stdio.h> 
#include<math.h> 

// declaring functions:
// function to convert the value from degree to rad
float deg_to_rad(float deg);
// function to evaluate the value of integral
float trap_rule(float a, float b, int N, float function_array[N+1]);
    
int main (void){
    
    // range of definite integral
    float start = 0, end = 60; 
    // number of grids. Higher value means more accuracy
    int N=12;
    // grid spacing
    float step_size = (end-start)/N;
    // storing tan values in array
    float tan_arr[N+1];
    
    // loop counter to generate degree angles
    int i=0;
    for (i=0; i<=N; i++){
        tan_arr[i] = tan(deg_to_rad(step_size * i));
    } 
    
    // calling the functions
    float result = trap_rule(deg_to_rad(start), deg_to_rad(end), N, tan_arr);
    
    printf("The approximated value is: %f\n", result);
    printf("The actual value is: %f\n", logf(2));
    
    return 0;
}

// defining degree to radian function
float deg_to_rad(float deg) {
    return ((M_PI*deg)/180.0);
}

// defining Trapezoidal rule function
float trap_rule(float a, float b, int N, float function_array[N+1]) {
    float sum;
    int i;
    
    // computing sum of first and last terms
    sum = function_array[0] + function_array[N];
    
    // adding middle terms
    for(i=1; i<N; i++) {
        sum += 2*function_array[i];
    }
    
    // multiplying whole sum by (b-a)/2N
    return (b-a)*(sum) / (2*N);
}
