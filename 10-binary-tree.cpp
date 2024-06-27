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
// FIND THE NUMBER OF LEAF NODES IN BINARY TREE
int countLeafNodes(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    if(root->left && root->right==NULL){
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
// FIND THE DIAMETER OF GIVEN BINARY TREE
int height(TreeNode<int>* root, int &diameter){
    if(root==NULL){
        return 0;
    }
    int leftHeight = height(root->left,diameter);
    int rightHeight = height(root->right,diameter);
    diameter = max(diameter,leftHeight+rightHeight);
    return 1+(max(leftHeight,rightHeight));
}
int findDiameter(TreeNode<int>* root){
    int diameter = 0;
    height(root,diameter);
    return diameter+1;
}
// FIND THE SUM OF BINARY TREE ( given a binary tree find the sum of all nodes)
void total(TreeNode<int>* root, long &sum){
    if(root==NULL){
        return;
    }
    sum+=root->data;
    total(root->left,sum);
    total(root->right,sum);
}
long int sumBT(TreeNode<int>* root){
    long int sum;
    total(root,sum);
    return sum;

}
// SECOND MIND TO FIND THE SUM OF BINARY TREE WITH LESS LINES OF CODE 
long int sumBT2(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return root->data + sumBT2(root->right) + sumBT2(root->left);
}
// CHECK WHETHER THE GIVEN TWO BINARY TREE ARE IDENTICAL OR NOT 
bool isIdentical(TreeNode<int>* root1, TreeNode<int>* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL)){
        return false;
    }
    if(root1->data != root2->data){
        return false;
    }
    return isIdentical(root1->right, root2->right) && isIdentical(root1->left, root2->left);
}
// CONVERT A GIVEN BINARY TREE TO ITS MIRROR IMAGE  ( return the same tree )
void mirror(TreeNode<int>* &root){
    if(root==NULL){
        return;
    }
    TreeNode<int>* temp = root->right;
    root->right = root->left;
    root->left = temp ;
    mirror(root->left);
    mirror(root->right);
}
// CHECK FOR BALANCE SUB TREE
// a tree is called balance when the difference in height of left subtree and right subtree is greater 
// than -1 and less than 1 

int height(TreeNode<int>* root, bool &valid){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left, valid);
    int right = height(root->right,valid);
    if(abs(left-right)>1){
        valid = 0;
    }
    return 1+max(left,right);
}
bool isBalanced(TreeNode<int>* root){
    bool valid = 1;
    height(root,valid);
    return valid;
}
// LEVEL ORDER TRAVERSAL IN SPIRAL FORM 
vector<int> levelOrderSpiral(TreeNode<int>* root){

}
// CHECK IF TWO NODES ARE COUSING 

// LEFT VIEW OF BINARY TREE
vector<int> leftView(TreeNode<int>* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.empty()==false){
        int n = q.size();
        ans.push_back(q.front()->data);
        while(n--){
            TreeNode<int>* temp = q.front();
            q.pop();
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
    return ans;
}
// LEFT VIEW OF BINARY TREE USING RECURSION 
void LeftView(TreeNode<int>* root, int level ,vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(level==ans.size()){
         ans.push_back(root->data);
    }
    LeftView(root->left,level+1,ans);
    LeftView(root->right,level+1,ans);
}
vector<int> leftView(TreeNode<int>* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    LeftView(root,0,ans);
    return ans;
}
// RIGHT VIEW OF BINARY TREE 
vector<int> rightView(TreeNode<int>* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.empty()==false){
        int n = q.size();
        ans.push_back(q.front()->data);
        while(n--){
            TreeNode<int> * temp = q.front();
            q.pop();
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            if(temp->left!=NULL){
                q.push(temp->right);
            }
        }
    }
    return ans;
}

// RIGHT VIEW OF BINARY TREE USING RECURSION 
void RightView(TreeNode<int>* root, int level, vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(level==ans.size()){
        ans.push_back(root->data);

    }
    RightView(root->right,level+1,ans);
    RightView(root->left,level+1,ans);
}
vector<int> rightView(TreeNode<int>* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    RightView(root,0,ans);
    return ans;
     
}

// TOP VIEW OF BINARY TREE

// CONSTRUCT A BINARY TREE FROM INRODER AND PREORDER TRAVERSAL 
int find(int in[], int target, int start, int end){
        for(int i=start;i<=end;i++){
            if(in[i]==target){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode<int>* tree(int in[], int pre[], int InStart, int InEnd, int index){
        if(InStart > InEnd){
            return NULL;
        }
        TreeNode<int>* root = new TreeNode<int>(pre[index]);
        int pos = find(in, pre[index],InStart, InEnd);
        
        root->left = tree(in,pre,InStart,pos-1,index+1);
        root->right = tree(in,pre,pos+1,InEnd,index+(pos-InStart)+1);
        return root;
    }

    TreeNode<int>* buildTree(int in[], int pre[], int n) {
        return tree(in, pre, 0, n - 1, 0);
}
// CONSTRUCT A TREE FROM POST ORDER AND INORDER TRAVERSAL 
int find(int in[], int target, int start, int end){
        for(int i=start;i<=end;i++){
            if(in[i]==target){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode<int>* tree(int in[], int post[], int InStart, int InEnd, int index){
        if(InStart > InEnd){
            return NULL;
        }
        TreeNode<int>* root = new TreeNode<int>(post[index]);
        int pos = find(in, post[index],InStart, InEnd);

        root->right = tree(in,post,pos+1,InEnd,index-1);
        root->left = tree(in,post,InStart,pos-1,index-(InEnd-pos )-1);
        return root;
    }

    TreeNode<int>* buildTree(int in[], int post[], int n) {
        return tree(in, post, 0, n - 1, n-1);
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
