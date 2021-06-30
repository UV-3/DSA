vector <int> bottomView(Node *root)
{
    vector<int>ans;
   if(root==NULL){
       return ans;
   }
   queue<pair<Node*,int>>q;
   map<int,int>m;
   q.push({root,0});
   while(!q.empty()){
       pair<Node*,int>p=q.front();
       q.pop();
       Node *n= p.first;
       int hd= p.second;
       m[hd]=n->data;
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
