/*   单链表   */

struct ListNode {
	int data;
	struct ListNode *next;
};

//链表的遍历 时间复杂度O(n),空间复杂度O(1)
int ListLength(struct ListNode *head){
	struct ListNode *current ;
	current = head;
	int count=0;
	while(current!=NULL){
		count++;
		current = current->next;
	}
	return count;
}

//单链表的插入操作
void InsertInLinkedList(struct ListNode **head,int data,int position){ //**head 双指针：指向指针的指针
	int k=1;
	struct ListNode *p,*q,*newNode;
	newNode = (ListNode *)malloc(sizeof(struct ListNode));
	if(!newNode){
		print("Memory is error")
		return ;
	}
	newNode->data = data;
	p = *head;
	//在头部插入链表
	if(position==1){
		newNode->next = p;
		//容易出错示例：p->next = newNode;
		*head = newNode;
	}
	else{
		//遍历链表知道我们想要插入的位置为止
		while((p!=NULL)&&(k<position)){
			k++;
			
			q = p;
			p = p->next;
		}
		q->next = newNode; //有更好的方法实现这一点
		newNode->next = p;
	}
}

//单链表的删除操作
void DeleteNodeFromLikedList(struct ListNode **head, int position){
	int k = 1;
	struct ListNode *p,*q;
	if(*head=NULL){
		print("List empty");
		return;
	}
	p = *head;
	//删除首元结点
	if(position==1){
		/*q = p; 我的另外一种想法
		p = p->next;
		head = p;
		free(q);
		return; */
		*head = (*head)->next;
		free(p);
		return;
	}
	else{
		//遍历链表直到达到我们想要删除的结点位置
		while((p!=NULL)&&(k<position)){
			k++;
			
			q=p;
			p=p->next;
		}
		if(p==NULL){
			printf("Position is not exist")
		}
		else{
			q->next = p->next;
			free(p);
		}
	}
}

//撤销单链表
void DeleteLinkedList(struct ListNode **head){
	struct ListNode *auxilaryNode,*iterator;
	iterator = *head;
	while(iterator!=NULL){
		auxilaryNode = iterator->next;
		free(iterator);
		iterator=auxilaryNode;
	}
	*head = NULL; //将调用者的头指针置空
}

/*  双链表  */
struct DLLNode{
	int data;
	struct DLLnode *next;
	struct DLLNode *prev;
};

//双链表的插入操作
void DLLInsert(struct DLLNode **head, int data, int position){
	int k =1;
	struct DLLNode *temp,*newNode;
	newNode = (struct DLLNode *)malloc(sixeof(struct DLLNode));
	if(!newNode){
		printf("Memory error");
		return;
	}
	newNode->data = data;
	//在头部插入链表
	if(position==1){
		newNode->next = *head;
		newNode->prev = NULL;
		
		if(*head)
			(*head)->prev = newNode;
		*head = newNode;
		return;
	}
	temp = *head;
	// 遍历链表直到到达我们想要插入的位置为止
	while((k<position - 1)&&temp->next!=NULL){
		temp = temp->next;
		k++;
	}
	if(k!=position){
		pritnf("Desired position does not exist.\n")
	}
	newnode->next = temp->next;
	newNode->prev = temp;
	if(temp->next){ //如果当前节点的下一个节点存在数据，则把下一个节点的前置指针指向newNode
		temp->next->prev = newNode;
	}
	temp->next = newNode;
	return;
}

//双链表删除操作
void DLLDelete(struct DLLNode **head,int position){
	struct DLLNode *temp, *temp2 ,temp = *head;
	int k =1;
	if(*head == NULL){
		print("List is empty");
		return;
	}
	if(position==1){
		*head = (*head)->next;
		if(*head!=NULL){
			*head-prev = NULL;
			free(temp);
			return;
		}
	}
	//遍历链表直到到达我们想要插入的位置为止
	while((k<position)&&temp->next!=NULL){
		temp = temp->next;
		k++;
	}
	if(k!=position-1){
		printf("Desired position does not exist.\n")
		return;
	}
	temp2 = temp->prev;
	temp2->next = temp->next;
	if(temp->next)  //删除的是中间的结点
	{
		temp->next->prev = temp2;
	}
	free(temp);
	return;
}

