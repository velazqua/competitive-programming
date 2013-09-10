#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

int main(void)
{
    unsigned int lim = 5000000, i, j;
    lim += 1;
    bool *primes = calloc(lim, sizeof(bool));

    for (i = 2; i*i <= lim-1; i++)
        if (!primes[i])
            for (j = i * i; j <= lim-1; j += i)
                primes[j] = true;
	
	
    for (i = 2; i <= lim-1; i++)
    {
	    if (!primes[i])
        {
			
		}
	}
    return 0;
}
