#include<bits/stdc++.h>
using namespace std;
// FIND THE LONGEST SUB-ARRAY WITH THE SUM K ( ASSUME ARRAY CONTAINS ONLY POSITIVE )
int longestSubArrayWithSumK(int A[], int N, int K){
    int left = 0;
    int right = 0;
    int mxLen = 0;
    int sum =0;
    while(right<N){
        sum+=A[right];
        while(left<=right && sum>=K){
            if(sum==K){
                mxLen = max(mxLen,right-left+1);
            }
            sum-=A[left];
            left++;
        }
        right++;
    }
    return mxLen;
}

// LONGEST SUBARRAY WITH SUM K ( IF ARRAY HAS BOTH POSITIVE AND NEGATIVE )
int lenOfLongSubarr(int A[], int N, int K){
    map<int, int> sumMap;
    int maxLen = 0;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        if (sum == K) {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - K;
        if (sumMap.find(rem) != sumMap.end()) {
            int len = i - sumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (sumMap.find(sum) == sumMap.end()) {
            sumMap[sum] = i;
        }
    }
    return maxLen;
}

// FIND THE MAX SUM OF SUB ARRAY OF SIZE K
int maxSum(vector<int> &v, int k){
    int n = v.size();
    int sum =0;
    int maxSum=0;
    for(int i = 0; i<k ; i++){
        sum+=v[i];
    }
    maxSum=sum;
    for(int i = k; i<n ; i++){
        sum = sum +v[i]-v[i-k];
        maxSum = max(maxSum,sum);
    }
    return maxSum;
}
