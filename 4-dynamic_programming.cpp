#include<bits/stdc++.h>
using namespace std;

// FIBONACCI SEQUENCE USING DYNMAIC PROGRAMMING TOP DOWN ( RECURSION + MEMORISATION )
int fib(int n, vector<int> &dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = fib(n-1,dp) + fib(n-2,dp);
    return dp[n];
}
// FIBONACCI SEQUENCE USING DYNMAIC PROGRAMMING BOTTOM UP ( TABULATION / ITERATIVE )
int fib2(int n,vector<int> &dp){
    dp[0]=1;
    dp[1]=1;
    for(int i = 2; i<=n ; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
// MINIMUM COST CLIMBING STAIRS USING DYNAMIC PROGRAMMING BOTTOM UP
int solve(vector<int> &cost, int n,vector<int> &dp){
    if(n==0){
        return cost[0];

    }
    if(n==1){
        return cost[1];
    }
    dp[n] = cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    return dp[n];
}
int minCostClimbingStairs(vector<int> &cost){
    int n = cost.size();
    vector<int> dp(n+1);
    int ans = min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    return ans;
}
// MINIMUM COST CLIMBING STAIRS USING DYNAMIC PROGRAMMING TOP DOWN 
int minCostClimbingStair2(vector<int> &cost){
    int n = cost.size();
    vector<int> dp(n+1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i = 2; i<=n ; i++){
        dp[i] = cost[i]+min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}
int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1);
    for(int i = 0; i<n ; i++){
        dp[i]=-1;

    }
    int ans = fib(n,dp);
    cout << ans << "\n";
    
}