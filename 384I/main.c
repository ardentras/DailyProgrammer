/////////////////////////////////////
// File: main.c
// Author: Shaun Rasmusen
// Email: shaunrasmusen@gmail.com
// Date: 2020/04/22
//
// Daily Programmer Challenge #384
//  Necklace Counting
//

#include <stdio.h>
#include <math.h>

long necklaces(long k, long n);
long phi(long a);
long factorial(long x);

int main( void )
{
    printf("%ld\n", necklaces(3, 4));
    printf("%ld\n", necklaces(3, 10));
    printf("%ld\n", necklaces(2, 12));
    printf("%ld\n", necklaces(3, 7));
    printf("%ld\n", necklaces(9, 4));
    printf("%ld\n", necklaces(21, 3));
    printf("%ld\n", necklaces(99, 2));

    return 0;
}

long necklaces(long k, long n)
{
    long sumOfPhiK = 0;
    int a = 1, b = 1;

    for (a = 1; a <= sqrt(n); a++)
    {
        if (n % a == 0)
        {
            b = n / a;

            sumOfPhiK += phi(a) * (long)pow(k, b);
            if (b != a)
            {
                sumOfPhiK += phi(b) * (long)pow(k, a);
            }
        }
    }

    return (1.0f / n) * (double)sumOfPhiK;
}

long phi(long a)
{
    long prime = 2, productP = 1, productPminus1 = 1;
    int i = 1, k = 1;

    do
    {
        if (a % prime == 0) // if a is divisible by the prime
        {
            productPminus1 *= prime - 1;
            productP *= prime;
        }
        i++;

        do
        {
            prime++;
            for (k = 2; k < prime - 1; k++)
            {
                if (prime % k == 0)
                {
                    // break out of the loop b/c number isn't prime
                    break;
                }
            }
        }
        while (prime % k == 0); // while a prime hasn't been found
    }
    while (prime <= a);

    return a * ((double)productPminus1 / (double)productP);
}

long factorial(long x)
{
    if (x > 1)
        return x * factorial(x - 1);
    else
        return 1;
}
