vector<int> Solution::solve(vector<int> &v, int k) {
    int n=v.size();
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=0;i<n;i++){
        q.push(v[i]);
        if(q.size()>k){
            q.pop();
        }
    }
    vector<int>ans;
    while(!q.empty()){
        ans.push_back(q.top());
        q.pop();
    }
    return ans;
}
