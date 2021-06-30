void calc(Node* root,map<int,vector<int>>&m, int s){
    if(root==NULL){
        return;
    }
    m[s].push_back(root->data);
    calc(root->left,m,s+1);
    calc(root->right,m,s);
}
vector<int> diagonal(Node *root)
{
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,vector<int>>m;
    calc(root,m,0);
    for(auto x:m){
        for(auto y:x.second){
            ans.push_back(y);
        }
    }
    return ans;
}
