const int N=2e5+5;

vector<bool>vis(N,false);
vector<int>adj[N];
stack<int>st;

void dfs(int v){
    vis[v]=true;
    for(int u:adj[v]){
        if(!vis[u]){
            dfs(u);
        }
    }
    st.push(v);
}
vector<int> toposort(int n){
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
// toposort in directed acyclic graph(DAG)
