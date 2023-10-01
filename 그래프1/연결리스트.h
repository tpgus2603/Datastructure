#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__


#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node {   //노드 
	LData data;
	struct _node* next; //노드속다음 노드를 연결하는 포인터
}Node;
typedef struct _linekedList { //헤드,현재,이전,데이터의수,정렬함수를 멤버로 가지는 list구조체
	Node* head; Node* cur; Node* before; int numOfData;
	int (*comp)(LData d1, LData d2);
}LinkedList;
typedef LinkedList List;
void ListInit(List* plist);
void LInsert(List* plist, LData data);
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);
LData LRemove(List* plist);
int LCount(List* plist);
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2)); //리스트의 정렬함수를 포인터로 전달

#endif