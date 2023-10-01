//#include<stdio.h>
//#include<stdlib.h>
//#include"양방향연결리스트.h"
//
//void ListInint(List* plist) {
//	plist->head = NULL;
//	plist->numOfData = 0;
//}
//void LInsert(List* plist, Data data) {
//	Node* newNode = (Node*)malloc(sizeof(Node)); //노드생성
//
//	newNode->data = data; //새로운 노드의 데이터 매개변수 data로 초기화
//	newNode->next = plist->head; //새로운 노드의 다음 노드는 이전 헤드노드를 가리킴
//	if (plist->head != NULL)   //두번째 이후의 노드 추가할때
//		plist->head->prev = newNode;  // 기존 헤드노드의 이전노드가 새로운 노드를 가리킴
//
//	newNode->prev = NULL;  //새로운 노드의 이전노드는 NULL가리킴
//	plist->head = newNode;  //헤드노드를 새로운 노드로 설정
//	plist->numOfData++;
//
//}
//int LFirst(List* plist, Data* pdata) {
//	if (plist->head == NULL)//저장된 노드가 없는경우
//		return FALSE;
//	plist->cur = plist->head;  //현재노드가 리스트의 헤드노드를 가리키게함
//	*pdata = plist->cur->data;
//	return TRUE;
//}
//int LNext(List* plist, Data* pdata) {
//	if (plist->cur->next == NULL) //더이상 읽을 노드가 없는경우
//		return FALSE;
//	plist->cur = plist->cur->next;
//	*pdata = plist->cur->data;
//	return TRUE;
//}
//int LPrevious(List* plist, Data* pdata) {
//	if (plist->cur->prev == NULL) //현재노드가 헤드노드인경우 혹은 저장된게 없는경우
//		return FALSE;
//	plist->cur = plist->cur->prev; //현재노드를 이전노드로 이동
//	*pdata = plist->cur->data;  //매개변수 데이터 포인터 초기화
//	return TRUE;
//}
//int LCount(List* plist) {
//	return plist->numOfData;
//}
//
