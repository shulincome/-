//分三种情况考虑：1.叶子结点 2.结点有一个孩子 3.结点有两个孩子

struct BinarySearchTreeNode *Delete(struct BinaryTreeNode *root, int data){
	struct BinaryTreeNode *temp;
	
	if(root == NULL)
		printf("Element not there in tree");
	else if(data < root->data)
		root->left = Delete(root->left,data);
	else if(data > root->data)
		root->right = Delete(root->roght, data);
	else{
		//查找元素
		if(root->left && root->right){
			temp = FindMax(root->left);
			root->data = temp->data;
			root->left = Delete(root->left,root->data);
		}
		else{
			/* 一个孩子*/
			temp = root;
			if(root->left == NULL)
				root = root->right;
			
			if(root->right == NULL)
				root = root->left;
			
			free(temp);
		}
	}
	return root;
}