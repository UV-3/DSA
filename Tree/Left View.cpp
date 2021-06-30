vector<int> leftView(Node *root)
{
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
       int s=q.size();
       ans.push_back(q.front()->data);
       for(int i=0;i<s;i++){
           Node * p= q.front();
           q.pop();
           if(p->left!=NULL){
               q.push(p->left);
           }
           if(p->right!=NULL){
               q.push(p->right);
           }
       }
   }
   return ans;
}
-----------------------------------------------(Recursive solution)
class Solution
{
public:
    //Function to return list containing elements of right view of binary tree.
    void calc(Node* root,int lev, int &mx, vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(mx<lev){
            mx=lev;
            ans.push_back(root->data);
        }
        calc(root->left,lev+1,mx,ans);
        calc(root->right,lev+1,mx,ans);
    }
    vector<int> leftView(Node *root)
    {
        vector<int>ans;
        int mx=0;
        calc(root,1,mx,ans);
        return ans;
    }
};
