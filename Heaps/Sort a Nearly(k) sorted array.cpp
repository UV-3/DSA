vector <int> nearlySorted(int arr[], int n, int k){
    vector<int>ans;
    // create a min heap
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=0;i<n;i++){
        q.push(arr[i]);
        if(q.size()>k){
            ans.push_back(q.top());
            q.pop();
        }
    }
    while(!q.empty()){
        ans.push_back(q.top());
        q.pop();
    }
    return ans;
}
