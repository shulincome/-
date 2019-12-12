/*利用递归*/
int FindMax(struct BinaryTree *root){
	int root_val,left,right,max=INT_MIN;
	if(root != NULL){
		root_val = root->data;
		left = FindMax(root->left);
		right = FindMax(root->right);
		//查找树的最大元素
		if(left > right)
			max = left;
		else
			max = right;
		if(root_val > max)
			max = root_val;
	}
	return max;
}

/* 利用层次遍历*/

int FindMaxUsingLevelOrder(struct BinaryTree *root){
	struct BinaryTree *temp;
	int max = INT_MIN;
	struct Queue *Q = CreateQueue();
	EnQueue(Q,root);
	while(!IsEmptyQueue(Q)){
		temp = DeQueue(Q);
		
		if(max < temp->data)
			max = temp->data;
		
		if(temp->left)
			EnQueue(Q,temp->left);
		
		if(temp->right)
			EnQueue(Q,temp->right);
		
	}
	DeleteQueue(Q);
	
	return max;
}