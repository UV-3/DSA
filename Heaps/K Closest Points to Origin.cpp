class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<double,pair<int,int>> , vector<pair<double,pair<int,int>>> >q;
        for(int i=0;i<points.size();i++){
            double x= points[i][0], y= points[i][1];
            double d= sqrt(x*x+ y*y);
            q.push({d,{points[i][0],points[i][1]}});
            if(q.size()>k){
                q.pop();
            }
        }
        vector<vector<int>>ans;
        while(!q.empty()){
            int x= q.top().second.first, y= q.top().second.second;
            ans.push_back({x,y});
            q.pop();
        }
        return ans;
    }
};
