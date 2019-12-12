/* 基于简单数组的实现 */ 
struct ArrayStack{
	int top;
	int capacity;
	int *array;
};

struct ArrayStack *CreateStack(){
	struct ArrayStack *S = malloc(sizeof(struct ArrayStack));
	if(!S)
		return ;
	S->capacity = 1;
	S->top = -1;
	S->array = malloc(S->capacity *sizeof(int));
	if(!S->array)
		return NULL;
	return S;
}

int IsEmptyStack(struct ArrayStack *S){
	return (S->top == -1); //如果条件成立，则返回1，否则返回0.
}

int IsFullStack(struct ArrayStack *S){
	//如果条件成立，则返回1，否则返回0。
	return (S->top == S->capacity - 1);
}

void Push(struct ArrayStack *S, int data){
	/* S->top == S->capacity - 1 用来判断栈是否为满*/
	if(IsFullStack(S))
		printf("Stack overflow");
	else{ //top 加一，然后将元素存入top所指的位置上
		S->array[++S->top] = data;
	}
}

int Pop(struct ArrayStack *S){
	/* S->top == -1 用来判断是否为空栈*/
	if(S->top == -1){
		printf("Satck is empty");
		return 0;
	}
	else{
		return (S->array[S->top--]);
	}
}

void DeleteStack(struct DynArrayStack *S){
	if(S){
		if(S->array)
			free(S);
		free(S);
	}
}


















