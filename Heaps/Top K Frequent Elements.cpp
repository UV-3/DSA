class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // O(n*logk)
        int n=nums.size();
        // min heap first element-> freq , second element-> number
        unordered_map<int,int>m;
        // NOTE ->
        // unordered_map uses hash table so insertion access and deletion is in O(1)
        // map or ordered_map used red black tree so insertion access and deletion if O(log n )
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >q;
        for(auto x:m){
            q.push({x.second,x.first});
            if(q.size()>k){
                q.pop();
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
