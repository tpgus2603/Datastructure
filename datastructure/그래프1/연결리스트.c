#include <stdio.h>
#include <stdlib.h>
#include "���Ḯ��Ʈ.h"

void ListInit(List* plist) {//����Ʈ �ʱ�ȭ �޼ҵ�
	plist->head = (Node*)malloc(sizeof(Node));  //���� ���� �� ��尡 ���̸� ����Ŵ
	plist->head->next = NULL;   //����� ������ �� �ʱ�ȭ
	plist->comp = NULL;  // �����Լ� ������ �� �ʱ�ȭ
	plist->numOfData = 0;
}
void FInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));   //���ο� ��� ����
	newNode->data = data;
	newNode->next = plist->head->next;   //���ο� ��尡 ���� �������� ����Ŵ
	plist->head->next = newNode;    //�Ӹ������ ������带 ���ο����
	plist->numOfData++;
}
void SInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));    //���ο� ��� ����
	Node* pred = plist->head;   // pred�� ��带 ����Ŵ
	newNode->data = data;    //
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) { //������� ���� �������� ����
		pred = pred->next;
	}
	newNode->next = pred->next; //���ο� ��� �������� ���� 
	pred->next = newNode; //�� ����� ���� ����

	plist->numOfData++;
}
void LInsert(List* plist, LData data) {
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}
int LFirst(List* plist, LData* pdata) {
	if (plist->head->next == NULL) //���̰� �ƹ��͵� ����Ű�� ������
		return FALSE;
	plist->before = plist->head;
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL)
		return FALSE;  //�����͸� �� ������ 0��ȯ
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}
LData LRemove(List* plist) {
	Node* rpos = plist->cur;
	LData rdata = rpos->data; //���ŵ� ������ ����
	plist->before->next = plist->cur->next; //before�� ��ĭ �ǳʶپ �̾�������
	plist->cur = plist->before; //���� ��� ������ ��ĭ �б�
	free(rpos);
	(plist->numOfData)--;
	return rdata;
}
int LCount(List* plist) {
	return plist->numOfData;
}
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2)) {
	plist->comp = comp;//����ü�� comp�� ���ڷ� ���޵� ������ �Լ��� 
}