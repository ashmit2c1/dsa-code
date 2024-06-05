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
// FIND THE MINMIMUM NUMBER OF COINS RECURSIVE APPROACH 
int findMin(vector<int> &nums, int x){
    if(x==0){
        return 0;
    }
    if(x<0){
        return -1;

    }
    int minCoins = INT_MAX;
    int n = nums.size();
    for(int i = 0; i<n ; i++){
        int ans = findMin(nums,x-nums[i]);
        if(ans!=-1){
            minCoins = min(minCoins,1+ans);
        }

    }
}
// MINIMUM NUNBER OF COINS USING RECURSION + MEMORISATION 
int solve(vector<int> &nums, vector<int> &dp, int x){
    if(x==0){
        return 0;
    }
    if(x<0){
        return -1;
    }
    if(dp[x]!=-1){
        return dp[x];
    }
    int minCoins = INT_MAX;
    int  n = nums.size();
    for(int i=0;i<n;i++){
        int ans = solve(nums,dp,x-nums[i]);
        if(ans!=-1){
            minCoins = min(minCoins,1+ans);
        }
    }
    dp[x]=minCoins;
    return dp[x];

}
int findMin(vector<int> &nums, int x){
    int n = nums.size();
    vector<int> dp(n+1,-1);
    int ans = solve(nums,dp,x);
    return ans;
}
// MINIMUM NUNBER OF COINS USING ITERATION
int solve(vector<int> &nums, vector<int>&dp, int x){
    dp[0] = 0;
    int n = nums.size();

    int minCoins = INT_MAX;
    for(int i=0;i<x;i++){
        for(int j = 0; j<n ; j++){
            dp[i] = min(dp[i],1+dp[i-nums[j]]);
        }
    }
    if(dp[x]==-1){
        return -1;
    }
    return dp[x];
}
int findMin(vector<int> &nums, int x){
    int n = nums.size();
    vector<int> dp(n+1,-1);
    int ans = solve(nums,dp,x);
    return ans;
}