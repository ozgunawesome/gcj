//
//  minesweepin.c
//
//
//  Created by Özgün Ayaz on 12/04/14.
//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
    if (argc < 2)
    {
        printf("minesweep: Usage: %s <input-file> \n", argv[0]);
        return 1;
    }
    int num_test;
    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        printf("minesweep: %s: No file\n", argv[1]);
        return 1;
    }
}