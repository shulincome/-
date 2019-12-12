// 利用二叉树的后序遍历
void DeleteBinaryTree(struct BinaryTree *root){
	if(root == NULL)
		return;
	DeleteBinaryTree(root->left);
	DeleteBinaryTree(root->right);
	free(root);
}