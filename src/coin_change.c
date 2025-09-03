#include <limits.h>
#include <stdlib.h>
#include "dp.h"
int coin_change_min_coins(const int *coins, int n, int amount){
    if(amount<0) return -1;
    int INF = INT_MAX/4;
    int *dp = (int*)malloc((amount+1)*sizeof(int));
    if(!dp) return -1;
    dp[0]=0;
    for(int i=1;i<=amount;++i) dp[i]=INF;
    for(int i=1;i<=amount;++i){
        for(int j=0;j<n;++j){
            if(coins[j]<=i && dp[i-coins[j]]!=INF){
                int cand = dp[i-coins[j]]+1;
                if(cand<dp[i]) dp[i]=cand;
            }
        }
    }
    int ans = (dp[amount]==INF)?-1:dp[amount];
    free(dp);
    return ans;
}
