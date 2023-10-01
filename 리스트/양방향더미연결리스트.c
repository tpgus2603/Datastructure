#include<stdio.h>
#include<stdlib.h>
#include "양방향더미연결리스트.h"

//case1 처음 더미노드가 초기화할때 연결되지 않는 경우

//void ListInit(List* plist) {   
//	plist->head = (Node*)malloc(sizeof(Node));//머리가 더미노드를 가리킴
//	plist->tail = (Node*)malloc(sizeof(Node));//꼬리가 더미노드를 가리킴
//	plist->head->next = NULL;
//	plist->head->prev = NULL;
//	plist->tail->next = NULL;
//	plist->tail->prev = NULL;
//	plist->cur = NULL;
//	plist->numOfData = 0;
//}
//void LInsert(List* plist, Data data) {
//	Node* newNode = (Node*)malloc(sizeof(Node)); //노드생성
//	newNode->data = data; //새로운 노드의 데이터 매개변수 data로 초기화
//	newNode->next = plist->tail;//새로운노드의 다음노드는 더미노드를 가리킴
//	if (plist->tail->prev == NULL) {
//		newNode->prev = plist->head;
//		plist->head->next = newNode;
//	}
//	else {
//		//plist->tail->prev //이게 기존노드임
//		newNode->prev = plist->tail->prev;
//		plist->tail->prev->next = newNode;
//	}
//	plist->tail->prev = newNode;
//	plist->numOfData++;
//}  //꼬리에 노드를 추가
//int LFirst(List* plist, Data* pdata) {
//	if (plist->tail->prev == NULL)//저장된 노드가 없는경우
//		return FALSE;
//	plist->cur = plist->head->next;  //현재노드가 리스트의 첫노드를 읽게함
//	*pdata = plist->cur->data;
//	return TRUE;
//}
//int LNext(List* plist, Data* pdata) {
//	if (plist->cur->next == plist->tail) //더이상 읽을 노드가 없는경우
//		return FALSE;
//	plist->cur = plist->cur->next;
//	*pdata = plist->cur->data;
//	return TRUE;
//}
//int LPrevious(List* plist, Data* pdata) {
//	if (plist->cur->prev == plist->head) //현재노드가 헤드노드인경우 혹은 저장된게 없는경우
//		return FALSE;
//	plist->cur = plist->cur->prev; //현재노드를 이전노드로 이동
//	*pdata = plist->cur->data;  //매개변수 데이터 포인터 초기화
//	return TRUE;
//}
//Data LRemove(List* plist) {
//	Node* rpos = plist->cur;
//	Data rdata = rpos->data;
//	plist->cur->prev->next = plist->cur->next;
//	plist->cur->next->prev = plist->cur->prev;
//	plist->cur = plist->cur->prev;
//	free(rpos);
//	plist->numOfData--;
//	return rdata;
//
//} //앞서 참조가 이루어진 노드 삭제
//int LCount(List* plist) {
//	return plist->numOfData;
//}

//처음 더미노드들이 연결 되는경우
void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));//머리가 더미노드를 가리킴
	plist->tail = (Node*)malloc(sizeof(Node));//꼬리가 더미노드를 가리킴
	plist->head->next = plist->tail;
	plist->head->prev = NULL;
	plist->tail->next = NULL;
	plist->tail->prev = plist->head;
	plist->numOfData = 0;
}
void LInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node)); //노드생성
	newNode->data = data; //새로운 노드의 데이터 매개변수 data로 초기화
	newNode->prev = plist->tail->prev;
	newNode->next = plist->tail;
	plist->tail->prev = newNode;
	plist->numOfData--;

}  //꼬리에 노드를 추가
int LFirst(List* plist, Data* pdata) {
	if (plist->tail->prev == NULL)//저장된 노드가 없는경우
		return FALSE;
	plist->cur = plist->head->next;  //현재노드가 리스트의 첫노드를 읽게함
	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List* plist, Data* pdata) {
	if (plist->cur->next == plist->tail) //더이상 읽을 노드가 없는경우
		return FALSE;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}
int LPrevious(List* plist, Data* pdata) {
	if (plist->cur->prev == plist->head) //현재노드가 헤드노드인경우 혹은 저장된게 없는경우
		return FALSE;
	plist->cur = plist->cur->prev; //현재노드를 이전노드로 이동
	*pdata = plist->cur->data;  //매개변수 데이터 포인터 초기화
	return TRUE;
}
Data LRemove(List* plist) {
	Node* rpos = plist->cur;
	Data rdata = rpos->data;
	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;
	plist->cur = plist->cur->prev;
	free(rpos);
	plist->numOfData--;
	return rdata;

} //앞서 참조가 이루어진 노드 삭제
int LCount(List* plist) {
	return plist->numOfData;
}