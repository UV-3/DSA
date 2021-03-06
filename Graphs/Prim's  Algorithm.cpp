const int N=2e5+5;

vector<pair<int,int>>adj[N];

int key[N],parent[N];
bool mstSet[N];

void prim(int n){
    for(int i=0;i<n;i++){
        key[i]=INF;
        mstSet[i]=false;
    }
    // min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    key[0]=0;
    parent[0]=-1;
    q.push({0,0});
    while(!q.empty()){ // condition to prevent repetition
        int u=q.top().second;
        q.pop();
        mstSet[u]=true; // include this in the MST
        for(auto it:adj[u]){
            int v= it.first;
            int weight= it.second;
            if(mstSet[v]==false && weight<key[v]){
                parent[v]=u;
                key[v]=weight;
                q.push({key[v],v});
            }
        }
    }
}

// complexity of O(nlogn)
