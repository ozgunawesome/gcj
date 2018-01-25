//
//  centerofmass.c
//  centerofmass
//
//  Created by Özgün Ayaz on 11/04/14.
//  Copyright (c) 2014 Özgün Ayaz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double dx = 0.0, dy = 0.0, dz = 0.0, dvx = 0.0, dvy = 0.0, dvz = 0.0;
int num;

double dist(double t)
{
    return sqrt( ((dx+dvx*t)*(dx+dvx*t)) + ((dy+dvy*t)*(dy+dvy*t)) + ((dz+dvz*t)*(dz+dvz*t)) );
}

double ternary_search(double left, double right, double prec)
{
    if (fabs(right - left) < prec) return (left + right) / 2.0;
    
    double leftThird = (2.0 * left + right) / 3.0;
    double rightThird = (left + 2.0 * right) / 3.0;
    
    if  (dist(leftThird) < dist(rightThird))
        return ternary_search(left, rightThird, prec);

    else
        return ternary_search(leftThird, right, prec);
}

void fly_test(FILE *f)
{
    int fly_count, fly, x, y, z, vx, vy, vz;
    dx = 0.0; dy = 0.0; dz = 0.0; dvx = 0.0; dvy = 0.0; dvz = 0.0;
    fscanf(f, "%d", &fly_count);
    for (fly = 0; fly < fly_count; fly++)
    {
        fscanf(f, "%d %d %d %d %d %d", &x, &y, &z, &vx, &vy, &vz);
        dx +=x; dy+=y; dz+=z; dvx+=vx; dvy+=vy; dvz+=vz;
    }
    dx /= fly_count; dy /= fly_count; dz /= fly_count;
    dvx /=fly_count; dvz/=fly_count; dvy/=fly_count;
    double result;
    if (dvx == 0.0 && dvy == 0.0 && dvz == 0.0)
        result = 0.0;
    else result = ternary_search(0.0, 10000000000000000000000000.0, 0.000000001);
    printf("Case #%d: %.8f %.8f\n", num, dist(result), result);
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s <input-file> \n", argv[0]); return 1;
	}
    int num_test;
    FILE *f = fopen(argv[1], "r");
    if (!f) return 1;
    fscanf(f, "%d", &num_test);
    for (num = 1; num <= num_test; num++)
        fly_test(f);
}