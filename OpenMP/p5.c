#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define x 20

int isPrime(int n){
  if(n == 0 || n == 1){
    return 0;
  }
  for(int i = 2; i <= n/2; i++){
    if(n%i == 0){
      return 0;
    }
  }
  return 1;
}

int main(){

  
  double start = omp_get_wtime();
  #pragma omp parallel for
  for(int i = 1; i <= x;i++){
    if(isPrime(i)){
      //int t = omp_get_thread_num();
      printf("%d \n",i);
    }
  }
  double end = omp_get_wtime();
  printf("The Parallel time taken is %lf ",end - start);

  start = omp_get_wtime();
  for(int i = 1; i <= x;i++){
    if(isPrime(i)){
      //int t = omp_get_thread_num();
      printf("\n%d \n",i);
    }
  }
  end = omp_get_wtime();
  printf("The Serial time taken is %lf ",end - start);

}