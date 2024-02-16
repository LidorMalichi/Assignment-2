#include <stdio.h>
#include "my_mat.h"

void init(int matrix[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void shortestPath(int matrix[N][N])
{
    for(int k = 1; k < N; k++)
    {
        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; ++j)
            {
                if(i != j && (matrix[i][k] > 0 && matrix[k][j] > 0))
                {
                    if(matrix[i][j] > matrix[i][k] + matrix[k][j])
                    {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
    }
}

void isThereAPath(int matrix[N][N], int isValidMatrix)
{
    int i, j;
    scanf("%d %d", &i, &j);
    if(isValidMatrix == 0 || matrix[i][j] == 0)
    {
        printf("False\n");
        return;
    }
    printf("True\n");
}

void shortestPathWeight(int matrix[N][N], int isValidMatrix)
{
    int i, j;
    scanf("%d %d", &i, &j);
    if(isValidMatrix == 0 || matrix[i][j] == 0)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", matrix[i][j]);

}