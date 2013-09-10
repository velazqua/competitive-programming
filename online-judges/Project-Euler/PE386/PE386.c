#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
    unsigned int lim, i, j;

    printf("Find primes upto: ");
    scanf("%d", &lim);
    lim += 1;
    bool *primes = calloc(lim, sizeof(bool));

    for (i = 2; i*i <= lim-1; i++)
        if (!primes[i])
            for (j = i * i; j <= lim-1; j += i)
                primes[j] = true;

    printf("\nListing prime numbers between 2 and %d:\n\n", lim - 1);
    long long R = 1LL;
    for (i = 2; i <= lim-1; i++)
    {
	    if (!primes[i])
        {
			R += (lim-1)/i;
		}
	}
	printf( "%lld\n", R );

    return 0;
}
