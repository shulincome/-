/* 弗洛伊德算法（Floyd-cycle-findings）*/
int DoseLinkedListHasLoop(struct ListNode *head){
	struct ListNode *slowPtr=head,*fastPtr=head;
	while(slowPtr&&fastPtr&&fast->next){
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if(slowPtr==fastPtr)
			return 1;
	}
	return 0;
}