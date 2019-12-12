// 利用散列表进行“克隆”
struct ListNode *Clone(strutc ListNode *head){
	struct ListNode *X, *Y;
	struct HashTable *HT = CreateHashTable();
	X = head;
	while(X != NULL){
		Y = (struct ListNode *)malloc(sizeof(struct ListNode));
		Y->data = X->data;
		Y->next = NULL;
		Y->random = NULL;;
		HT.insert(X,Y);
		X = X->next;
	}
	X = head;
	while(X != NULL){
		//从散列表中获得与X对应的新结点Y
		Y = HT.get(X);
		Y->next = HT.get(X->next);
		Y.setRandom = HT.get(X->random);
		X = X->next;
	}
	
	return HT.get(head);
}

//另外一种不需要额外空间的解决办法
void Clone(struct ListNode *head){
	//temp指向当前结点，temp2用来指向当前对应的新结点
	struct ListNode *temp, *temp2;
	/*步骤1：在第一次扫描中用temp->random设置temp2->next.
	这样我们就可以利用temp的random域指向结点temp2
	换句话说，在第一次扫描中利用新结点的next域保存当前的random域的
	信息，再利用当前的结点的random域保存指向新结点的指针，以便能再次访问
	新结点*/
	temp = head;
	while(temp !=NULL){
		temp2 = (struct ListNode *)malloc(sizeof(struct ListNode));
		temp2->data = temp->data;
		temp2->next = temp->random;
		temp->random = temp2;
		temp = temp->next;
	}
	/*步骤2：设置temp2->random。temp2->random是temp2->next应该指向的结点的旧副本，
	因此temp2->next->random是该结点的新副本*/
	temp = head;
	while(temp !=NULL){
		temp2 = temp->random;
		temp2->random = temp->next->random;
		temp = temp->next;
	}
	/* 步骤3：在第三次扫描中。还原链表结点random域的信息并设置新结点的next域，
	得到链表的克隆链表*/
	temp = head;
	while(temp !=NULL){
		temp2 = temp->random;
		temp->random = temp2->next;
		temp2->next = temp->next->random;
		temp = temp->next;
	}
	
}

















































