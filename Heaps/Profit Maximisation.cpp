int Solution::solve(vector<int> &v, int k) {
    priority_queue<int,vector<int>>q;
    for(int i=0;i<v.size();i++){
        q.push(v[i]);
    }
    int ans=0;
    for(int i=0;i<k;i++){
        if(q.top()==0){
            break;
        }
        int e= q.top();
        ans+=e;
        q.pop();
        q.push(e-1);
    }
    return ans;
}
