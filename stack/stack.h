#ifndef _STACK_H_
#define _STACK_H_

#define ElementType int

struct Node {
    ElementType data;
	Node* next;
};

typedef Node* PtrToNode;
typedef PtrToNode Stack;

bool is_Empty(Stack S);
Stack make_Empty(Stack S);
Stack create_Stack();
void Pop(Stack S);
void Push(Stack S, ElementType X);
int Size(Stack S);

#endif 