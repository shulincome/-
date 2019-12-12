
struct ListNode *GetJosephusPosition(){
	struct ListNode *p, *q;
	int N, M;
	printf("Enter N(number of players): ");
	scanf("%d",&N);
	printf("Enter M(every M-th player gets eliminate): ");
	scanf("%d",&M);
	
	//创建包含所有参与游戏者的循环链表
	p = q = (struct ListNode *)(malloc(sizeof(struct ListNode)));
	p->data = 1;
	
	for(i=2;i<=N;i++){
		p->next = (struct ListNode *)(malloc(sizeof(struct ListNode)));
		p = p->next;
		p->dta = i;
	}
	//通过让最后一个结点的指针域指向第一个结点得到循环链表
	p->next = q;
	
	//淘汰第M个玩家直到至多剩下一位玩家为止
	for(int count=M;count > 1; count--){
		for(i=0;i<M;i++){
			p=p->next;
		}
		p->next = p->next->next;
	}
	printf("Last player left standing(Josephus Position) is %d.\n",p->data);
}















