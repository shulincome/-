//为了插入一个元素，我们需要二叉树的层次遍历，将元素插入遍历过程中遇到的第一个无左孩子或无有孩子的结点的左指针域中。
void  InsertInBinaryTree(struct BinaryTreeNode *root , int data){
	struct BinaryTreeNode *temp;
	struct Queue *Q;
	struct BinaryTreeNode *newNode;
	newNode = (struct BinaryTree *)malloc(sizeof(struct BinaryTreeNode));
	newNode->left = newNode->right = NULL;
	if(!newNode){
		printf("Memory Error");
		return ;
	}
	if(!root){
		root = newNode;
		return;	
	}
	Q = CreateQueue();
	EnQueue(Q,root);
	while(!IsEmptyQueue(Q)){
		temp = DeQueue(Q);
		if(temp->left)
			EnQueue(Q,temp->left);
		else{
			temp->left = newNode;
			DeleteQueue(Q);
			return;
		}
		if(temp->right)
			EnQueue(Q,temp->right);
		else{
			temp->right = newNode;
			DeleteQueue(Q);
			return;
		}
	}
	DeleteQueue(Q);
		
}










