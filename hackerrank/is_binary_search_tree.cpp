vector<int>v;
	void inorder(Node* root){
		if(root){
			inorder(root->left);
			v.push_back(root->data);
			inorder(root->right);
   }        
}

bool checkBST(Node* root) {
       
       inorder(root);
       
       for(int i=0;i<v.size()-1;i++){
           //printf("%d ", v[i]);
           if(v[i]>=v[i+1])return false;
           
       }
       //printf("\n");
       return true;
}
