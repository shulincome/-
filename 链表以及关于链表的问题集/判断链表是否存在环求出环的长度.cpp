
int FindLoopLength(struct ListNode *head){
	struct ListNode *slowPtr=head,*fastPtr=head;
	int loopExists = 0, count = 0;
	
	while(slowPtr && fastPtr && fastPtr->next){
		slowPtr = slowPtr->next ;
		fastPtr = fastPtr->next->next;
		if(slowPtr==fastPtr){
		loopExists = 1;
		break;
		}
	}
	if(loopExists){
		fastPtr = fastPtr->next;
		while(slowPtr!=fastPtr){
			fastPtr = fastPtr->next;
			count++;
		}
		return count;
	}
	return 0; //如果没有环存在
}