#include<stdio.h>
#include<stdlib.h>
#include "�������̿��Ḯ��Ʈ.h"

//case1 ó�� ���̳�尡 �ʱ�ȭ�Ҷ� ������� �ʴ� ���

//void ListInit(List* plist) {   
//	plist->head = (Node*)malloc(sizeof(Node));//�Ӹ��� ���̳�带 ����Ŵ
//	plist->tail = (Node*)malloc(sizeof(Node));//������ ���̳�带 ����Ŵ
//	plist->head->next = NULL;
//	plist->head->prev = NULL;
//	plist->tail->next = NULL;
//	plist->tail->prev = NULL;
//	plist->cur = NULL;
//	plist->numOfData = 0;
//}
//void LInsert(List* plist, Data data) {
//	Node* newNode = (Node*)malloc(sizeof(Node)); //������
//	newNode->data = data; //���ο� ����� ������ �Ű����� data�� �ʱ�ȭ
//	newNode->next = plist->tail;//���ο����� �������� ���̳�带 ����Ŵ
//	if (plist->tail->prev == NULL) {
//		newNode->prev = plist->head;
//		plist->head->next = newNode;
//	}
//	else {
//		//plist->tail->prev //�̰� ���������
//		newNode->prev = plist->tail->prev;
//		plist->tail->prev->next = newNode;
//	}
//	plist->tail->prev = newNode;
//	plist->numOfData++;
//}  //������ ��带 �߰�
//int LFirst(List* plist, Data* pdata) {
//	if (plist->tail->prev == NULL)//����� ��尡 ���°��
//		return FALSE;
//	plist->cur = plist->head->next;  //�����尡 ����Ʈ�� ù��带 �а���
//	*pdata = plist->cur->data;
//	return TRUE;
//}
//int LNext(List* plist, Data* pdata) {
//	if (plist->cur->next == plist->tail) //���̻� ���� ��尡 ���°��
//		return FALSE;
//	plist->cur = plist->cur->next;
//	*pdata = plist->cur->data;
//	return TRUE;
//}
//int LPrevious(List* plist, Data* pdata) {
//	if (plist->cur->prev == plist->head) //�����尡 ������ΰ�� Ȥ�� ����Ȱ� ���°��
//		return FALSE;
//	plist->cur = plist->cur->prev; //�����带 �������� �̵�
//	*pdata = plist->cur->data;  //�Ű����� ������ ������ �ʱ�ȭ
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
//} //�ռ� ������ �̷���� ��� ����
//int LCount(List* plist) {
//	return plist->numOfData;
//}

//ó�� ���̳����� ���� �Ǵ°��
void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));//�Ӹ��� ���̳�带 ����Ŵ
	plist->tail = (Node*)malloc(sizeof(Node));//������ ���̳�带 ����Ŵ
	plist->head->next = plist->tail;
	plist->head->prev = NULL;
	plist->tail->next = NULL;
	plist->tail->prev = plist->head;
	plist->numOfData = 0;
}
void LInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node)); //������
	newNode->data = data; //���ο� ����� ������ �Ű����� data�� �ʱ�ȭ
	newNode->prev = plist->tail->prev;
	newNode->next = plist->tail;
	plist->tail->prev = newNode;
	plist->numOfData--;

}  //������ ��带 �߰�
int LFirst(List* plist, Data* pdata) {
	if (plist->tail->prev == NULL)//����� ��尡 ���°��
		return FALSE;
	plist->cur = plist->head->next;  //�����尡 ����Ʈ�� ù��带 �а���
	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List* plist, Data* pdata) {
	if (plist->cur->next == plist->tail) //���̻� ���� ��尡 ���°��
		return FALSE;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}
int LPrevious(List* plist, Data* pdata) {
	if (plist->cur->prev == plist->head) //�����尡 ������ΰ�� Ȥ�� ����Ȱ� ���°��
		return FALSE;
	plist->cur = plist->cur->prev; //�����带 �������� �̵�
	*pdata = plist->cur->data;  //�Ű����� ������ ������ �ʱ�ȭ
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

} //�ռ� ������ �̷���� ��� ����
int LCount(List* plist) {
	return plist->numOfData;
}