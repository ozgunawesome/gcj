#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long candies[100000];

int cmpfunc (const void * a, const void * b)
{
   return (int)( *(unsigned long*)a - *(unsigned long*)b );
}

int main() {
    unsigned int n, k, i, min = 0xFFFFFFFF, min_temp;
    scanf("%u %u", &n, &k);
    for (i = 0; i < n; i++) scanf("%lu", candies + i);
    qsort(candies, n, sizeof(long), cmpfunc);
    for (i = 0; i < n - k + 1; i++)
    {
        min_temp = (unsigned int)(candies[i + k - 1] - candies[i]);
        if (min_temp < min) min = min_temp;
    }
    printf("%u\n", min);
    return 0;
}

