 
#include <stdio.h>
#include <math.h>
#include <pthread.h>

void *primeCalc() 
{
    int n = 0;
    for (int i = 2; i < 1000000; i++) 
    {
      int isPrime = 1;
      for (int j = 2; j < sqrt(i); j++)
        if (i % j == 0) 
        {
            isPrime = 0;
            break;
        }
      if (isPrime == 1)  printf("Prime number %d: %d\n",n++,i);
    }
}
void *fiboCalc()
{
  printf("Fibo number 1:1\n");
  printf("Fibo number 2:1\n");
  int first = 2, sec = 3, n = 3;
  while (first < 1000000 && sec < 1000000)
  {
      printf("Fibo number %d:%d\n", n++,first);
      printf("Fibo number %d:%d\n", n++,sec);
      first += sec;
      sec += first;
  }

}

int main()
{
    pthread_t prime_t, fibo_t;
    pthread_create(&prime_t, NULL, primeCalc, NULL);
    pthread_create(&fibo_t, NULL, fiboCalc, NULL);
    pthread_join(prime_t, NULL);
    pthread_join(fibo_t, NULL);
    return 0;
}
