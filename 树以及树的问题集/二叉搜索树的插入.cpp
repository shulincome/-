struct BinarySreachTreeNode* Insert(struct BinarySreachTreeNode *root, int data){
	if(root == NULL){
		root = (struct BinarySreachTreeNode *) malloc(sizeof(struct BinarySreachTreeNode));
		if(root == NULL){
			printf("Memory Error");
			return ;
		}
		else{
			root->data = data;
			root->left = roo->right = NULL;
		}
	}
	else{
		if(data < root->data)
			root->left = Insert(root->left,data);
		else if(data > root->data)
			root->right = Insert(root->right, data);
	}
	return root;
}