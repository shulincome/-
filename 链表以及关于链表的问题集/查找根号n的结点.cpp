struct ListNode *sqrtNode(struct ListNode *head){
	struct ListNode *sqrtN = NULL;
	int i=1,j=1;
	
	for(;head!=NULL;head = head->next){
		if(i == j*j){
			if(sqrtN == NULL)
				return sqrtN=head;
			else
				return sqrtN=sqrtN->next;
			
			j++;
		}
		i++;
	}
	return sqrtN;
}