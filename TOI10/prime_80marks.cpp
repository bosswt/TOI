#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 8000000

void prime(int n, int *primes)
{
        int count=0;
        primes[count++] = 2;
        if (count == n)
                return;
        for(int i=3; i<=MAX; i+=2)
        {
                bool isPrime=true;
                for(int j=3; j<=sqrt(i); j+=2)
                {
                        if(i%j==0)
                        {
                                isPrime=0;
                                break;
                        }
                }
                if(isPrime)
                {
                        primes[count++] = i;
                        if(count==n)
                                return;
                }
        }
}

int main()
{
        int n;
        scanf("%d",&n);
        int primes[n+1];
        prime(n, primes);
        printf("%d\n", primes[n-1]);
        return 0;
}
