// 线索二叉树的数据结构
struct ThreadedBinaryTreeNode{
	struct ThreadedBinaryTreeNode *left;
	int LTag;
	int data;
	int RTag;
	struct ThreadedBinaryTreeNode *right;
};

//在线索二叉树中查找中序后继结点
struct ThreadedBinaryTreeNode* InorderSuccessor(struct ThreadedBinaryTreeNode *P){
	struct ThreadedBinaryTreeNode *Position;
	if(P->RTag == 0)
		return P->right;
	else{
		Position = p->right;
		while(Position->LTag == 1)
			Position  = Position->left;
		return Position;
	}
}