//使用一个偶数指针

int IsLinkedListLengthEven(struct ListNode *listHead){
	while(listHead && listHead->next){
		listHead = listHead->next->next;
	}
	if(!head)
		return 0;
	return 1;
}