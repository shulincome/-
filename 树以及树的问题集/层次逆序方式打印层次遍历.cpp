// 显示结果为 1234567 ---->> 4567 23 1
void LevelOrderTraversalInReverse(struct BinaryTreeNode *root){
	struct Queue *Q;
	struct Stack *s = CreatStack();
	struct BinaryTreeNode *temp;
	if(!root)
		return ;
	Q = CreatQueue();
	EnQueue(Q,root);
	while(!IsEmptyQueue(Q)){
		temp = DeQueue(Q);
		if(temp->left)
			EnQueue(Q,temp->left);
		if(temp->right)
			EnQueue(Q,temp->right);
		Push(s,temp);
	}
	while(!IsEmptyStack(s)){
		printf("%d",Pop(s->data));
	}
}