#include <stdio.h>
#include "my_mat.h"

int main()
{
    int matrix[N][N];
    int isValidMatrix = 0;

    char action;
    scanf(" %c", &action);
    while (action != 'D')
    {
        if(action == 'A')
        {
            init(matrix);
            shortestPath(matrix);
            isValidMatrix = 1;
        }
        if(action == 'B')
        {
            isThereAPath(matrix, isValidMatrix);
        }
        if(action == 'C')
        {
            shortestPathWeight(matrix, isValidMatrix);
        }
        scanf(" %c", &action);
    }
    return 0;
}