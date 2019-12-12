//给定一个链表，修改链表使得值域为偶数的结点全部位于奇数结点的前面。
struct ListNode *exchangeEvenOddList(struct ListNode *head){
	struct ListNode *EvenList=NULL, *OddList=NULL;
	
	//用两个辅助指针始终分别指向odd list 和even list 的尾部
	struct ListNode *oddlistEnd=NULL,*evenlistEnd = NULL;
	struct ListNode *itr = head;
	
	if(head ==NULL)
		return 
	else{
		while(itr!=NULL)
		{
			if(itr->data % == 0){
				if(EvenList == NULL)
					EvenList = evenlistEnd =  itr;
				else{
					evenlistEnd->next = itr;
					evenlistEnd = itr;
				}
			}
			else{
				if(itr->data % == 0){
				if(OddList == NULL)
					OddList = OddlistEnd = itr;
				else{
					OddlistEnd->next = itr;
					oddlistEnd = itr;
				}
			}
					
			}
			itr = itr->next;
		}
		EvenList->next = OddList;
		return head;
	}
}