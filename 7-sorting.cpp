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