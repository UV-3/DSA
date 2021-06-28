int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int,vector<int>>q;
    for(int i=0;i<B.size();i++){
        q.push(B[i]);
    }
    long long ans=0;
    const int mod=1e9+7;
    for(int i=0;i<A;i++){
        int r= q.top();
        ans = (ans+ r)%mod;
        q.pop();
        q.push(r/2);
    }
    return ans;
}
