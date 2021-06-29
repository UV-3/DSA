vector<int> inOrder(Node* root) {
    vector<int>ans;
    stack<Node*>st;
    Node* cur=root;
    while(!st.empty() || cur!=NULL){
        if(cur!=NULL){
            st.push(cur);
            cur=cur->left;
        }
        else{
            cur=st.top();
            st.pop();
            ans.push_back(cur->data);
            cur=cur->right;
        }
    }
    return ans;
}
