#include<bits/stdc++.h>
using namespace std;

// FIND THE LAST OCCURENCE OF AN ELEMENT 
int findLastOccurence(vector<int> &v, int el){
    int index=0;
    int n = v.size();
    for(int i = n-1 ; i>=0 ; i++){
        if(v[i]==el){
            index=i;
            break;
        }
    }
    return index;
}
// FIND THE TOTAL NUMBER OF PAIRS WHOSE SUM IS EQUAL TO X
int findPairs(vector<int> &v, int x){
    int n = v.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum = v[i]+v[j];
            if(sum==x){
                count++;
            }
        }
    }
    return count;
}
// FIND THE ELEMENT THAT DOES NOT HAVE A DUPLICATE
int findElement(vector<int> &v){
    int n = v.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i]==v[j]){
                v[i]=-1;
                v[j]=-1;
            }
        }
    }
    int element=0;
    for(int i = 0; i<n ; i++){
        if(v[i]!=-1){
            element = v[i];
            break;
        }
    }
    return element;
}
// FIND THE SECOND LARGEST ELEMENT IN ARRAY
int secondLargest(vector<int> &v){
    int max1=INT_MIN;
    int n = v.size();
    int maxIndex=0;
    for(int i = 0; i<n ; i++){
        if(v[i]>max1){
            max1=v[i];
            maxIndex=i;
        }
    }
    v[maxIndex]=-1;
    int max2=INT_MIN;
    int maxIndex2=0;
    for(int i = 0; i<n ; i++){
        if(v[i]>max2 && v[i]!=max1 && i!=maxIndex){
            max2=v[i];
            maxIndex2=i;
        }
    }
    return max2;
}
// ROTATE AN ARRAY BY K STEPS
void rotateByK(vector<int> &v, int k){
    int n = v.size();
    k=k%n;
    int temp[n];
    int j=0;
    for(int i=n-k;i<n;i++){
        temp[j]=v[i];
        j++;
    }
    for(int i=0;i<=k;i++){
        temp[j]=v[i];
        j++;
    }
    int k=0;
    for(int i = 0; i<n ; i++){
        v[k]=temp[i];
        k++;
    }
}
// SORT AN ARRAY WITH 0 AND 1
void sortZeroesOnes(vector<int> &v){
    int n = v.size();
    int countZero=0;
    for(int i = 0; i<n ; i++){
        if(v[i]==0){
            countZero++;
        }
    }
    vector<int> w;
    for(int i = 0; i<n ; i++){
        if(i<=countZero){
            w.push_back(0);
        }
        else{
            w.push_back(1);
        }
    }
    for(int i = 0; i<n ; i++){
        cout << w[i] << "\n"; 
    }
}
// USING TWO POINTER APPRAOCH SOLVE TEH ABOVE QUESTION
void sortZeroesAndOnesTwoPointers(vector<int> &v){
    int n = v.size();
    int leftptr=0;
    int rightptr=n-1;
    while(leftptr<rightptr){
        if(v[leftptr]==1 && v[rightptr]==0){
            swap(v[leftptr],v[rightptr]);
            leftptr++;
            rightptr--;
        }
        if(v[leftptr]==0){
            leftptr++;
        }
        if(v[rightptr]==1){
            rightptr--;
        }
    }
    for(int i = 0; i<n ; i++){
        cout << v[i] << "\n";
    }
}
// GIVEN AN ARRAY PLACE ALL THE EVEN INTEGERS IN FRONT 
void sortOddsEvens(vector<int> &v){
    int n = v.size();
    int leftpt=0;
    int rightpt=n-1;
    while(leftpt<rightpt){
        if(v[leftpt]%2!=0 && v[rightpt]%2==0){
            swap(v[leftpt],v[rightpt]);
            leftpt++;
            rightpt--;
        }
        if(v[leftpt]%2==0){
            leftpt++;
        }
        if(v[rightpt]%2!=0){
            rightpt--;
        }
    }
    for(int i = 0; i<n ; i++){
        cout << v[i] << "\n";
    }
}
// GIVEN AN INTEGER ARRAY, RETURN THE SQUARE ARRAY IN INCREASING ORDER
void returnSortedSquareArray(vector<int> &v){
    int n = v.size();
    int leftptr=0;
    int rightptr =n-1;
    vector<int> ans(n);
    int index=n-1;
    while(leftptr<=rightptr){
        if(abs(v[leftptr]) < abs(v[rightptr])){
            ans[index]=v[rightptr]*v[rightptr];
            rightptr--;
            index--;
        }
        else{
            ans[index]=v[leftptr]*v[leftptr];
            leftptr++;
            index--;
        }
    }
    for(int i = 0; i<n ; i++){
        cout << ans[i] << "\n";
    }    
}
// GIVEN AN INTEGER ARRAY RETURN THE PREFIX SUM OF THE ARRAY
void prefixSum(vector<int> &v){
    int n = v.size();
    for(int i = 1; i<n ; i++){
        v[i]=v[i]+v[i-1];
    }
    for(int i = 0; i<n ; i++){
        cout << v[i] << "\n";
    }
}
// GIVEN AN INTEGER ARRAY CHECK IF WE CAN PARTITION THE ARRAY INTO TWO HALVES WITH EQUAL SIM
bool check(vector<int> &v){
    int sum=0;
    int n = v.size();
    for(int i = 0; i<n ; i++){
        sum +=v[i];
    }
    int prefixSum=0;
    int suffixSum=0;
    for(int i = 0; i<n ; i++){
        prefixSum+=v[i];
        suffixSum=sum-prefixSum;
        if(prefixSum==suffixSum){
            return true;
        }
    }
    return false;
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
// FIND THE SUB-ARRAY INDEX WITH THE GIVEN SUM 
vector<int> subArraySum(vector<int> &v,int sum){
    int n = v.size();
    int start=0;
    int end = n-1;
    int currSum=0;
    vector<int> ans;
    for(int i = 0; i<n ; i++){
        currSum=currSum+v[i];
        if(currSum>=sum){
            end=i;
            while(sum<currSum && start<end){
                currSum-=v[start];
                start++;
            }
        }
        if(currSum==sum){
            ans.push_back(start+1);
            ans.push_back(end+1);
            return ans;
        }
    }
    ans.push_back(-1);
    return ans;
}
// FIND THE MIN NUMBER OF OPERATIONS REQUIRED TO CHANGE ALL THE ELMENTS TO SAME 
int changeAll(vector<int> &v){
    int n = v.size();
    sort(v.begin(),v.end());
    int occ=1;
    int maxOcc=1;
    for(int i = 0; i<n-1 ; i++){
        if(v[i]==v[i+1]){
            occ++;
            maxOcc=max(occ,maxOcc);
        }
        else{
            occ=1;
        }
    }
    int ans = n-maxOcc;
    return ans;
}
int main(){
    
}
// MAX SUBARRAY ( KADANE'S ALGORITHM )
int maxSubArray(vector<int>& nums) {
    int maxHere = 0;
    int maxSoFar = INT_MIN;
    int n = nums.size();
    for(int i=0;i<n;i++){
        maxHere+=nums[i];
        if(maxHere<nums[i]){
            maxHere = nums[i];
        }
        if(maxSoFar < maxHere){
            maxSoFar = maxHere;
        }
    }
    return maxSoFar;
}
// REVERSE A GIVEN ARRAY 
void reverseArray(vector<int>&v){
    int n = v.size();
    int start = 0 ;
    int end = n-1;
    while(start<=end){
        swap(v[start],v[end]);
        start++;
        end--;
    }
    for(int i = 0; i<n ; i++){
        cout << v[i] << " ";
    }
}
// FIND THE KTH SMALLEST ELEMENT IN ARRAY
int kthSmallest(vector<int>&v, int k){
    int n = v.size();
    sort(v.begin(),v.end());
    int ans = v[k-1];
    return ans;
}
// FIND THE KTH LARGEST ELEMENT IN ARRAY
int kthLargest(vector<int>&v, int k){
    int n = v.size();
    sort(v.begin(),v.end());
    int ans = v[n-k+1];
    return ans;
}
// FIND THE UNION AND INTERSECTION OF TWO SORTED ARRAYS AND RETURN THE ARRAY
vector<int> doUnion(int a[], int n, int b[], int m){
    int i=0;
    int j=0;
    vector<int> unionArr;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            if(unionArr.size()==0 || unionArr.back()!=a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionArr.size()==0 || unionArr.back()!=b[j]){
                unionArr.push_back(b[j]);
            }
            j++;

        }
    }
    while(i<n){
        if(unionArr.size()==0||unionArr.back()!=a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
    }
    while(j<m){
        if(unionArr.size()==0||unionArr.back()!=b[j]){
            unionArr.push_back(b[j]);
        }
        j++;
    }
    return unionArr;
}
// INTERSECTION OF TWO SORTED ARRAYS
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n = nums1.size();
        int m = nums2.size();
        int i=0;
        int j=0;
        vector<int> ans;
        while(i<n && j<m){
            if(nums1[i] > nums2[j]){
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                if(ans.size()==0|| ans.back()!=nums1[i] ){
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        
        return ans;
    }
// CYCLICALLY ROTATE AN ARRAY BY ONE PLACE 
vector<int> rotate(vector<int>&v){
    vector<int> ans;
    int n = v.size();
    ans.push_back(v[n-1]);
    for(int i = 0; i<n-1 ; i++){
        ans.push_back(v[i]);
    }
    int index = 0;
    for(int i = 0; i<n ; i++){
        v[index]=ans[i];
    }
    return v;
}
// CHECK IF THE ARRAY IS SORTED OR NOT 
bool check(vector<int>&v){
    int n = v.size();
    for(int i = 0; i<n-1 ; i++){
        if(v[i] > v[i+1]){
            return false;
        }
    }
    return true;
}
// FIND AN ELEMENT IN SORTED ARRAY ( BINARY SEARCH )
bool find(vector<int>&v,int target){
    int n = v.size();
    int start =0;
    int end = n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(v[mid]==target){
            return true;
        }
        if(v[mid]<target){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return false;
}
// FIND THE MISSING ELEMENT IN ARAY
int findMissingNumber(int n,vector<int>&v){
    int sum = 0;
    int n2 = v.size();
    for(int i = 1; i<=n;i++){
        sum+=i;
    }
    int sum2 = 0;
    for(int i = 0; i<n2 ; i++){
        sum2+=v[i];
    }
    int ans = sum-sum2;
    return ans;
}
// FIND THE MAX ONES BY FLIPPING M ZEROES 
int findZeros(vector<int> &v, int n, int m){
    int j=0;
    int zero=0;
    int ans=0;
    for(int i = 0; i<n ; i++){
        if(v[i]==0){
            zero++;
        }
        while(zero>m){
            if(v[j]==0){
                zero--;
            }
            j++;
        }
        ans=max(ans,j-i+1);
    }
    return ans;
}
// FIND THE LONGEST SUBARRAY WITH SUM K ( ASSUMING ARRAY HAS ONLY POSITIVES)
int lenOfLongestSubarray(vector<int>&v, int k){
    int left = 0;
    int right = 0;
    int maxLen = 0;
    int sum = 0;
    while(right< v.size()){
        sum+=v[right];
        while(left<=right && sum>=k){
            if(sum==k){
                maxLen = max(maxLen,right-left+1);
                right++;
            }
            sum-=v[left];
            left++;
        }
        right++;
    }
    return maxLen;
}
// SEARCH FOR AN ELEMENT IN 2D MATRIX
bool find(vector<vector<int>> matrix,int target){
    int rows = matrix.size();
    int cols = matrix[0].size();
    for(int i=0;i<rows;i++){
        int start = 0;
        int end = cols-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(matrix[i][mid]==target){
                return true;
            }
            if(target > matrix[i][mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
    }
    return false;
}
// STOCK BUY AND SELL 
int stockBuyAndSell(vector<int>&prices){
    int n= prices.size();
    int maxProfit = 0;
    for(int i=1;i<n;i++){
        if(prices[i]>prices[i-1]){
            int sell = prices[i]=prices[i-1];
            maxProfit+=sell;
        }
    }
    return maxProfit;
}
