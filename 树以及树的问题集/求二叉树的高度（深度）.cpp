// 类似于深度优先搜索
int HeightofBinaryTree(struct BinaryTreeNode *root){
	int leftheight, rightheight;
	if(root== NULL)
		return 0;
	else{
		/* 计算每颗子树的深度*/
		leftheight = HeightofBinaryTree(root->left);
		rightheight = HeightofBinaryTree(root->right);
		if(leftheight > rightheight)
			return (leftheight +1);
		else
			return (rightheight + 1);
	}
}

//类似于广度优先搜索
int FindHeightofBinaryTree(struct BinaryTreeNode *root){
	int level = 1;
	struct Queue *Q;
	if(!root)
		return 0;
	Q = CreateQueue();
	EnQueue(Q,root);
	while(!IsEmptyQueue){
		root = DeQueue(Q);
		//
		if(root == NULL){
			//
			if(!IsEmptyQueue(Q))
				EnQueue(Q,NULL);
			level++;
		}
		else{
			if(root->left)
				EnQueue(root->left);
			if(root->right)
				EnQueue(root->right);
		}
	}
	return level;
}