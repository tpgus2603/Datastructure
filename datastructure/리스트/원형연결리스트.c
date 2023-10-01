//#include<stdio.h>
//#include<stdlib.h>
//#include "원형연결리스트.h"
//
//void ListInit(List* plist) {
//	plist->tail = NULL;
//	plist->cur = NULL;
//	plist->before = NULL;
//	plist->numOfData = 0;
//}
//void LInsert(List* plist, Data data) {
//	Node* newNode = (Node*)malloc(sizeof(Node)); //노드생성
//	newNode->data = data;  //인자의 데이터를 생성 노드의 데이터에 저장
//	if (plist->tail == NULL) { //첫노드인 경우
//		plist->tail = newNode; //꼬리가 새 노드를 가리키게 한다
//		newNode->next = newNode; //새로운 노드가 자기 자신을 가리키게한다
//	}
//	else { //첫노드가 아닌경우
//		newNode->next = plist->tail->next; //새로운 노드가 기존의 꼬리가 가리키는것을 가리키게함
//		plist->tail->next = newNode; //기존 꼬리노드가 새로운 노드를 가리키게한다 
//		plist->tail = newNode;  //새로운 노드가 꼬리노드가 되게한다
//	}
//	plist->numOfData++;
//}  //꼬리에 노드를 추가
//void LInsertFront(List* plist, Data data) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = data;
//	if (plist->tail == NULL) { //첫노드인 경우
//		plist->tail = newNode; //꼬리가 새 노드를 가리키게 한다
//		newNode->next = newNode; //새로운 노드가 자기 자신을 가리키게한다
//	}
//	else {
//		newNode->next = plist->tail->next;  //꼬리가 연결된 노드에 새로운 노드 연결
//		plist->tail->next = newNode;//꼬리를 새로운 노드에 연결
//	}
//	plist->numOfData++;
//
//} //머리에 노드를 추가
//int LFirst(List* plist, Data* pdata) { //첫번째 데이터 읽기
//	if (plist->tail == NULL)   //데이터가 없을때 예외처리
//		return FALSE;
//	plist->before = plist->tail;  //이전 노드를 꼬리 노드로 지정
//	plist->cur = plist->before->next;   //현재 노드를  이전노드의 다음노드로 지정
//	*pdata = plist->cur->data; //현재노드의 데이터를 *pdata가 참조
//	return TRUE;
//
//}
//int LNext(List* plist, Data* pdata) { //한 노드씩 읽는 함수
//	if (plist->tail == NULL) //저장된 노드가 없을떄 
//		return FALSE;
//	plist->before = plist->cur; //이전노드가 현재 노드를 가리킴
//	plist->cur = plist->cur->next;  //현재노드를 이전 현재 노드의 다음 노드로 지정
//	*pdata = plist->cur->data;  //pdata가 현재 노드가 가리키는 데이터 참조
//	return TRUE;
//}
//Data LRemove(List* plist) {   //노드 삭제 함수
//	Node* rpos = plist->cur;  //현재 노드를 가리키는 노드타입 포인터 정의
//	Data rdata = rpos->data;  //rdata가 현재 노드가 가리키는 데이터 저장
//	//삭제할 데이터가 꼬리인경우와 그게 마지막 노드인 경우 예외처리
//	if (rpos == plist->tail) { //삭제할 데이터가 tail이면
//		if (plist->tail == plist->tail->next)//마지막 노드라면
//			plist->tail == NULL;   //꼬리노드를 널포인터로 지정
//		else//삭제할 노드가 마지막 노드는 아니지만 꼬리노드인 경우 
//			plist->tail = plist->before;  //꼬리노드가 이전 노드를 가리키게 함
//	} //꼬리 옮겨놓기
//		plist->before->next = plist->cur->next; //이전 노드의 다음 노드는 삭제할 노드의 다음노드를 가리킴
//		plist->cur = plist->before; //현재 노드를 삭제할 노드 이전노드로 지정
//		free(rpos); //현재노드의 메모리 해제
//		plist->numOfData--;
//		return rdata;
//}
//int Lcount(List* plist) {
//	return plist->numOfData;
//}