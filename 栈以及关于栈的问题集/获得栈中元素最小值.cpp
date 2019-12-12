
struct AdvancedStack{
	struct Stack elementStack;
	struct Stack minStack;
};
void Push(struct AdvancedStack *S, int data){
	Push(S->elementStack,data);
	if(IsEmptyStack(S->minStack) || Top(S->minStack) >= data)
		Push(S->minStack);
	else
		Push(S->minStack,Top(S->minStack));
}

int Pop