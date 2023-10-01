#ifndef __DBLINKEDDUMMY_LIST_H
#define __DBLINKEDDUMMY_LIST_H

#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node {
	Data data;
	struct _node* next;
	struct _node* prev;
}Node;
typedef struct _DlinkedList {
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
}DBlinkedList;
typedef DBlinkedList List;
void ListInit(List* plist);
void LInsert(List* plist, Data data);  //꼬리에 노드를 추가
int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
int LPrevious(List* plist, Data* pdata);
Data LRemove(List* plist); //앞서 참조가 이루어진 노드 삭제
int LCount(List* plist);
#endif
