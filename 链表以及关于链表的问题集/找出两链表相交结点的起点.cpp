
//
struct  ListNode *FindIntersectingNode(struct ListNode* list1, struct ListNode* list2){
	int L1=0,L2=0,diff=0;
	struct ListNode *head1=list1, *head2 = list2;
	while(head1!=NULL){
		L1++;
		head1 = head1->next;
	}
	while(head2!=NULL){
		L2++;
		head2 = head2->next;
	}
	if(L1 < L2){
		head1=list2;head2=list1;diff=L2-L1;
	}
	else{
		head1=list1;head2=list2;diff=L1-L2;
	}
	for(int i=0; i<diff;i++){
		head1 = head1->next;
	}
	while(head1 && head2){
		if(head1 == head2)
			return head1;
		head1=head1->next;
		head2 = head2->next;
	}
	return NULL;
}