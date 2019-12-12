
int FindBeginofLoop(struct ListNode *head){
	struct ListNode *slowPtr=head, *fastPtr=head;
	int loopExists = 0;
	
	while(slowPtr && fastPtr && fastPtr->next){
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
		if(slowPtr==fastPtr){
			loopExists = 1;
			break;
		}
	}
	if(loopExists){
		slowPtr = head;
		while(slowPtr!=fastPtr){
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next;
		}
		return slowPtr;
	}
	return NULL;
}

//总感觉这个有点问题