// LOGIC-> dfsvis marks those nodes which are curently present in the dfs call as soon as
// dfs call is over dfsvis is unmarked 
// cycle exists when an adjacent node of a node is visited and is also present in dfs call (dfsvis) 
const int N=2e5+5;

vector<int>adj[N];
vector<bool>vis(N,false);
vector<bool>dfsvis(N,false);

bool dfs(int v){
    vis[v]=true;
    dfsvis[v]=true;
    for(int u:adj[v]){
        if(!vis[u]){
            if(dfs(u)){
                return true;
            }
        }
        else if(dfsvis[u]){
            return true;
        }
    }
    dfsvis[v]=false;
    return false;
}
bool check(int n){
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i))return true;
        }
    }
    return true;
}
