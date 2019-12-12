struct BinaryTreeNode *InorderSuccessor(struct BinaryTreeNode *node){
	static struct BinaryTreeNode *P;
	static Stack *S = CreateStack();
	if(node != NULL)
		P = node;
	if(p->right != NULL){
		P = Pop(S);
	}
	else{
		P = P->right;
		while(P->right == NULL)
			Push(S,P);
		p = p->left;
	}
	return P;
}