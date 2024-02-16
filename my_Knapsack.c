#include <stdio.h>

#define MAXWEIGHT 20
#define N 5
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void scan_knapsack(int weights[], int values[], char products[])
{
    for(int i = 0; i < N; i++)
    {
        scanf(" %c", &products[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }
}

void maxProfit(int weights[], int values[], int profit[][MAXWEIGHT+1])
{
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < MAXWEIGHT+1; j++){
            if(i == 0 || j == 0){
                profit[i][j] = 0;
            }
            else{
                if(weights[i-1] <= j){
                    profit[i][j] = MAX(profit[i-1][j],
                                       values[i-1] + profit[i-1][j-weights[i-1]]);
                }
                else{
                    profit[i][j] = profit[i-1][j];
                }
            }
        }
    }
}

void choose(int weights[], int values[] ,int profit[][MAXWEIGHT+1], int selected_bool[]){
    int i = N;
    int j = MAXWEIGHT;
    for(int k = 0;k < i; k++){
        selected_bool[k] = 0;
    }

    while(i > 0 && j > 0){
        int w = weights[i-1];

        if(profit[i][j] > profit[i-1][j]){
            selected_bool[i-1] = 1;
            i--;
            j-=w;
        }
        else{
            i--;
        }
    }
}


int knapSack (int weights[], int values[] , int selected_bool[]){
    int profit[N+1][MAXWEIGHT+1];
    maxProfit(weights, values, profit);
    choose(weights, values , profit, selected_bool);
    return profit[N][MAXWEIGHT];
}

void printItems(char products[], int selected_bool[]){
    printf("Selected Items:");
    for(int i=0; i<N; i++){
        if(selected_bool[i] == 1){
            printf("%c", products[i]);
        }
    }
}

int main(){
    char products[N];
    int weights[N];
    int values[N];
    int selected_bool[N];

    scan_knapsack(weights, values, products);
    int max_profit = knapSack(weights, values, selected_bool);
    printf("Maximum profit: %d\n", max_profit);
    printItems(products, selected_bool);

    return 0;

}

