//递归算法--搜索二叉树
int FindInBinaryTreeUsingRecursion(struct BinaryTree *root, int data){
	int temp;
	if(!root)
		return 0;
	else{
		if(temp == root->data)
			return 1;
		else{
			//否则在相应的子树进行递归
			temp = FindInBinaryTreeUsingRecursion(root->left, data)
			if(temp==1)
				return temp;
			else
				reutrn (temp = FindInBinaryTreeUsingRecursion(root->right, data));
		}
	}
	return 0;
}

//层次遍历--搜索二叉树
int SearchUsingLevelOrder(struct BinaryTree *root, int data){
	struct BinaryTree *temp;
	struct Queue *Q;
	if(!root)
		return 0;
	Q = CreateQueue();
	EnQueue(Q,root);
	while(!IsEmptyQueue(Q)){
		temp = DeQueue(Q);
		if(temp->data == data)
			return 1;
		if(temp->left)
			EnQueue(Q,temp->left);
		if(temp->right)
			EnQueue(temp->right);
	}
	DeleteQueue(Q);
	return 0;
}