//LOGIC -> a node i with indegree 0 will always come before any of its adjacent node
// after that node is considered we reduce the indegree of its adjacent nodes becuase the
// current node's dependency gets reduced on its adjacent
const int N=2e5+5;
vi adj[N];
vector<int>indegree(N);

vector<int> toposort(int n){
    for(int i=0;i<n;i++){
        for(auto u:adj[i]){
            indegree[u]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int v=q.front();
        ans.push_back(v);
        q.pop();
        for(auto u:adj[v]){
            indegree[u]--;
            if(indegree[u]==0){
                q.push(u);
            }
        }
    }
    return ans;
}
