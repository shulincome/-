// 这个算法是逆置链表算法的扩展

/* 此函数返回第K个结点的直接后置结点的地址，即返回指向第K+1个结点的指针*/
struct ListNode * GetKPlusOneThNode(int K, struct ListNode *head){
	struct ListNode *Kth;
	int i = 0;
	if(!head)
		return head;
	for(i = 0,Kth=head; Kth&&(i < k); i++,Kth->next);
	
	if(i==K && Kth!=NULL)
		return Kth;
	return head->next;
}
/* 此函数判断链表head是否至少有K个结点*/
int HasKNode(struct ListNode *head,int K){
	int i = 0;
	for(i = 0,head; head&&(i < k); i++,head->next);
	if(i==K)
		return 1;
	return 0;
}

/* 该函数对链表head前K个元素进行逆置*/
struct ListNode *ReverseBlockOfK-NodesInLinkedList(struct ListNode *head, int K){
	struct ListNode *cur = head, *temp,*next,newHead;
	int i;
	if(K==0 || K == 1)
		return head;
	if(HasKNode(cur,K-1))
		newHead = GetKPlusOneThNode(K-1,cur);
	else
		newHead = head;
	while(cur && HasKNode(cur, K)){
		temp = GetKPlusOneThNode(K,cur);
		i=0;
		
		while(i<K){
			next = cur->next;
			cur->next = temp;
			temp = cur;
			cur = next;
			i++;
		}
	}
	return newHead;
}




















