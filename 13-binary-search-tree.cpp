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
// VALIDATE BINARY SEARCH TREE
bool helper(TreeNode<int>* root, int maxValue = INT_MAX, int minVal = INT_MIN){
    if(root==NULL){
        return true;
    }
    bool left = helper(root->left,root->data,minVal);
    bool right = helper(root->right, maxValue,root->data);
    if(left && right && root->data > minVal && root->data < maxValue){
        return true;
    }
    else{
        return false;
    }
}
// CONVERT A SORTED ARRAY TO BINARY SEARCH TREE
TreeNode<int>* helperFunction(vector<int>&arr,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid = start + (end-start)/2;
    int rootData = arr[mid];
    TreeNode<int>* root = new TreeNode<int>(rootData);
    root->left = helperFunction(arr,start,mid-1);
    root->right = helperFunction(arr,mid+1,end);
    return root;
}
TreeNode<int>* createTree(vector<int>&arr){
    int n = arr.size();
    return helperFunction(arr,0,n-1);
}
// PRINT A BINARY SEARCH TREE
void printTreeData(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    if(root->left!=NULL){
        cout << " L " << " : " << root->left->data << "\n";
    }
    if(root->right!=NULL){
        cout << " R " << " : " << root->right->data << "\n";
    }
    printTreeData(root->left);
    printTreeData(root->right);
}
// INSERT A DATA IN BINARY SEARCH TREE
TreeNode<int>* insertData(TreeNode<int>* root, int value){
    if(root==NULL){
        TreeNode<int>* n = new TreeNode<int>(value);
        return n;
    }
    if(value > root->data){
        root->right = insertData(root->right,value);
    }
    else{
        root->left = insertData(root->left,value);
    }
    return root;
}
bool validate(TreeNode<int>* root){
    return helper(root);
}
int main(){
    
}