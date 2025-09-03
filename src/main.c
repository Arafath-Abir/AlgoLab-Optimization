
#include <stdio.h>
#include <stdlib.h>
#include "include/dp.h"
#include "include/knapsack.h"
#include "include/utils.h"

static void menu(){
    printf("\n=== Optimization Suite ===\n");
    printf("1. Coin Change (min coins)\n");
    printf("2. Fractional Knapsack\n");
    printf("0. Exit\n");
    printf("Choice: ");
}

int main(void){
    int c;
    while(1){
        menu();
        if(scanf("%d",&c)!=1) break;
        if(c==0) break;
        if(c==1){
            int n; printf("Number of coin types: "); scanf("%d",&n);
            int *coins = (int*)malloc(n*sizeof(int));
            printf("Enter %d coin values: ", n);
            for(int i=0;i<n;++i) scanf("%d",&coins[i]);
            int amount; printf("Amount: "); scanf("%d",&amount);
            int ans = coin_change_min_coins(coins, n, amount);
            if(ans==-1) printf("Impossible to make %d.\n", amount);
            else printf("Minimum coins: %d\n", ans);
            free(coins);
        } else if(c==2){
            int n; printf("Number of items: "); scanf("%d",&n);
            Item *items = (Item*)malloc(n*sizeof(Item));
            for(int i=0;i<n;++i){
                printf("Item %d (weight value): ", i+1);
                scanf("%lf %lf", &items[i].weight, &items[i].value);
            }
            double cap; printf("Capacity: "); scanf("%lf",&cap);
            double best = fractional_knapsack(items, n, cap);
            printf("Max value: %.6f\n", best);
            free(items);
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}