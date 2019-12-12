/*将循环链表均等拆分：
1.利用Floyd环查找算法，找到循环链表的中间位置和尾元结点
2.循环链表后半部分生成新的循环链表
3.循环链表钱半部分生成新的循环链表
4.设置两个新循环链表的头指针
*/

struct ListNode{
	int data;
	struct ListNode *next;
}

void SplitList(struct ListNode *head, struct ListNode **head1, struct ListNode **head2){
	struct ListNode *slowptr = head;
	struct ListNode *fastptr = head;
	
	if(head == NULL){
		return ;
	}
	/*如果循环链表有奇数个结点，则while循环后fastptr->next== head
	  偶数个结点，则fastptr->next->next = head*/
	while(fastptr->next!= head && fastptr->next->next != head){
		fastptr = fastptr->next->next;
		slowptr = slowptr->next;
	}
	
	//如果被拆分链表有偶数个结点，那么向后移动fastptr 使其指向表尾
	if(fastptr->next == head){
		fastptr = fastptr->next;
	}
	//设置前半部分的头指针
	*head1 = head;
	
	//设置后半部分的头指针
	if(head->next!= head)
		*head2 = slowptr->next;
	
	//生成由后半部分结点构成的新循环链表
	fastptr->next = slowptr->next;
	
	//生成由前半部分结点构成的新循环链表
	slowptr->next = head;
}



























