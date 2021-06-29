vector <int> postOrder(Node* root){
    vector<int>ans;
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        Node *cur= st.top();
        st.pop();
        ans.push_back(cur->data);
        if(cur->left!=NULL){
            st.push(cur->left);
        }
        if(cur->right!=NULL){
            st.push(cur->right);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
