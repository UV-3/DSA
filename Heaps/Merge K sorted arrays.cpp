vector<int> Solution::solve(vector<vector<int> > &a) {
    // O(n*k*log(k))
    int k=a.size(),n=a[0].size();
    // min heap of pii
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
    for(int i=0;i<k;i++){
        q.push({a[i][0],i});
    }
    vector<int>ans;
    vector<int>ind(k,0);// stores the current index of smallest element
    while(!q.empty()){
        int j= q.top().second;
        ans.push_back(q.top().first);
        q.pop();
        if(ind[j]+1<n){
            ind[j]++;
            q.push({a[j][ind[j]],j});
        }
    }
    return ans;
}
