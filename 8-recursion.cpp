#include<bits/stdc++.h>
using namespace std;

// ======================= // 
// PRINT RECURSIVELY // 
// ======================= // 
void printRecursion(int i, string s, int n){
    if(i>n){
        return;
    }
    cout << s << "\n";
    printRecursion(i+1,s,n);
}
// ======================= // 
// PRINT RECURSIVELY FROM 1 TO N // 
// ======================= // 
void print1ToN(int i,int n){
    if(i>n){
        return;
    }
    cout << i << "\n";
    print1ToN(i+1,n);
}
// ======================= // 
// PRINT RECURSIVELY FROM N to 1 // 
// ======================= // 
void printNTo1(int i,int n){
    if(i<1){
        return;
    }
    cout << i << "\n";
    printNTo1(i-1,n);
}
int main(){
    int n = 5 ;
    string s = "simran";
    // printRecursion(1,s,n);
    printNTo1(n,n);
    
}
// ======================= // 
// PARAMETERISED RECURSION // 
// ======================= //
 void parameterisedRecursion(int i, int sum){
    if(i<1){
        cout << sum << "\n";
        return;
    }
    parameterisedRecursion(i-1,sum+i);
} 
// ======================= // 
// PARAMETERISED RECURSION // 
// ======================= //
int functionalRecursion(int n){
    if(n<=1){
        return 1;
    }
    int ans = n*functionalRecursion(n-1);
    return ans;
}
