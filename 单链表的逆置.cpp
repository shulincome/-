
/* 有两种求解思路：迭代版本和递归版本*/

//迭代版本：

struct ListNode *ReverseList(struct ListNode *head){
	struct ListNode *temp = NULL, *nextNode = NULL;
	while(head){
		nextNode = head->next;
		head->next = temp;
		temp = head;
		head = nextNode;
	}
	return temp;
}

/*递归版本：我们会发现从提出并解决小问题开始的自底向上的求解方式更容易理解,
			1.NULL的逆置是什么？是NULL
			2.包含一个结点的链表逆置是什么？还是该链表
			3.含n个结点的链表逆置是什么？是第二个结点到底n个结点构成长度为n-1的链表的逆置的后面接上第一个结点。
*/
struct ListNode RecursiveReverse(struct ListNode *head){
	if(head==NULL)
		return NULL;
	if(head->next == NULL)
		return head;
	struct ListNode *secondElem = head->next;
	
	head->next = NULL;
	struct ListNode *ReverseRest = RecursiveReverse(secondElem);
	
	secondElem->next = head;
	return reverseRest;
}