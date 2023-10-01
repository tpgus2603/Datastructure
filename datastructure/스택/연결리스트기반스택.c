#include <stdio.h>
#include<stdlib.h>
#include"연결리스트기반스택.h"

void StackInit(Stack* pstack) {
	pstack->head = NULL;
}
int SIsEmpty(Stack* pstack) {
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}
void SPush(Stack* pstack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}
Data SPop(Stack* pstack) {
	Data rdata;
	Node* rnode;
	if (SISEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	rdata = pstack->head->data;
	rnode = pstack->head;
	pstack->head = pstack->head->next;
	free(rnode);
	return rdata;
}
Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack->head->data;  //머리가 가르키는 데이터 반환
}
