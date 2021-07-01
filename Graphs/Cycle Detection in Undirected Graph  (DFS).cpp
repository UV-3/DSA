const int N=2e5+5;

vector<bool>vis(N,false);
vector<int>adj[N];

bool dfs(int v, int par){
    vis[v]=true;
    for(int u:adj[v]){
        if(vis[u]==false){
            if(dfs(u,v)){ //most imp step
                return true;
            }
        }
        else if(u!=par){
            return true; // cycle exists when a next node which is already visited is not its parent
        }
    }
    return false;
}

bool check(int n){ // n is number of nodes
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            if(dfs(i,-1)){
                return true;
            }
        }
    }
    return false;
}
