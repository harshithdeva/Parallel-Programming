#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 1000000
void parpi()
{
    double factor = 1.0, sum = 0.0;
    int i;
    double start,stop;
    start=omp_get_wtime();
#pragma omp parallel for reduction(+ : sum) // private(factor)
    for (int i = 0; i < N; i++)
    {
        factor = (i % 2 == 0) ? 1 : -1;
        sum += factor / (2 * i + 1);
    }
    stop=omp_get_wtime();
    double pi;
    pi = 4 * sum;
    printf("pi= %1.18f", pi);
    printf("\nParallel time: %f\n", stop - start);

}
void serpi()
{
    double factor = 1.0, sum = 0.0;
    int i;
    double start,stop;
    start=omp_get_wtime();
//#pragma omp parallel for reduction(+ : sum) // private(factor)
    for (int i = 0; i < N; i++)
    {
        factor = (i % 2 == 0) ? 1 : -1;
        sum += factor / (2 * i + 1);
    }
    stop=omp_get_wtime();
    double pi;
    pi = 4 * sum;
    printf("pi= %1.18f", pi);
    printf("\nSerial time: %f\n", stop - start);

}

void main()
{
    serpi();
    parpi();
}