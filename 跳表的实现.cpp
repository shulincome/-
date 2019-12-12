#include <stdio.h>
#include <stdlib.h>
#define MAXSKIPLEVEL 5

struct ListNode{
	int data;
	struct ListNode *next[1];
};

srtuct SkipList{
	struct ListNode *header;
	int listLevel;     //跳表当前的层次数
};
struct SkipList list;

struct ListNode *insertElement(int data){
	int i, newLevel;
	struct ListNode *update[MAXSKIPLEVEL+1];
	srtuct ListNode *temp;
	temp = list.header;
	for(i=list.listLevel;i>=0;i--){
		while(temp->next[i]!=list.header&&temp->next[i]->data < data){
			temp=temp->next[i];
		}
		update[i] = temp;
	}
	temp = temp->next[0];
	if(temp!=list.header&&temp->data == data){
		return(temp);
	}
	//随机确定新插入结点的层次
	for(newLevel = 0;rand()<RAND_MAX/2 && newLevel < MAXSKIPLEVEL; newLevel++);
	if(newLevel > list.listLevel){
		for(i = list.header+1; i<=newLevel;i++)
			update[i] = list.header;
		list.listLevel = newLevel;
	}
	//生成新结点
	if((temp==malloc(sizeof(Node) + newLevel*sizeof(Node *))) == 0){
		printf("insufficient memory (insertElement)\n");
		exit(1);
	}
	temp->data = data;
	for(i = 0; i <= newLevel; i++){
		temp->next[i] = update[i]->next[i];
		update[i]->next[i] = temp;
	}
	return(temp);
}

//删除值域等于给定data的结点
void deleteElement(int data){
	int i;
	struct ListNode *update[MAXSKIPLEVEL+1], *temp;
	
	temp = list.header;
	for(i = list.listLevel;i>=0;i--){
		while(temp->next[i] != list.header && temp->next[i]->data < data)
			temp = temp->next;
		update[i] = temp;
	}
}



















