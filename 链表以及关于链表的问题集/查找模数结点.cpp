//在这个问题中n的值我们是事先不知道的
struck ListNode *modularNodeFromBegin(struct ListNode *head, int k){
	struct ListNode *modularNode;
	int i = 0;
	if(k<=0)
		return NULL;
	for(;head!=NULL;head = head->next){
		if(i%k == 0)
			return modularNode = head;
		i++;
	}
	return modularNode;
}