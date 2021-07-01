// LOGIC-> IF ADJACENT NODE OF A NODE IS COLORED AND IS COLORED WITH THE SAME COLOR THEN GRAPH IS NOT PARTITTE
const int N=2e5+5;

vector<int>adj[N];
vector<int>col(N,-1);

bool bfs(int s){
    queue<int>q;
    q.push(s);
    col[s]=1;
    while(!q.empty()){
        int v= q.front();
        q.pop();
        for(auto u:adj[v]){
            if(col[u]==-1){
                col[u]=1-col[v];
                q.push(u);
            }
            else if(col[u]==col[v]){
                return false;
            }
        }
    }
    return true;
}
bool check(int n){
    for(int i=0;i<n;i++){
        if(!bfs(i)){
            return false;
        }
    }
    return true;
}
