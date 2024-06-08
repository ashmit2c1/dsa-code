#include<bits/stdc++.h>
using namespace std;


// SELECTION SORT
void selectionSort(vector<int> &v){
    int n = v.size();
    int i,j,minIdx;
    for(i=0;i<n-1;i++){
        minIdx=i;
        for(j=i+1;j<n;j++){
            if(v[minIdx]>v[j]){
                minIdx=j;
            }
            if(minIdx!=i){
                swap(v[minIdx],v[i]);
            }
        }
    }
}

void bubbleSort(vector<int> &v){
    int n = v.size();
    for(int i=0;i<=n-1;i++){
        bool flag = false;
        for(int j=0;j<=n-2;j++){
            if(v[j]>v[j+1]){
                flag = true;
                swap(v[j],v[j+1]);
            }
        }
        if(flag==false){
            break;
        }
    }
}

void insertionSort(vector<int> &v){
    int n = v.size();
    for(int i=1;i<n;i++){
        int currElement = v[i];
        int j = i-1;
        while(j>=0 && v[j] > currElement){
            v[j+1]=v[j];
            j--;
        }
        v[j+1] = currElement;
    }
}
int main(){
    int n = 5 ;
    vector<int> v;
    for(int i = 0; i<n ; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    insertionSort(v);
    for(int i = 0; i<n ; i++){
        cout << v[i] << " ";
    }
}

void merge(vector<int> &v, int start, int mid, int end) {
    int size_a = mid - start + 1;
    int size_b = end - mid;

    vector<int> a(size_a);
    vector<int> b(size_b);

    for (int i = 0; i < size_a; i++) {
        a[i] = v[start + i];
    }
    for (int i = 0; i < size_b; i++) {
        b[i] = v[mid + 1 + i];
    }

    int i = 0, j = 0;
    int k = start;
    while (i < size_a && j < size_b) {
        if (a[i] < b[j]) {
            v[k++] = a[i++];
        }
        else {
            v[k++] = b[j++];
        }
    }
    while (i < size_a) {
        v[k++] = a[i++];
    }
    while (j < size_b) {
        v[k++] = b[j++];
    }
}

void mergeSort(vector<int> &v, int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);
    merge(v, start, mid, end);
}  