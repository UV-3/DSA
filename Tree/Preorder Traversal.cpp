vector <int> preorder(Node* root){
    stack<Node*>st;
    st.push(root);
    vector<int>ans;
    while(!st.empty()){
        Node *cur= st.top();
        ans.push_back(cur->data);
        st.pop();
        if(cur->right!=NULL){
            st.push(cur->right);
        }
        if(cur->left!=NULL){
            st.push(cur->left);
        }
    }
    return ans;
}
