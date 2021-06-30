// O(nlogn) solution using map
vector<int> topView(Node *root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>m;  // hd, val
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        pair<Node*,int>p=q.front();
        Node *n= p.first;
        q.pop();
        int hd= p.second;
        if(!m.count(hd)){
            m[hd]=n->data;
        }
        if(n->left!=NULL){
            q.push({n->left,hd-1});
        }
        if(n->right!=NULL){
            q.push({n->right,hd+1});
        }
    }
    for(auto x:m){
        ans.push_back(x.second);
    }
    return ans;
    
}
// O(n) solution using min,max and unordered map
vector<int> topView(Node *root)
{
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    unordered_map<int,int>m;  // hd, val
    queue<pair<Node*,int>>q;
    q.push({root,0});
    int mx=-1e6;
    int mn=1e6;
    while(!q.empty()){
        pair<Node*,int>p=q.front();
        Node *n= p.first;
        q.pop();
        int hd= p.second;
        mx=max(mx,hd);
        mn=min(mn,hd);
        if(!m.count(hd)){
            m[hd]=n->data;
        }
        if(n->left!=NULL){
            q.push({n->left,hd-1});
            mx=max(mx,hd-1);
            mn=min(mn,hd-1);
        }
        if(n->right!=NULL){
            q.push({n->right,hd+1});
            mx=max(mx,hd+1);
            mn=min(mn,hd+1);
        }
    }
    for(int i=mn;i<=mx;i++){
        ans.push_back(m[i]);
    }
    return ans;
    
}

