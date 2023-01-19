#include <stdio.h>
#include "mpi.h"
int main(int argc, char **argv)
{
    int rank, size, i, n, lm, j, mod;
    int fact, rslt = 1;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int unused; // attribute ((unused));
    if (rank == 0)
    {
        printf(" Enter the number to find the factorial \n ");
        unused = scanf("%d", &n);
    }
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    lm = n / size;
    mod = n % size;
    for (i = rank * lm + 1; i <= rank * lm + lm; i++)
    {
        rslt = rslt * i;
        printf(" The multiplication from %d is %d\n", rank + 1, rslt);
    }

    if (mod != 0)
    {
        if (rank == size - 1)
        {
            for (j = i; j <= (rank + 1) * lm + mod; j++)
            {
                rslt = rslt * j;
                printf(" The multiplication from %d is %d\n", rank + 1, rslt);
            }
        }
    }
    MPI_Reduce(&rslt, &fact, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
    if (rank == 0)
    {
        printf("\nThe factorial of the Given number %d is %d \n", n, fact);
    }
    MPI_Finalize();
    return 0;
}