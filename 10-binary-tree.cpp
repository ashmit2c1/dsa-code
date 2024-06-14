#include<bits/stdc++.h>
using namespace std;

//CREATING A TREE N0DE FOR BINARY TREE
template<typename T>
class TreeNode{
public:
    T data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(T data){
        this->data= data;
        this->left = NULL;
        this->right = NULL;
    }
};
// FUNCTION TO PRINT A BINARY TREE
void printTree(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout << root->data << ":";
    if(root->left!=NULL){
        cout << root->left->data << "L" << " ";

    }
    if(root->right!=NULL){
        cout << root->right->data << "R" <<" ";
    }
    cout << "\n";
    printTree(root->left);
    printTree(root->right);
}
// RECURSIVE FUNCTION TO TAKE INPUT IN BINARY TREE
TreeNode<int>* takeInputRecursive(){
    int rootData;
    cin >> rootData;
    if(rootData==-1){
        return NULL;
    }
    TreeNode<int>* root = new TreeNode<int>(rootData);
    TreeNode<int>* leftChild = takeInputRecursive();
    TreeNode<int>* rightChild = takeInputRecursive();
    root->left=leftChild;
    root->right = rightChild;
    return root;
}
// TAKING INPUT IN BINAY TREE LEVEL WISE
TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.empty()==false){
        TreeNode<int>* frontNode = q.front();
        q.pop();
        int leftChildData;
        cout << "Enter the left child of " << frontNode->data << " ";
        cin >> leftChildData;
        if(leftChildData!=-1){
            TreeNode<int>* leftChildNode = new TreeNode<int>(leftChildData);
            q.push(leftChildNode);
            frontNode->left = leftChildNode;
        }
        int rightChildData;
        cout << "Enter the right child of" << frontNode->data << " ";
        cin >> rightChildData;
        if(rightChildData!=-1){
            TreeNode<int>* rightChildNode = new TreeNode<int>(rightChildData);
            q.push(rightChildNode);
            frontNode->right=rightChildNode;
        }
    }
    return root;
}
int main(){
    // CREATING THE TREE NODES DYNAMICALLY
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* n1 = new TreeNode<int>(2);
    TreeNode<int>* n2 = new TreeNode<int>(3);
    // MAKING CONNECTIONS BETWEEN THE NODES
    root->left=n1;
    root->right=n2;
    
}

int findMax(vector<int> arr, int k){
    int n = arr.size();
    int ptr=0;
    int ans=-1;
    int zero =0;
    for(int i = 0; i<n ; i++){
        if(arr[i]==0){
            zero++;
        }
        while(zero>k){
            if(arr[ptr]==0){
                zero--;
            }
            ptr++;
        }
        ans = max(ans,i-ptr+1);
    }
}