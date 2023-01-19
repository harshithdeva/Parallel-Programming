#include<stdio.h>
#include<stdlib.h>
#include<omp.h>


void main(){
    int n =100;
    int sum = 0; // global so should use critical while updating
    double start= omp_get_wtime();
    #pragma omp parallel for
    for(int i=1;i<=n;i++){
        #pragma omp critical
        sum+=i;
    }
    double stop= omp_get_wtime();
    printf("Sum is %d\n",sum);
    printf("Parallel time is %f\n",stop-start);
}