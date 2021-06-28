class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        int n=a.size();
        priority_queue<pair<int,int>, vector<pair<int,int>> >q;
        // max heap of size k
        for(int i=0;i<n;i++){
            q.push({abs(a[i]-x),a[i]});
            if(q.size()>k){
                q.pop();
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
