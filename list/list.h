#ifndef LIST_H

#define LIST_H
#define ElementType int

struct Node {
    ElementType data;
	Node* next;
};

typedef Node* PtrNode;
typedef PtrNode Position;
typedef PtrNode List;

List Make_Empty(List L);
bool Is_Empty(List L);
bool Is_Last(List L, Position P);
Position Find(List L, ElementType X);
Position FindPrevious(List L, ElementType X);
void Delete(List L, ElementType X);
void Insert(List L, Position P, ElementType X);
void DeleteList(List L);
void Print(List L);

void test_List();

#endif