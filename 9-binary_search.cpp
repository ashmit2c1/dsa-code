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