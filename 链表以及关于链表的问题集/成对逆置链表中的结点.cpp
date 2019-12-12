
//递归思路
struct ListNode *ReversePairRecursive(struct ListNode *head){
	struct ListNode *temp;
	if(head == NULL || head->next ==NULL)
		return;
	else{
		//逆置第一对结点
		temp = head->next;
		head->next = temp->next;
		temp->next = head;
		head = temp;
		//对剩余部分递归调用该方法
		head->next = ReversePairRecursive(head->next->next);
		reutrn head;
	}
}

//迭代思路
struct ListNode *ReversePairIterative(struct ListNode *head){
	struct ListNode *temp1 = NULL, *temp2 = NULL, *current = head;
	
	while(current != NULL && current != NULL){
		if(temp1!=NULL)
			temp1->next->next = current->next;
		temp1 = current->next;
		current->next = current->next->next;
		temp1->next = current;
		if(temp2 == NULL)
			temp2 = temp1;
		current = current->next;
	}
	return temp2;
}
