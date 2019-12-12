
struct ListNode *InsertInSortedList(struct ListNode *head, struct ListNode *newNode){
	struct ListNode *current=head,*temp;
	if(!head) //有序链表为空
		return newNode;
		//遍历链表直到当前结点的值大于新结点的值为止
	while(current!=NULL && current->data < newNode->data){
		temp = current;
		current = current->next;
	}
	//在current所指结点前面插入新结点
	newNode->next = current;
	temp->next = newNode;
	return head;
}