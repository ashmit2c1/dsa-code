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
// ======================================= // 
// FIND THE PEAK ELEMENT IN MOUNTAIN ARRAY // 
// ======================================= //
int findPeakElement(vector<int> arr){
    int n = arr.size();
    int start =0 ;
    int end = n-1;
    while(start<=end){
        int mid = end+(start-end)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
            return mid; // index found
        }
        if(arr[mid]>arr[mid-1]){
            start=mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1; // index not found
} 
// ======================================= // 
// SEARCH FOR ELEMENT IN ROTATED ARRAY // 
// ======================================= //
bool search(vector<int> arr, int x){
    int n = arr.size();
    int start =0 ;
    int end = n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==x){
            return true;
        }
        else if(arr[mid]==arr[start] && arr[end]==arr[mid]){
            start ++ ;
            end --;
        }
        else if(arr[mid]>=arr[start]){
            if(x>=arr[start] && x<arr[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        else{
            if(x>=arr[mid] && x<arr[end]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
    }
    return false;
}
// ======================================= // 
// BINARY SEARCH IN 2D ARRAYS // 
// ======================================= //
bool findIn2D(vector<vector<int>> &mat, int x){
    int rows  = mat.size();
    int cols = mat[0].size();
    for (int i=0;i<rows;i++){
        int start = 0;
        int end = cols-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(mat[i][mid]==x){
                return true;
            }
            if(x>mat[i][mid]){
                start = mid+1;
            }
            if(x<mat[i][mid]){
                end= mid-1;
            }
        }
    }
    return false;
}
// ======================================= // 
// FIND THE MINIMUM ELEMENT IN ROTATED SORTED ARRAY // 
// ======================================= //
int findMin(vector<int> arr){
    int n = arr.size();
    int start = 0;
    int end = n-1;
    int ans = arr[0];
    if(arr[start]<=arr[end]){
        return ans;
    }
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[end]>=arr[mid]){
            ans = arr[mid];
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
}
// ======================================= // 
// FIND THE KTH POSITIVE MISSING NUMBER // 
// ======================================= //
int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int start =0 ;
        int end = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            int missingNumber = arr[mid]-(mid+1);
            if(k>missingNumber){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return start + k;

}
// ======================================= // 
// BOOK ALLOCATION PROBLEM  // 
// ======================================= //
bool isPossible(vector<int> &books, int n, int m, int mid){
    int studentCount=1;
    int pageSum = 0;
    for(int i = 0; i<n ; i++){
        if(books[i]>mid){
            return false;
        }
        if(pageSum+books[i]<=mid){
            pageSum+=books[i];
        }
        else{
            studentCount++;
            if(studentCount>m){
                return false;
            }
            pageSum=books[i];
        }
    }
    return true;
}
int findPages(vector<int> &books, int n, int m){
    int sum = 0;
    for(int i = 0; i<n ; i++){
        sum+=books[i];
    }
    if(m>n){
        return -1;
    }
    int start =0 ;
    int end = sum;
    int ans = -1;
    while(start<=end){
        // guess for the max pages a student can read
        int mid = start + (end-start)/2;
        if(isPossible(books,n,m,mid)==true){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}