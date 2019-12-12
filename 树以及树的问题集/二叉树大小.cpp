//递归算法
int SizeofBinaryTree(struct BinaryTreeNode *root){
	if(root==NULL)
		return 0;
	else return(SizeofBinaryTree(root->left) + 1 + SizeofBinaryTree(root-right));
}

//可以试试二叉树的层次遍历
int SizeofBTUsingLevelOrder(struct BinaryTreeNode *root){
	struct BinaryTreeNode *temp;
	struct Queue *Q;
	int count = 0;
	if(!root)
		return 0;
	Q = CreateQueue();
	EnQueue(Q,root);
	while(!IsEmptyQueue(Q)){
		temp = DeQueue(Q);
		count ++;
		if(temp->left)
			EnQueue(temp->left);
		if(temp->right)
			EnQueue(temp->right);
	}
	DeleteQueue();
}