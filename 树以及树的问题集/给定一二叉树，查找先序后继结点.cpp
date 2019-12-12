//为了解决这个问题，我们需要使用一个辅助栈S。在从一次函数调用到下一次函数调用的过程中，
//栈S的内容和指向刚刚被访问的点指针P是必须被保存的。因此，我们将它们定义为静态变量。

struct BinaryTreeNode *PreorderSuccessor(struct BinaryTreeNode *node){
	static struct BinaryTreeNode *P;
	static Stack *S = CreateStack();
	if(node != NULL)
		P = node;
	if(p->left != NULL){
		Push(S,P);
		p = p->left;
	}
	else{
		while(P->right == NULL)
			P = Pop(S);
		P = p->right;
	}
	return P;
}