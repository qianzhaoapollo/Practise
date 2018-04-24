#include <iostream>
#include <stdlib.h>

#include "stack.h"

bool is_Empty(Stack S)
{
	return S->next == NULL;
}

void Pop(Stack S)
{
	PtrToNode firstCell;

	if (is_Empty(S))
		std::cout << "Empty Stack" << std::endl;
	else {
		firstCell = S->next;
		S->next = S->next->next;
		free(firstCell);
	}
}

void Push(Stack S, int X)
{
	PtrToNode firstCell;
	
	firstCell = (Node*)malloc(sizeof(struct Node));
	if (firstCell == NULL)
		std::cout << "Out of Space"  << std::endl;
	else {
		firstCell->data = X;
		firstCell->next = S->next;
		S->next = firstCell;
	}
}

Stack make_Empty(Stack S)
{
	if (S == NULL)
		std::cout << "Must create a stack first!" << std::endl;
	else 
		while (!is_Empty(S))
			Pop(S);
	
	return S;
}

int Size(Stack S)
{
	Stack tmp = S;
	int count = 0;
	while (!is_Empty(tmp)) {
		count++;
		tmp = tmp->next;
	}
	
	return count;
}


Stack create_Stack()
{
	Stack S;
	S = (Node*)malloc(sizeof(struct Node));
	if (S == NULL) {
		std::cout << "" << std::endl;
	}
	
	S->next = NULL;
	
	for(int i = 0; i < 10; i++) {
		Push(S, i);
	}
	
	while (!is_Empty(S)) {
		if (Size(S) == 1) 
			std::cout << S->next->data << std::endl;
		else
			std::cout << S->next->data << "->";
		Pop(S);
	}
	
	make_Empty(S);
	
	return S;
}

