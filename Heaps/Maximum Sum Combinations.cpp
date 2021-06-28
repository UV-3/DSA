vector<int> Solution::solve(vector<int> &v1, vector<int> &v2, int k) {
    int n=v1.size();
    vector<int>ans;
    sort(v1.begin(),v1.end());  
    sort(v2.begin(),v2.end());
    priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> > q;
    set<pair<int,int>>st;
    st.insert({n-1,n-1});
    q.push({v1[n-1]+v2[n-1],{n-1,n-1}});
    for(int l=0;l<k;l++){
        ans.push_back(q.top().first);
        int s=q.top().second.first;
        int e=q.top().second.second;
        q.pop();
        if(s-1>=0  && st.find({s-1,e})==st.end()){
            st.insert({s-1,e});
            q.push({v1[s-1]+v2[e],{s-1,e}});
        }
        if(e-1>=0 && st.find({s,e-1})==st.end()){
            st.insert({s,e-1});
            q.push({v1[s]+v2[e-1],{s,e-1}});
        }
    }
    return ans;
}
