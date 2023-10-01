#ifndef __C__LINKED_LIST_H
#define __C_LINKED_LIST_H
#include "사원정보.h"

#define TRUE 1
#define FALSE 0
typedef Employee* Data;
typedef struct _node {
	Data data;
	struct _node* next;
}Node;
typedef struct _CLL {
	Node* tail; Node* cur; Node* before; int numOfData;

}CList;
typedef CList List;
void ListInit(List* plist);
void LInsert(List* plist, Data data);  //꼬리에 노드를 추가
void LInsertFront(List* plist, Data data); //머리에 노드를 추가
int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
Data LRemove(List* plist);
int Lcount(List* plist);

#endif
