#include <stdio.h>
#include <stdlib.h>
#include "연결리스트.h"

void ListInit(List* plist) {//리스트 초기화 메소드
	plist->head = (Node*)malloc(sizeof(Node));  //더미 생성 후 헤드가 더미를 가리킴
	plist->head->next = NULL;   //헤드의 다음이 널 초기화
	plist->comp = NULL;  // 정렬함수 포인터 널 초기화
	plist->numOfData = 0;
}
void FInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));   //새로운 노드 생성
	newNode->data = data;
	newNode->next = plist->head->next;   //새로운 노드가 널을 다음노드로 가리킴
	plist->head->next = newNode;    //머리노드의 다음노드를 새로운노드로
	plist->numOfData++;
}
void SInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));    //새로운 노드 생성
	Node* pred = plist->head;   // pred가 헤드를 가리킴
	newNode->data = data;    //
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) { //헤드노드의 수를 기준으로 정렬
		pred = pred->next;
	}
	newNode->next = pred->next; //새로운 노드 오른쪽을 연결 
	pred->next = newNode; //새 노드의 왼쪽 연결

	plist->numOfData++;
}
void LInsert(List* plist, LData data) {
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}
int LFirst(List* plist, LData* pdata) {
	if (plist->head->next == NULL) //더미가 아무것도 가르키지 않을때
		return FALSE;
	plist->before = plist->head;
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL)
		return FALSE;  //데이터를 다 읽으면 0반환
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}
LData LRemove(List* plist) {
	Node* rpos = plist->cur;
	LData rdata = rpos->data; //제거될 데이터 저장
	plist->before->next = plist->cur->next; //before가 한칸 건너뛰어서 이어지게함
	plist->cur = plist->before; //현재 노드 앞으로 한칸 밀기
	free(rpos);
	(plist->numOfData)--;
	return rdata;
}
int LCount(List* plist) {
	return plist->numOfData;
}
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2)) {
	plist->comp = comp;//구조체의 comp를 인자로 전달된 포인터 함수로 
}