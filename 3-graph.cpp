#include<bits/stdc++.h>
using namespace std;


// breadth first search in graph 
vector<int> bfsGraph(int V, vector<int> adjLs[]){
    queue<int> q; // queue
    vector<int> ans; // ans 
    q.push(0);
    vector<bool> vis(V,false); // visited array
    vis[0]=true;
    int node;
    while(!q.empty()){
        node = q.front();
        q.pop();
        ans.push_back(node);
        for(int i = 0; i<adjLs[node].size() ; i++){
            if(vis[adjLs[node][i]]==false){
                vis[adjLs[node][i]]==true;
                q.push(adjLs[node][i]);
            }
        }
    }
    return ans;
}

// Depth first search in graph 
void dfs(int node, vector<int> adj[],vector<bool> &vis, vector<int> &ans){
    vis[node]=true;
    ans.push_back(node);
    for(int i = 0; i<adj[node].size() ; i++){
        if(vis[adj[node][i]]==false){
            dfs(adj[node][i],adj,vis,ans);
        }
    }
}
vector<int> dfsGraph(int V, vector<int> adj[]){
    int start=0;
    vector<int> ans;
    vector<bool> vis(V,false);
    dfs(start,adj,vis,ans);
    return ans;
}

int main(){
    int n; // number of nodes 
    int m; // number of edges
    cin >> n >> m;
    int adjMat[n+1][m+1]; // defining the ajdacency matrix
    // initialising the matrix to zero
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m ; j++){
            adjMat[i][j]=0;
        }
    }
    // adding the connections between the vertices
    for(int i = 0; m ; i++){
        int u,v;
        cin >> u >> v;
        adjMat[u][v]=1;
        adjMat[v][u]=1;
    }
    vector<vector<int>> adjList(n+1); // defining the adjacency list 
    for(int i = 0; i<m ; i++){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
// =========================================== // 
// CYCLE DETECTION USING DFS
// =========================================== // 
bool checkForCycle(int node, int parent, vector<bool>&visited,vector<int> adj[]){
    visited[node]=true;
    for(int i=0;i<adj[node].size();i++){
        int neighbor = adj[node][i];
        if(neighbor==parent){
            continue;
        }
        if(visited[neighbor]==true){
            return true;
        }
        if(visited[neighbor]==false){
            if(checkForCycle(neighbor,node,visited,adj)==true){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]){
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            if(checkForCycle(i,-1,visited,adj)==true){
                return true;
            }
        }
    }
    return false;
}
// =========================================== // 
// CYCLE DETECTION USING BFS
// =========================================== // 
bool checkForCycleBFS(vector<int> adj[], vector<bool> &visited, int node){
    visited[node]= true;
    queue<pair<int,int>> q;
    q.push(make_pair(node,-1));
    while(q.empty()==false){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(int i=0;i<adj[node].size();i++){
            int neighbor = adj[node][i];
            if(neighbor==parent){
                continue;
            }
            if(visited[neighbor]==true){
                return true;
            }
            if(visited[neighbor]==false){
                visited[neighbor]=true;
                q.push(make_pair(neighbor,node));
            }
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]){
    vector<bool> visited(V,false);
    for(int i = 0; i<V ; i++){
        if(visited[i]==false){
            if(checkForCycleBFS(adj,visited,i)==true){
                return true;
            }
        }
        return false;
    }
}
// =========================================== // 
// TOPOLOGICAL SORT USING DFS
// =========================================== // 
void dfsTopSort(int node, vector<bool>&visited, vector<int> adj[],stack<int> &s){
    visited[node]=true;
    for(int i=0;i<adj[node].size();i++){
        if(visited[adj[node][i]]==false){
            dfsTopSort(adj[node][i],visited,adj,s);
        }

    }
    s.push(node);

}
vector<int> topologicalSortDFS(int V, vector<int> adj[]){
    vector<bool> visited(V,false);
    stack<int> s;
    vector<int> ans;
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            dfsTopSort(i,visited,adj,s);
        }
    }
    while(s.empty()==false){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
// =========================================== // 
// TOPOLOGICAL SORT USING BFS ( KAHN"S ALGORITHM )
// =========================================== // 
vector<int> kahnsAlgorithm(int V, vector<int> adj[]){
    vector<int> ans;
    vector<int> inDegree(V,0);
    for(int i=0;i<V;i++){
        for(int j=0;j<adj[i].size();j++){
            int node = adj[i][j];
            inDegree[node]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    while(q.empty()==false){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        int n = adj[node].size();
        for(int i=0;i<n;i++){
            int neighbor = adj[node][i];
            inDegree[neighbor]--;
            if(inDegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    return ans;
}
// =========================================== // 
// DETECT CYCLE IN DIRECTED GRAPH DFS
// =========================================== // 
bool detectCycle(int node, vector<int> adj[], vector<bool >&visited, vector<bool>&path){
    visited[node]=true;
    path[node]=true;
    int n = adj[node].size();
    for(int i = 0; i<n ; i++){
        int neighbor = adj[node][i];
        if(path[neighbor]==true){
            return true;
        }
        if(visited[neighbor]==true){
            continue;
        }
        if(visited[neighbor]==false){
            if(detectCycle(neighbor,adj,visited,path)==true){
                return true;
            }
        }
    }
    path[node]=false;
    return false;

}
bool isCyclic(int V, vector<int> adj[]){
    vector<bool> path(V,false);
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            if(detectCycle(i,adj,visited,path)==true){
                return true;
            }
        }
    }
    return false;
}
// =========================================== // 
// DETECT CYCLE IN DIRECTED GRAPH BFS ( KAHNS ALGORITHM)
// =========================================== // 

bool isCycle(int V, vector<int> adj[]){
    vector<int> inDegree(V,0);
    for(int i=0;i<V;i++){
        for(int j=0;adj[i].size();i++){
            inDegree[adj[i][j]]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(q.empty()==false){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int i=0;i<adj[node].size();i++){
            int neighbor = adj[node][i];
            inDegree[neighbor]--;
            if(inDegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    int count = ans.size();
    if(count!=V){
        return true;
    }
    else{
        return false;
    }
}
// =========================================== // 
// BIPARTITE GRAPH USING BFS
// =========================================== // 
bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            color[i]=0;
	            q.push(i);
	            while(q.empty()==false){
	                int node = q.front();
	                q.pop();
	                int n = adj[node].size();
	            for(int j=0;j<n;j++){
	                int neighbor = adj[node][j];
	                if(color[neighbor]==-1){
	                    color[neighbor]=1-color[node];
	                    q.push(neighbor);
	                }
	                else{
	                    if(color[node]==color[neighbor]){
	                        return false;
	                    }
	                }
	            }
	        }
        }
	}
	return true;
}
// =========================================== // 
// BIPARTITE GRAPH USING DFS
// =========================================== // 
bool check(int node, vector<int>& color, vector<int> adj[]) {
    int n = adj[node].size();
    for (int i = 0; i < n; i++) {
        int neighbor = adj[node][i];
        if (color[neighbor] == -1) {
            color[neighbor] = 1 - color[node];
            if (!check(neighbor, color, adj)) {
                return false;
            }
        } else {
            if (color[node] == color[neighbor]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[]) {
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            if (!check(i, color, adj)) {
                return false;
            }
        }
    }
    return true;
}
// =========================================== // 
// COVID SPREAD
// =========================================== // 
int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,-1,1};
int r,c;
bool valid(int i,int j){
    return i>=0 && i < r && j>=0 && j<c;
}
int function(vector<vector<int>> hospital){
    r = hospital.size();
    c = hospital[0].size();
    queue<pair<int,int>> q;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(hospital[i][j]==2){
                q.push(make_pair(i,j));
            }
        }
    }
    int time = 0;
    while(q.empty()==false){
        int currentCovidPatients = q.size();
        time++;
        while(currentCovidPatients--){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int ni = i+rows[k];
                int nj = j+cols[k];
                if(valid(ni,nj)&&hospital[ni][nj]==1){
                    hospital[ni][nj]==2;
                    q.push(make_pair(ni,nj));
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(hospital[i][j]==1){
                    return -1;
                }
            }
        }
        int ans = time-1;
        return ans;
    }
}
//=======================================//
// REPLACE O'S WITH X'S //
// =====================================//
    int r;
    int c;
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,-1,1};
    bool valid(int i, int j){
        return i>=0 && i < r && j>=0 && j < c;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        r = n ;
        c = m ;
        queue<pair<int, int>> q;
        for(int i=0;i<c;i++){
            if(mat[0][i]=='O'){
                mat[0][i]='T';
                q.push(make_pair(0,i));
            }
        }
        for(int i=1;i<r;i++){
            if(mat[i][0]=='O'){
                mat[i][0]='T';
                q.push(make_pair(i,0));
            }
        }
        for(int i=1;i<r-1;i++){
            if(mat[i][c-1]=='O'){
                mat[i][c-1]='T';
                q.push(make_pair(i,c-1));
            }
        }
        for(int i=1;i<c;i++){
            if(mat[r-1][i]=='O'){
                mat[r-1][i]='T';
                q.push(make_pair(r-1,i));
            }
        }
        while(q.empty()==false){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int newRow = i + row[k];
                int newCol = j + col[k];
                if(valid(newRow, newCol)&&mat[newRow][newCol]=='O'){
                    q.push(make_pair(newRow,newCol));
                    mat[newRow][newCol]='T';
                }
            }
            
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]=='O'){
                    mat[i][j]='X';
                }
                if(mat[i][j]=='T'){
                    mat[i][j]='O';
                }
            }
        }
        return mat;
        
    }
// =========================================== // 
// NUMBER OF ISLANDS
// =========================================== // 
int row[] = {-1, 1, 0, 0}; // Offsets for rows (up, down, left, right)
int col[] = {0, 0, -1, 1}; // Offsets for columns (up, down, left, right)
bool valid(int newRow, int newCol, vector<vector<char>>& grid) {
    return newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == '1';
}
int numIslands(vector<vector<char>>& grid) {
    r = grid.size();
    if (r == 0) return 0;
    c = grid[0].size();
    int count = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '1') {
                count++;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                grid[i][j] = '0';
                while (!q.empty()) {
                    int rowIndex = q.front().first;
                    int colIndex = q.front().second;
                    q.pop();
                    for (int k = 0; k < 8; k++) {
                        int newRow = rowIndex + row[k];
                        int newCol = colIndex + col[k];
                        if (valid(newRow, newCol, grid)) {
                            grid[newRow][newCol] = '0'; // Mark as visited
                            q.push(make_pair(newRow, newCol));
                        }
                    }
                }
            }
        }
    }
    return count;
}