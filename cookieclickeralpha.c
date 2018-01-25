#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double minsec_to_farm_or_target(double cost, double incr, double target, double persec)
{
    double sec_to_farm = (cost / persec) + (target / (persec+incr));
    double sec_to_target = target / persec;
    if (sec_to_farm < sec_to_target)
    {
        return (cost / persec) + minsec_to_farm_or_target(cost, incr, target, persec + incr);
    } else {
        return sec_to_target;
    }
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("cookie-clicker-alpha: Usage: %s <input-file> \n", argv[0]);
        return 1;
	}
    int num_test;
    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        printf("cookie-clicker-alpha: %s: No file\n", argv[1]);
        return 1;
    }
    fscanf(f, "%d", &num_test);
    int i;
    for (i=1; i<=num_test; i++) {
        double cost, incr, target;
        fscanf(f, "%lf %lf %lf", &cost, &incr, &target);
        printf("Case #%d: %.8lf\n", i, minsec_to_farm_or_target(cost,incr,target,2.0));
    }
    return 0;
}