/* 2019/12/2 循环链表 */
//类型声明
struct CLLNode{
	int data;
	struct CLLNode *next;
}

//统计循环链表中的节点个数
/* 通过头指针访问循环链表，从首元结点借助
  辅助指针current遍历整个链表，当current再一
   次指向首元结点时停止计数。*/
int CircularListLength(struct CLLNode *head){
	struct CLLNode *current;
	int count=0;
	current = head;
	
	if(current==NULL){
		return 0;
	}
	do{
		current = current->next;
		count++;
	}while(current!=head);
	return count;
}

//打印输入循环链表的内容(和统计节点个数相似)

void PrintCircularListData(struct CLLNode *head){
	struct CLLNode *current=head;
	if(head==NULL){
		printf("No data ");
		return;
	}
	do{
		printf("%d",current->data);
		current=current->next;
	}while(current!=head)
}

//在循环链表的尾部插入一个结点

void InsertAtEndInCLL(struct CLLNode **head, int data){
	struct CLLNode *current=*head;
	struct CLLNode *newNode;
	newNode = (struct CLLNode *)(malloc(sizeof(struct CLLNode)));
	
	if(!newNode){
		printf("Memory Error");
		return ;
	}
	
	//创建新结点使next指针域指向它自己
	newNode->data = data;
	newNode->next = newNode;
	
	//遍历链表直到达到表尾
	while(current->next!=*head){
		current = current->next;
	}
	if(*head==NULL){
		*head = newNode;
	}
	else{
		newNode->next = *head;
		current->next = newNode;
	}
}

//在循环链表头部插入一个结点
void InsertAtBeginInCLL(struct CLLNode **head, int data){
	struct CLLNode *current = *head;
	struct CLLNode *newNode;
	
	newNode = (struct CLLNode *)(malloc(sizeof(struct CLLNode)));
	
	if(!newNode){
		printf("Memory error");
		return;
	}
	newNode->data = data;
	newNode->next = newNode;
	
	if(*head==NULL){ //这个if是插入空表的情况
		*head = newNode;
		return;
	}
	while(current->next!=*head){
		current=current->next;
	}
	newNode->next = *head;
	current->next = newNode;
	*head = newNode;
	return;
}

//删除循环链表的尾元结点 (需要两个辅助指针变量)

void DeleteLastNodeFromCLL(struct CLLNode **head){
	struct CLLNode *temp=*head, *current=*head;
	if(*head==NULL){
		printf("List Empty");
		return;
	}
	while(current->next=*head){
		temp = current;
		current = current->next;
	}
	temp->next = current->next;
	free(current);
	return;
}

//删除循环链表的首元结点（需要两个辅助指针变量）

void DeleteFrontNodeFromCLL(struct CLLNode **head){
	struct CLLNode *temp = *head;
	struct CLLNode *current = *head;
	
	if(*head==NULL){
		printf("List Empty");
		return;
	}
	while(current->next!=*head){
		current = current->next;
	}
	current->next = *head->next;
	*head = (*head)->next;
	
	free(temp);
	return ;
}

//总结：循环链表可以应用在管理计算机的计算资源，可以用循环链表实现栈和队列

/*一种存储高效的双链表 */

//这种方法基于指针的区分值，指针区分值可以通过向前指针和向后指针的异或操作计算得到。

/* 松散链表*/

/* 跳表
跳表是一种可以替代平衡二叉树的数据结构。
利用了概率平衡而不是严格意义上的平衡。
基本上是一个带有附加指针的链表，附加指针可以使得中间结点被跳过。
*/
















