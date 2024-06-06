#include<bits/stdc++.h>
using namespace std;

// =========================================== // 
// LENGTH OF THE LONGEST SUBSTRING WIHTOUT REPEATING CHARACTERS
// =========================================== // 
int lenOfLongestSubstring(string &s){
    vector<bool>count(256,0);
    int first=0;
    int second=0;
    int len=0;
    while(second<s.size()){
        while(count[s[second]]){
            count[s[first]]=0;
            first++;
        }
        count[s[second]]=1;
        len= max(len,second-first+1);
        second++;
    }
    return len;
}

// =========================================== // 
// SORT A GIVEN STRING 
// =========================================== //
void sortString(string &s){
    vector<int> freq(26,0);
    int n = s.size();
    for(int i = 0; i<n ; i++){
        int index = s[i]-'a';
        freq[index]++;
    }
    int j=0;
    for(int i=0;i<26;i++){
        while(freq[i]--){
            s[j]=i+'a';
            j++;
        }
    }
}
// =========================================== // 
// FIND THE LONGEST PALINDROME IN A STRING
// =========================================== //
int lenLongestPalindrome(string &s){
    int n = s.size();
    vector<int> lower(26,0);
    vector<int> upper(26,0);
    for(int i = 0; i<n ; i++){
        if(s[i]>='a'){
            lower[s[i]-'a']++;
        }
        if(s[i]>='A'){
            upper[s[i]-'A']++;
        }
    }
    int count=0;
    int odd=0;
    for(int i = 0; i<26; i++){
        if(lower[i]%2==0){
            count+=lower[i];
        }
        else{
            count+=lower[i];
            odd=1;
        }
        if(upper[i]%2==0){
            count+=upper[i];
        }
        else{
            count+=upper[i];
            odd=1;
        }
    }
    return count+odd;
}
// =========================================== // 
// GIVEN TWO STRINGS CHECK IF THEY ARE ANAGRAM OR NOT
// =========================================== //
bool check(string &s1, string &s2){
    int n1 = s1.length();
    int n2 = s2.length();
    if(n1!=n2){
        return false;
    }
    vector<int> freq(26,0);
    for(int i = 0; i<n1 ; i++){
        int index1=s1[i]-'a';
        freq[index1]++;
        int index2=s2[i]-'a';
        freq[index2]--;
    }
    bool flag = true;
    for(int i = 0; i<26 ; i++){
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
}