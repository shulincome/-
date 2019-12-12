//采用递归的方法进行求解。
void PrintListFromEnd(struct ListNode *head){
	if(!head)
		return;
	PrintListFromEnd(head->next);
	printf("%d",head->data);
}