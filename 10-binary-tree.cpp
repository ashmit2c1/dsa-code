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
// LEVEL ORDER TRAVERSL IN BINARY TREE
vector<vector<int>> levelOrderTraveralBinaryTree(TreeNode<int>* root){
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.empty()==false){
        vector<int> level;
        int n = q.size();
        for(int i = 0; i<n ; i++){
            TreeNode<int>* frontNode = q.front();
            if(frontNode->left!=NULL){
                q.push(frontNode->left);

            }
            if(frontNode->right!=NULL)
            {
                q.push(frontNode->right);
            }
            level.push_back(frontNode->data);
        }
        ans.push_back(level);
    }
    return ans;
}
// COUNT NUMBER OF NODES PRESENT IN BINARY TREE
int countNodesBinaryTree(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return countNodesBinaryTree(root->left) + countNodesBinaryTree(root->right)+1;
}
// INORDER TRAVERSAL OF BINARY TREE
void inOrder(TreeNode<int>* root, vector<int> &v){
    if(root==NULL){
        return;
    }
    inOrder(root->left,v);
    v.push_back(root->data);
    inOrder(root->right,v);
}

vector<int> inOrderTraversalBinaryTree(TreeNode<int>* root){
    vector<int> ans;
    inOrder(root,ans);
    return ans;
}
// MAX DEPTH OR HEIGHT OF BINARY TREE
int maxDepth(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    int height = max(maxDepth(root->left),maxDepth(root->right));
    return height+1;
}
// CHECK WHETHER A PARTICULAR VALUE IS PRESENT IN BINARY TREE OR NOT
bool searchForKey(TreeNode<int>* root, int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    return (searchForKey(root->left,key) || searchForKey(root->right,key));
}
// FIND THE MINIUM VALUE IN BINARY TREE
int findMinValueBinaryTree(TreeNode<int>* root){
    if(root==NULL){
        return INT_MAX;
    }
    int ans = root->data;
    int leftMin = findMinValueBinaryTree(root->left);
    int rightMin = findMinValueBinaryTree(root->right);
    ans = min(ans,min(rightMin,leftMin));
    return ans;
}
// FIND THE MAX VALUE IN BINARY TREE
int findMaxValueBinaryTree(TreeNode<int>* root){
    if(root==NULL){
        return INT_MIN;
    }
    int ans = root->data;
    int leftMax = findMaxValueBinaryTree(root->left);
    int rightMax = findMaxValueBinaryTree(root->right);
    ans = max(ans,max(leftMax,rightMax));
    return ans;
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
