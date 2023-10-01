#ifndef __TABLE__H__
#define __TABLE__H__
#include "����.h"

#define MAX_TBL	100
typedef int HashFunc(Key k); //��ȯ���� int�� �Լ��� ������ �ִ� �Լ� ������ ���� int (*HashFunc)(key)���� �� ���ŷο�
typedef struct {  //�ؽ��Լ��� ������ �����
	Slot tbl[MAX_TBL]; //���Ե� Ű�� ���, ���� ����ü�� ����� �ϴ� ����ü 
	HashFunc* hf;
}Table;
void TBLInit(Table* pt, HashFunc* f);
void TBLInsert(Table* pt, Key k,Value v);
Value TBLDelete(Table* pt, Key k); //Ű�� �Է¹ް� ���̺��� ����
Value TBLSearch(Table* pt, Key k);


#endif