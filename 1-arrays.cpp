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
    for(int i = 0; i<n ; i++){
        sum+=v[i];
    }
    maxSum=sum;
    for(int i = 0; i<k ; i++){
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