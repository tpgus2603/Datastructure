//#include<stdio.h>
//#include<stdlib.h>
//#include"����⿬�Ḯ��Ʈ.h"
//
//void ListInint(List* plist) {
//	plist->head = NULL;
//	plist->numOfData = 0;
//}
//void LInsert(List* plist, Data data) {
//	Node* newNode = (Node*)malloc(sizeof(Node)); //������
//
//	newNode->data = data; //���ο� ����� ������ �Ű����� data�� �ʱ�ȭ
//	newNode->next = plist->head; //���ο� ����� ���� ���� ���� ����带 ����Ŵ
//	if (plist->head != NULL)   //�ι�° ������ ��� �߰��Ҷ�
//		plist->head->prev = newNode;  // ���� ������� ������尡 ���ο� ��带 ����Ŵ
//
//	newNode->prev = NULL;  //���ο� ����� �������� NULL����Ŵ
//	plist->head = newNode;  //����带 ���ο� ���� ����
//	plist->numOfData++;
//
//}
//int LFirst(List* plist, Data* pdata) {
//	if (plist->head == NULL)//����� ��尡 ���°��
//		return FALSE;
//	plist->cur = plist->head;  //�����尡 ����Ʈ�� ����带 ����Ű����
//	*pdata = plist->cur->data;
//	return TRUE;
//}
//int LNext(List* plist, Data* pdata) {
//	if (plist->cur->next == NULL) //���̻� ���� ��尡 ���°��
//		return FALSE;
//	plist->cur = plist->cur->next;
//	*pdata = plist->cur->data;
//	return TRUE;
//}
//int LPrevious(List* plist, Data* pdata) {
//	if (plist->cur->prev == NULL) //�����尡 ������ΰ�� Ȥ�� ����Ȱ� ���°��
//		return FALSE;
//	plist->cur = plist->cur->prev; //�����带 �������� �̵�
//	*pdata = plist->cur->data;  //�Ű����� ������ ������ �ʱ�ȭ
//	return TRUE;
//}
//int LCount(List* plist) {
//	return plist->numOfData;
//}
//
