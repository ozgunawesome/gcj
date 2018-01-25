//
//  minesweepin.c
//
//  what is this ? i hate myself
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROW 10
#define MAX_COL 10
int main(int argc, char* argv[])
{
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
    int i;
    char field[MAX_ROW][MAX_COL];
    fscanf(f,"%d",&num_test);
    for (i=1;i<=num_test;i++)
    {
        memset(field, '.', MAX_ROW * MAX_COL * sizeof(char));
        int row, col, mine;
        fscanf(f, "%d %d %d", &row, &col, &mine);
        int row_t = row, col_t = col, mine_t = mine;
        int row_ptr = 0, col_ptr = 0;
        int row_end = row, col_end = col;
        int a,b,c;
        while (mine_t)
        {
#ifdef DEBUG
            printf("Test %d: %d mines remain to place on %d x %d grid\n",i,mine_t,row_t,col_t);
#endif
            if (row_t < col_t && mine_t >= col_t)
            {
#ifdef DEBUG
                printf("Test %d: Mine a col. Rowptr = %d Colptr = %d\n",i, row_ptr, col_ptr);
#endif
                for (a = row_ptr; a < row_end; a++)
                {
                    field[a][col_ptr] = '*';
                    mine_t--;
                }
                col_ptr++;
                col_t--;
                
            }
            else if (col_t <= row_t && mine_t >= row_t)
            {
#ifdef DEBUG
                printf("Test %d: Mine a row. Rowptr = %d Colptr = %d\n",i, row_ptr, col_ptr);
#endif
                for (a = col_ptr; a < col_end; a++)
                {
                    field[row_ptr][a] = '*';
                    mine_t--;
                }
                row_ptr++;
                row_t--;
            }
            else
            {
#ifdef DEBUG
                printf("Test %d: Point of no return\n",i);
#endif
                int whoa = 0;
                int rows = row_ptr; int cols = col_ptr;
                int rowe = row_end-1; int cole = col_end-1;
                while(mine_t)
                {
                    if (whoa)
                    {
                        field[rows][cols++] = '*';
                        mine_t--;
                        whoa++;
                    }
                    else
                    {
                        field[rowe][cole--]='*';
                        mine_t--;
                        whoa--;
                    }
                }
            }
        }
        int okay = 0;
#ifdef DEBUG
        printf("Test %d: Start click-find\n", i);
#endif
        for (b = row_ptr; b < row_end; b++)
        {
            if (okay) break;
            for (c = col_ptr; c < col_end; c++)
            {
                okay = 1;
                if (field[b][c] == '*') okay = 0;
                if (b != 0) if (field[b-1][c] != '.') okay = 0;
                if (b+1 != row) if (field[b+1][c] != '.') okay = 0;
                if (c != 0) if (field[b][c-1]!='.')okay = 0;
                if (c+1 !=col) if (field[b][c+1]!='.')okay=0;
                
                if (b != 0 ||c != 0) if (field[b-1][c-1] != '.') okay = 0;
                if (b+1 != row || c+1 != col) if (field[b+1][c+1] != '.') okay = 0;
                if (b+1 != row || c != 0) if (field[b+1][c-1]!='.') okay = 0;
                if (b != 0 || c+1 != col) if (field[b-1][c+1]!='.') okay = 0;
                
                if (okay)
                {
                    field[b][c] = 'c';
                    break;
                }

            }
        }
        printf("Case #%d:\n",i);
#ifdef DEBUG
        printf("Placing %d mines on %d x %d grid\n", mine, row, col);
#endif
        if (okay)
        {
            for (b = 0; b < row; b++)
            {
                for (c = 0; c < col; c++)
                {
                    printf("%c", field[b][c]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("Impossible\n");
        }
    }
}