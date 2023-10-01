#include"���̺�2.h"
#include<stdio.h>
#include<stdlib.h>

void TBLInit(Table* pt, HashFunc* f) {
	int i;
	for (i = 0; i < MAX_TBL; i++)
		ListInit(&(pt->tbl[i])); //���̺�� ����Ʈ �迭 �ϳ��ϳ� �ʱ�ȭ
	pt->hf = f;
}
void TBLInsert(Table* pt, Key k, Value v) {
	int hv = pt->hf(k);
	Slot ns = { k,v };
	if (TBLSearch(pt, k) != NULL)  //Ű�� �ߺ��Ȱ��
	{
		printf("Ű �ߺ����� �߻�");
		return;
	}
	else
	{
		LInsert(&(pt->tbl[hv]), ns); //�ش��ϴ� ����Ʈ�� ���� �ֱ� 
	}
}
Value TBLDelete(Table* pt, Key k) {
	int hv = pt->hf(k);
	Slot cSlot;
	if (LFirst(&(pt->tbl[hv]), &cSlot)) {  //key�� ����Ʈ�� ��尡 ������� �������=�����Ͱ� �ִ°��
		LRemove(&(pt->tbl[hv]));
		return cSlot.val;  //������ ��� ��ȯ
	}
	else
	{
		while (LNext(&(pt->tbl[hv]), &cSlot)) //����Ʈ�� ���� ��� Ȯ���ߴµ� �����Ͱ� �ִ°��
		{
			if (cSlot.key == k)
			{
				LRemove(&(pt->tbl[hv]));
				return cSlot.val;
			}
		}
	}
}
Value TBLSearch(Table* pt, Key k) {
	int hv = pt->hf(k);
	Slot cSlot;
	if (LFirst(&(pt->tbl[hv]), &cSlot)) {
		if (cSlot.key == k)
			return cSlot.val;
		else {
			while (LNext(&(pt->tbl[hv]), &cSlot)) {
				if (cSlot.key == k)
					return cSlot.val;
			}
		}
	}

	return NULL;
}