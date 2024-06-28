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
// FRUITS INTO BASKETS
/*There is a farm which producees different types of trees, each tree is shown in the array
and the type of the fruit is the value inside the array, there are two baskets and each basket can only store
a sinlge type of fruits, our task is to pick the max fruits however once we a pick a fruit, we cannot skip
in between, our fruit selection should be contigious*/
/* for example the array is given as [3,3,3,1,2,1,1,2,3,4], in this we can pick the first 4 fruits, it will have three
fruits of type 3 and one fruit of type 1, thus we have picked 4 fruits, 
Thus in short, our question is to find the max length sub-array with at most 2 unique numbers 
*/
// FIRST SOLUTION WITH O(N^2)
int totalFruits(vector<int>& fruits){
    int n = fruits.size();
    int len = 0;
    for(int i = 0; i<n ; i++){
        set<int>st;
        for(int j=i;j<n;j++){
            st.insert(fruits[j]);
            if(st.size()<=2){
                len = max(len,j-i+1);
            }
            else{
                break;
            }
        }
    }
    return len;
}
// OPTIMISED SOLUTION 
int totalFruits(vector<int>&fruits){
    int n = fruits.size();
    unordered_map<int,int> map;
    int maxLen = 0;
    int left = 0;
    int right;
    for(right=0;right<n;right++){
        map[fruits[right]]++;
        while(map.size()>2){
            map[fruits[left]]--;
            if(map[fruits[left]]==0){
                map.erase(fruits[left]);
            }
            left++;
        }
        maxLen = max(maxLen,right-left+1);
    }
    return maxLen;
}
// LONGEST SUBSTRING WITH ATMOST K DISTINCT CHARACTERS
// THIS QUESTION IS EXACTLY SAME AS FRUITS TO BASKET, THE ONLY DIFFERENCE 
// IS THE THIS TIME WE ARE FINDING MAX SUB-STRING WITH K CHARACTERS, THERE WE FOUND 
// MAX SUB-ARRAY WITH 2 NUMBERS
int longestKSubstr(string s, int k) {
    int n = s.size();
    if (n == 0 || k == 0) return -1;

    unordered_map<char, int> count;
    int max_len = -1;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        count[s[right]]++;
        while (count.size() > k) {
            count[s[left]]--;
            if (count[s[left]] == 0) {
                count.erase(s[left]);
            }
            left++;
        }
        if (count.size() == k) {
            max_len = max(max_len, right - left + 1);
        }
    }
    return max_len;
    }
