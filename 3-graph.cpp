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