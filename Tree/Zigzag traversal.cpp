vector <int> zigZagTraversal(Node* root)
{
	vector<int>ans;
	if(root==NULL){
	    return ans;
	}
	queue<Node*>q;
	q.push(root);
	int par=0;
	while(!q.empty()){
	    int s=q.size();
	    vector<Node*>temp;
	    if(par%2==0){
	        for(int i=0;i<s;i++){
	            temp.push_back(q.front());
	            ans.push_back(q.front()->data);
	            q.pop();
	        }
	        for(int i=0;i<temp.size();i++){
	            if(temp[i]->left!=NULL){
	                q.push(temp[i]->left);
	            }
	            if(temp[i]->right!=NULL){
	                q.push(temp[i]->right);
	            }
	        }
	        par++;
	        par%=2;
	    }
	    else{
	        for(int i=0;i<s;i++){
	            temp.push_back(q.front());
	            q.pop();
	        }
	        reverse(temp.begin(),temp.end());
	        for(int i=0;i<temp.size();i++){
	            ans.push_back(temp[i]->data);
	        }
	        reverse(temp.begin(),temp.end());
	        for(int i=0;i<temp.size();i++){
	            if(temp[i]->left!=NULL){
	                q.push(temp[i]->left);
	            }
	            if(temp[i]->right!=NULL){
	                q.push(temp[i]->right);
	            }
	        }
	        par++;
	        par%=2;
	    }
	}
	return ans;
}
