#include<bits/stdc++.h>
using namespace std;

// CLASS FOR BINARY TREE
template<typename T>
class TreeNode{
    public:
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
// RECURSIVE SEARCH IN BINARY SEARCH TREE
bool findKeyRecursively(TreeNode<int>* root, int key){
    if(root==NULL){
        return false;
    }
    if(key==root->data){
        return true;
    }
    if(key>root->data){
        findKeyRecursively(root->right,key);
    }
    if(key<root->data){
        findKeyRecursively(root->left,key);
    }
}
// ITERATIVE SEARCH IN BINARY SEARCH TREE
bool findKeyIteratively(TreeNode<int>* root, int key){
    while(root!=NULL){
        if(key==root->data){
            return true;
        }
        if(key>root->data){
            root= root->right;
        }
        if(key<root->data){
            root=root->left;
        }
    }
    return false;
}
// FIND THE MINIMUM VALUE IN BINARY SEARCH TREE
int findMin(TreeNode<int>* root){
    while(root->left!=NULL){
        root=root->left;
    }
    int minVal = root->data;
    return minVal;
}
// FIND THE MAXIMUM VALUE IN BINARY SEARCH TREE
int findMax(TreeNode<int>* root){
    while(root->right!=NULL){
        root=root->right;
    }
    int maxVal = root->data;
    return maxVal;
}
// RANGE SUM IN BINARY SEARCH TREE
int rangeSumBST(TreeNode<int>* root, int left, int right){
    if(root==NULL){
        return 0;
    }
    int sum =0 ;
    if(root->data >=left && root->data <=right){
        sum+=root->data;
    }
    if(root->data>=left){
        sum+=rangeSumBST(root->right,left,right);
    }
    else if(root->data<=right){
        sum+=rangeSumBST(root->left,left,right);
    }
    else{
        sum+=rangeSumBST(root->left,left,right)+rangeSumBST(root->right,left,right);
    }
    return sum;
}

int main(){
    
}