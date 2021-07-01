const int N=2e5+5;
vector<int>adj[N];
vector<int>col(N,-1);
// imp -> instead of using visited array we use color array(most imp step)
bool dfs(int v){
    if(col[v]==-1){
        col[v]=1;
    }
    for(int u:adj[v]){
        if(col[u]==-1){
            col[u]=1-col[v];
            if(!dfs(u)){
                return false;
            }
        }
        else if(col[u]==col[v]){
            return false;
        }
    }
    return true;
}
bool check(int n){
    for(int i=0;i<n;i++){
        if(col[i]==-1){
            if(!dfs(i))return false;
        }
    }
    return true;
}