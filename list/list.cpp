#include "list.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

List Make_Empty(List L)
{
    return L->next = NULL;
}

bool Is_Empty(List L)
{
    return L->next == NULL;
}

bool Is_Last(List L, Position P)
{
    return P->next == NULL;
}

Position Find(List L, ElementType X)
{
	Position Ptr = L->next;
	while (Ptr->data != X) {
		Ptr = Ptr->next;
	}
	
	return Ptr;
}

Position FindPrevious(List L, ElementType X)
{
	Position Ptr = L;
	while (Ptr->next->data != X && Ptr->next != NULL) {
		Ptr = Ptr->next;
	}
	
	return Ptr;
}

void Delete(List L, ElementType X)
{
	Position Ptr, Tmp;
	Ptr = FindPrevious(L, X);
	
	if (!Is_Last(L, Ptr)) {
		Tmp = Ptr->next;
		Ptr->next = Tmp->next;
		free(Tmp);
	}
}

// insert X at P.
void Insert(List L, Position P, ElementType X)
{
	Position Tmp = (Node*)malloc(sizeof(Node));
	if (Tmp == NULL) 
		cout << "Out of Space!" << endl;
	
	Tmp->data = X;
	Tmp->next = P->next;
	P->next = Tmp;
}

void DeleteList(List L)
{
	Position P, Tmp;
	P = L->next;
	L->next = NULL;
	
	while (P != NULL) {
		Tmp = P->next;
		free(P);
		P = Tmp->next;
	}
}


void Print(List L)
{
	Position P = L->next;
	while (P != NULL) {
		if (!Is_Last(L, P)) 
			std::cout << P->data << "->";
		else 
			std::cout << P->data << std::endl;
		P = P->next;
	}
}

void test_List()
{
    Node init;
	init.data = 0;
	init.next = NULL;
	List L = &init;

	if (Is_Empty(L))
		std::cout << "List L is empty!" << std::endl;

	Position Ptr = L;
	for (int i = 0; i < 10; i++) {
		Insert(L, Ptr, i);
// 		Ptr = Ptr->next;
	}

	Print(L);

// 	Make_Empty(L);
	DeleteList(L);
	if (Is_Empty(L))
		std::cout << "List L is empty!" << std::endl;
}
