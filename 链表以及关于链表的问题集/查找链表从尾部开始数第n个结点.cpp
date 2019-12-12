/* 利用两个辅助指针进行扫描*/
struct ListNode *NthNodeFromEnd(struct ListNode *head,int NthNode){
	struct ListNode *pNthNode=NULL,*pTemp=head;
	for(int count=1; count<NthNode; count++){
		if(pTemp)
			pTemp = pTemp->next;
	}
	while(pTemp){
		if(pNthNode==NULL)
			pNthNode=head;
		else
			pNthNode=pNthNode->next;
		pTemp = pTemp->next;
	}
	if(pNthNode)
		return pNthNode;
	return NULL;
}