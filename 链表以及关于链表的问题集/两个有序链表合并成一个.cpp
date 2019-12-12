//利用递归的方法
struct ListNode *MergeSortedList(struct ListNode *a, struct ListNode *b){
	struct ListNode *result = NULL;
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	if(a->data <= b->data){
		result = a;
		result->next = MergeSortedList(a->next,b);
	}
	else{
		result=b;
		result->next = MergeSortedList(a,b->next);
	}
	return result;
}

//利用迭代的思路
struct ListNode *MergeSortedListIterative(struct ListNode *head1, struct ListNode *head2){
	struct ListNode * newNode = (struct ListNode *)(malloc(sizeof(struct ListNode)));
	struct ListNode *temp;
	newNode = new Node;  /* 此处有疑问，是否有问题*/
	newNode->next = NULL;
	temp = newNode;
	while(head1 && head2){
		if(head1->data <= head2->data){
			temp->next = head1;
			temp = temp->next;
			head1 = head1->next;
		}
		else{
			temp->next = head2;
			temp = temp->next;
			head2 = head2->next;
		}
	}
	if(head1==NULL){
		temp->next = head2;
	}
	else
		temp->next = head1;
	temp = newNode->next;
	free(newNode);
	return temp;
}



















