//先序遍历
void PreOrder( struct BinaryTreeNode *root){
	if(root){
		printf("%d",root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

//中序遍历
void Inorder(struct BinaryTreeNode *root ){
	if(root){
		Inorder(root->left);
		printf("%d",root->data);
		Inorder(root->right);
	}
}

//后序遍历
void PostOrder(struct BinaryTreeNode *root){
	if(root){
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d",root->data);
	}
}

//层次遍历
/* 层次遍历定义如下：
1.访问根节点
2.在遍历l层结点的同时，将l+1层的结点依次插入队列中
3.访问下一层的结点
4.重复上述过程直到所有层上的结点均被访问
*/
void LevelOrder(strcut BinaryTreeNode *root){
	struct BinaryTreeNode *temp;
	struct Queue *Q = CreatQueue();
	if(!root)
		return;
	EnQueue(Q,root);
	while(!isEmptyQueue(Q)){
		temp = DeQueue(Q);
		
		//处理当前结点
		printf("%d",temp->data);
		if(temp->left)
			EnQueue(Q,temp->left);
		if(temp->right)
			EnQueue(Q,temp->right);
	}
	DeleteQueue(Q);
}




















