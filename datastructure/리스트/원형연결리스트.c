//#include<stdio.h>
//#include<stdlib.h>
//#include "�������Ḯ��Ʈ.h"
//
//void ListInit(List* plist) {
//	plist->tail = NULL;
//	plist->cur = NULL;
//	plist->before = NULL;
//	plist->numOfData = 0;
//}
//void LInsert(List* plist, Data data) {
//	Node* newNode = (Node*)malloc(sizeof(Node)); //������
//	newNode->data = data;  //������ �����͸� ���� ����� �����Ϳ� ����
//	if (plist->tail == NULL) { //ù����� ���
//		plist->tail = newNode; //������ �� ��带 ����Ű�� �Ѵ�
//		newNode->next = newNode; //���ο� ��尡 �ڱ� �ڽ��� ����Ű���Ѵ�
//	}
//	else { //ù��尡 �ƴѰ��
//		newNode->next = plist->tail->next; //���ο� ��尡 ������ ������ ����Ű�°��� ����Ű����
//		plist->tail->next = newNode; //���� ������尡 ���ο� ��带 ����Ű���Ѵ� 
//		plist->tail = newNode;  //���ο� ��尡 ������尡 �ǰ��Ѵ�
//	}
//	plist->numOfData++;
//}  //������ ��带 �߰�
//void LInsertFront(List* plist, Data data) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = data;
//	if (plist->tail == NULL) { //ù����� ���
//		plist->tail = newNode; //������ �� ��带 ����Ű�� �Ѵ�
//		newNode->next = newNode; //���ο� ��尡 �ڱ� �ڽ��� ����Ű���Ѵ�
//	}
//	else {
//		newNode->next = plist->tail->next;  //������ ����� ��忡 ���ο� ��� ����
//		plist->tail->next = newNode;//������ ���ο� ��忡 ����
//	}
//	plist->numOfData++;
//
//} //�Ӹ��� ��带 �߰�
//int LFirst(List* plist, Data* pdata) { //ù��° ������ �б�
//	if (plist->tail == NULL)   //�����Ͱ� ������ ����ó��
//		return FALSE;
//	plist->before = plist->tail;  //���� ��带 ���� ���� ����
//	plist->cur = plist->before->next;   //���� ��带  ��������� �������� ����
//	*pdata = plist->cur->data; //�������� �����͸� *pdata�� ����
//	return TRUE;
//
//}
//int LNext(List* plist, Data* pdata) { //�� ��徿 �д� �Լ�
//	if (plist->tail == NULL) //����� ��尡 ������ 
//		return FALSE;
//	plist->before = plist->cur; //������尡 ���� ��带 ����Ŵ
//	plist->cur = plist->cur->next;  //�����带 ���� ���� ����� ���� ���� ����
//	*pdata = plist->cur->data;  //pdata�� ���� ��尡 ����Ű�� ������ ����
//	return TRUE;
//}
//Data LRemove(List* plist) {   //��� ���� �Լ�
//	Node* rpos = plist->cur;  //���� ��带 ����Ű�� ���Ÿ�� ������ ����
//	Data rdata = rpos->data;  //rdata�� ���� ��尡 ����Ű�� ������ ����
//	//������ �����Ͱ� �����ΰ��� �װ� ������ ����� ��� ����ó��
//	if (rpos == plist->tail) { //������ �����Ͱ� tail�̸�
//		if (plist->tail == plist->tail->next)//������ �����
//			plist->tail == NULL;   //������带 �������ͷ� ����
//		else//������ ��尡 ������ ���� �ƴ����� ��������� ��� 
//			plist->tail = plist->before;  //������尡 ���� ��带 ����Ű�� ��
//	} //���� �Űܳ���
//		plist->before->next = plist->cur->next; //���� ����� ���� ���� ������ ����� ������带 ����Ŵ
//		plist->cur = plist->before; //���� ��带 ������ ��� �������� ����
//		free(rpos); //�������� �޸� ����
//		plist->numOfData--;
//		return rdata;
//}
//int Lcount(List* plist) {
//	return plist->numOfData;
//}