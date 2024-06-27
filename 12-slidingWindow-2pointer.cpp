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
// FIND THE MAX POINTS FROM THE CARDS WE CAN PICK 
/* We can pick N cards from the array to maximise points, however 
we can only pick the cards from either the front or the back, that is 
if we have to pick 4 cards, then we either pick all 4 from the front 
3 from front 1 from back ,2 from front 2 fron back , 1 front 3 back or 
all four from the back, we cannot pick cards from the middle */
int maxPoints(vector<int> &v, int k){
    int n = v.size();
    int leftSum = 0 ;
    int rightSum = 0;
    int maxSum = 0 ;
    for(int i = 0; i<k ; i++){
        leftSum+=v[i];
    }
    maxSum = leftSum;
    int rightIndex = n-1;
    for(int i=k-1;i>=0;i--){
        leftSum-=v[i];
        rightSum+=v[rightIndex];
        maxSum = max(maxSum,leftSum+rightSum);
        rightIndex--;
    }
    return maxSum;
}
// LONGEST SUBSTRING WITHOUT REPEARTING CHARACTERS
int longestSubString(string s){
    int first=0;
    int second =0;
    int len = 0;
    vector<bool> count(256,false);
    while(second<s.size()){
        char character = s[second];
        while(count[character]){
            count[s[first]]=false;
            first++;
        }
        count[character] = true;
        len = max(len, second-first+1);
        second++;
    }
    return len;
}
