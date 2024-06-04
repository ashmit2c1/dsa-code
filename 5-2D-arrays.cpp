#include<bits/stdc++.h>
using namespace std;
// =========================================== // 
// MATRIX MULTIPLICATION
// =========================================== // 
void matrixMultiplicaton(){
    int r1,c1;
    cin >> r1 >> c1;
    int matrixA[r1][c1];
    for(int i = 0; i<r1 ; i++){
        for(int j=0;j<c1;j++){
            cin >> matrixA[i][j];
        }
    }
    int r2,c2;
    cin >> r2 >> c2;
    int matrixB[r2][c2];
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin >> matrixB[i][j];
        }
    }
    // condition to check if multiplication is possible or not
    if(c1!=r2){
        cout << "Matrix Multiplication is not possible" << "\n";
        return;
    }
    int ans[r1][c2];
    for(int i=0;i<r1;i++){
        for (int j=0;j<c2;j++){
            int value=0;
            for(int k = 0 ; k<r2;k++){
                value+=(matrixA[i][k]*matrixB[k][j]);
            }
            ans[i][j]=value;
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            cout << ans[i][j] << " | ";
        }
        cout << "\n";
    }
}
// =========================================== // 
// TRANSPOSE OF MATRIX
// =========================================== // 
void transpose(){
    int r,c;
    cin >> r >> c;
    int matrix[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> matrix[i][j];
        }
    }
    int transmat[c][r];
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            transmat[i][j] = matrix[j][i];
        }
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            cout << transmat[i][j] << " | ";
        }
        cout << "\n";
    }
}
// =========================================== // 
// DIAGONAL SUM OF MATRIX
// =========================================== // 
void diagonalSum(){
    int rows;
    int cols;
    cin >> rows >> cols;
    int mat[rows][cols];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin >> mat[i][j];
        }
    }
    int first = 0 ;
    int second =0 ;
    int index =0 ;
    int colIndex =0 ;
    while(index<rows){
        first+=mat[index][index];
        index++;
    }
    index=0;
    while(colIndex>=0){
        second+=mat[index][colIndex];
        index++;
        colIndex--;
    }
    int ans = first+second;
    cout << ans << "\n";
}
// =========================================== // 
// PRINT THE SPIRAL ORDER OF MATRIX
// =========================================== // 
vector<int> spiralOrder(vector<vector<int>> &mat, int r,int c){
    int rows = mat.size();
    int cols = mat[0].size();
    int top = 0;
    int left = 0;
    int right = cols-1;
    int bottom = rows-1;
    vector<int> ans;
    while(top<=bottom && left<=right){
        // printing the top row
        for(int i=left;i<=right;i++){
            ans.push_back(mat[top][i]);
        }
        top++;
        // printing the right row
        for(int i=top;i<=bottom;i++){
            ans.push_back(mat[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
}
// =========================================== // 
// ROTATE A MATRIX BY 90 CLOCKWISE
// =========================================== // 
void rotate(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    // finding the transpose of the matrix
    for(int i=0;i<rows;i++){
        for(int j=i+1;j<cols;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<rows;i++){
        int start=0;
        int end = cols-1;
        while(start<end){
            swap(matrix[i][start],matrix[i][end]);
            start++;
            end--;
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
// =========================================== // 
// BINARY SEARCH IN 2D Matrix
// =========================================== // 
bool isPresent(vector<vector<int>> &matrix, int X){
    int rows = matrix.size();
    int cols = matrix[0].size();
    for(int i=0;i<rows;i++){
        int start=0;
        int end = cols-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(matrix[i][mid]==X){
                return true;
            }
            if(matrix[i][mid]>X){
                end = mid-1;
            }
            if(matrix[i][mid] < X){
                start = mid+1;
            }
        }
    }
    return false;
}
int main(){
    
}