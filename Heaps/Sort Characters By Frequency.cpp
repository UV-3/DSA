string frequencySort(string s) {
        unordered_map<char,int>m;
        for(char c:s){
            m[c]++;
        }
        priority_queue< pair<int,char>  ,  vector<pair<int,char>> >q;
        for(auto x:m){
            q.push({x.second,x.first});
        }
        string ans="";
        while(!q.empty()){
            for(int i=0;i<q.top().first;i++){
                ans+=q.top().second;
            }
            q.pop();
        }
        return ans;
    }
