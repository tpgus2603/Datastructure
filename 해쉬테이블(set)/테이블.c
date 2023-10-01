#include"���̺�.h"
#include<stdio.h>
#include<stdlib.h>

void TBLInit(Table* pt, HashFunc* f) {
	int i;
	for (i = 0; i < MAX_TBL; i++) //Empty���·� �ʱ�ȭ
		(pt->tbl[i].status = EMPTY);
	pt->hf = f;  //�ؽ� �Լ� ���
}
void TBLInsert(Table* pt, Key k, Value v) {  //���̺��� Ű�� �ش��ϴ� ���Կ� ���� Ű ����
	int hv = pt->hf(k); //key���� �ؽ��Լ� ����->�ٸ�key���� ���� �ؽ����� ���� ��찡 �浹
	pt->tbl[hv].val = v;  //���Կ� �� ����
	pt->tbl[hv].key = k;
	pt->tbl[hv].status = INUSE;
}
Value TBLDelete(Table* pt, Key k) {
	int hv = pt->hf(k);
	if (pt->tbl[hv].status != INUSE)  //������� �ƴ� �����̶�� NULL��ȯ
		return NULL;  
	else {
		pt->tbl[hv].status = DELETED; //status�� ������ ���°����� �������� ���� 
		return pt->tbl[hv].val;
	}
}
Value TBLSearch(Table* pt, Key k) {
	int hv = pt->hf(k);
	if (pt->tbl[hv].status != INUSE) {
		return NULL;
	}
	else
		return pt->tbl[hv].val; //Ž�� ����� �� ��ȥ
}