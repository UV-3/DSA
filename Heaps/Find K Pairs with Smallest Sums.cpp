// SUPER DUPER AWESOME QUESTION
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& v1, vector<int>& v2, int k) {
        int n=v1.size();
        int m= v2.size();
        vector<vector<int>>ans;
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>> >q;
        set<pair<int,int>>st;
        st.insert({n-1,m-1});
        q.push({v1[n-1]+v2[m-1],{n-1,m-1}});
        for(int l=0;l<k;l++){
            if(q.empty()){
                break;
            }
            int s=q.top().second.first;
            int e=q.top().second.second;
            ans.push_back({v1[s],v2[e]});
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
};
