class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node *root, int &ans){
        if(root==NULL){
            return 0;
        }
        int lh= height(root->left,ans);
        int rh=height(root->right,ans);
        ans= max(ans,lh+rh+1);
        return 1+max(lh,rh);
    }
    int diameter(Node* root) {
        int ans=0;
        int v= height(root,ans);
        return ans;
    }
};

