#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("magician: Usage: %s <input-file> \n", argv[0]);
        return 1;
	}
    int num_test;
    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        printf("magician: %s: No file\n", argv[1]);
        return 1;
    }
    fscanf(f, "%d", &num_test);
    int i, j, a, b, hit;
    int cards1[16];
    int cards2[16];
    int test1[4];
    int test2[4];
    int row1;
    int row2;
    for (i = 1; i <=num_test; i++)
    {
        printf("Case #%d: ", i);
        fscanf(f, "%d", &row1);
        for (j=0;j<16;j++) fscanf(f,"%d",&cards1[j]);
        fscanf(f, "%d", &row2);
        for (j=0;j<16;j++) fscanf(f,"%d",&cards2[j]);
        memcpy(test1, cards1 + (4* (row1-1)), 4 * sizeof(int));
        memcpy(test2, cards2 + (4* (row2-1)), 4 * sizeof(int));
        hit = 0;
        for (a = 0; a < 4; a++)
            for (b = 0; b < 4; b++)
                if (test1[a] == test2[b])
                {
                    if (hit == 0)
                        hit = test1[a];
                    else
                        hit = 31;
                }
        if (hit == 0) printf("Volunteer cheated!\n");
        else if (hit == 31) printf("Bad magician!\n");
        else printf("%d\n", hit);
    }
}