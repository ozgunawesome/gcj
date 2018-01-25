#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t, n, c, m, choc, wrappers_remain, newchoc;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d", &n, &c, &m);
        choc = n / c;
        wrappers_remain = choc;
        while (wrappers_remain >= m)
        {
            newchoc = wrappers_remain / m;
            wrappers_remain -= newchoc * (m - 1);
            choc += newchoc;
        }
        printf("%d\n", choc);
    }
    return 0;
}

