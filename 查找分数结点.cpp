//
struct ListNode *fractionalNodes(struct *head, int k){
	struct ListNode *fractionalNode = NULL;
	int i = 0;
	if(k<=0)
		return NULL;
	for(;head!=NULL;head=head->next){
		if(i%k == 0){
			if(fractionalNode==NULL)
				fractionalNode = head;
			else
				fractionalNode = fractionalNode->next;
		}
		i++;
	}
	return fractionalNode;
}






