#include <stdio.h>
#include <math.h>

#define COUNT 11

int main(int argc, char** argv)
{

    int rows[COUNT][COUNT+1];

    for (int i=0; i<COUNT; i++)
        for (int j=0; j<COUNT+1; j++)
            rows[i][j] = 0;

    int left_pad = 2*COUNT;

    for (int c=1; c<left_pad; c++)
        printf(" ");

    rows[0][0] = 1;
    printf("  %4d\n", rows[0][0]);

    for (int i=1; i<COUNT; i++)
    {
        for (int c=1; c<left_pad; c++)
            printf(" ");

        rows[i][0] = rows[i-1][0];
        printf("%4d", rows[i][0]);

        for (int j=1; j<i+1; j++)
        {
            rows[i][j] = rows[i-1][j]+rows[i-1][j-1];
            rows[i][i+1] = rows[i-1][i];
            printf("%4d", rows[i][j]);
        }
        printf("\n");
        left_pad -= 2;
    }
    return 0;
}
