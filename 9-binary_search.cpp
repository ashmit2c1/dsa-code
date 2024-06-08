#include<bits/stdc++.h>
using namespace std;

// ======================================= // 
// SIMPLE BINARY SEARCH CODE // 
// ======================================= // 
int binarySearch(vector<int> &v,int target){
    int n = v.size();
    int start=0;
    int end = n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(target == v[mid]){
            return mid; // INDEX OF THE TARGET ELEMENT FOUND 
        }
        if(target < v[mid]){
            end = mid-1;
        }
        if(target > v[mid]){
            start = mid+1;
        }
    }
    return -1; // INDEX OF THE TARGET ELEMENT NOT FOUND
}
// ======================================= // 
// RECURSIVE BINARY SEARCH CODE // 
// ======================================= // 
int recursiveBinarySearch(vector<int> &v, int target, int start, int end){
    if(start>end){
        return -1; // INDEX OF TARGET NOT FOUND
    }
    int mid = start + (end-start)/2;
    if(target == v[mid]){
        return mid; // INDEX OF TARGET ELEMENT FOUND
    }
    if(target > v[mid]){
        return recursiveBinarySearch(v,target,mid+1,end);
    }
    else{
        return recursiveBinarySearch(v,target,start,mid-1);
    }
}
// ======================================= // 
// FIND THE INTEGER SQUARE ROOT OF NUMBER // 
// ======================================= // 
int findSqrt(int x){
    int start = 0 ;
    int end = x;
    int ans = -1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(mid*mid <= x){
            ans = mid;
            start=mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}
// ======================================= // 
// FIND THE FIRST AND LAST OCCURENCE OF ELEMENT // 
// ======================================= // 
vector<int> firstAndLast(vector<int> &v, int x){
    int n = v.size();
    int first = -1;
    int second = -1;
    int start =0 ;
    int end = n-1;
    // SEARCHING IN THE LEFT SIDE OF THE ARRAY
    while(start<=end){
        int mid = start + (end-start)/2;
        if(x==v[mid]){
            first = mid;
            end = mid-1;
        }
        if(x>v[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    int start =0 ;
    int end = n-1;
    // SEARCHING IN THE RIGHT SIDE OF THE ARRAY 
    while(start<=end){
        int mid = start + (end-start)/2;
        if(x==v[mid]){
            second = mid;
            start = mid+1;
        }
        if(x>v[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    vector<int> ans;
    ans.push_back(first);
    ans.push_back(second);
    return ans;
}
// ======================================= // 
// SEARCH FOR POSITION OF ELEMENT IN VECTOR / ARRAY // 
// ======================================= // 
int findIndex(vector<int> &arr,int x){
    int n = arr.size();
    int start  = 0 ;
    int end = n-1;
    int ans = n ;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]>=x){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}
// ======================================= // 
// FIND THE SMALLEST ELEMENT IN A ROTATE ARRAY // 
// ======================================= // 
int finMin(vector<int>& arr){
    int n = arr.size();
    int start =0 ;
    int end = n-1;
    int ans;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]>=arr[0]){
            start = mid+1;
        }
        else{
            ans = arr[mid];
            end = mid-1;
        }
    }
    return ans;
}
// ======================================= // 
// FIND AN ELEMENT USING BINARY SEARCH IN 2D MATRIX // 
// ======================================= // 
bool isPresent(vector<vector<int>> &matrix, int X){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int n = rows;
    for(int i = 0; i<n ; i++){
        int start =0;
        int end = cols-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(matrix[i][mid]==X){
                return true;
            }
            if(X>matrix[i][mid]){
                start = mid+1;
            }
            if(X<matrix[i][mid]){
                end = mid-1;
            }
        }
    }
    return false;
}