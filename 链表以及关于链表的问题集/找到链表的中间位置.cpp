//利用两个指针，一个是另一个指针速度的两倍
struct ListNode * FindMiddle(struct ListNode *head){
	srtuct ListNode *ptr1x,*ptr2x;
	ptr1x = ptr2x = head;
	int i = 0;
	//持续循环过程直到ptr1x到达表尾为止（最后一个结点的next指针为NULL）
	while(ptr1x!=NULL){
		if(i == 0){
			ptr1x = ptr1x->next;
			i=1;
		}
		else if(i==1){
			ptr1x = ptr1x->next;
			ptr2x = ptr2x->next;
			i = 0;
		}
	}
	return ptr2x;
}