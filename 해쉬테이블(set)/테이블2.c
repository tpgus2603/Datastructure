#include"테이블2.h"
#include<stdio.h>
#include<stdlib.h>

void TBLInit(Table* pt, HashFunc* f) {
	int i;
	for (i = 0; i < MAX_TBL; i++)
		ListInit(&(pt->tbl[i])); //테이블속 리스트 배열 하나하나 초기화
	pt->hf = f;
}
void TBLInsert(Table* pt, Key k, Value v) {
	int hv = pt->hf(k);
	Slot ns = { k,v };
	if (TBLSearch(pt, k) != NULL)  //키가 중복된경우
	{
		printf("키 중복오류 발생");
		return;
	}
	else
	{
		LInsert(&(pt->tbl[hv]), ns); //해당하는 리스트에 슬롯 넣기 
	}
}
Value TBLDelete(Table* pt, Key k) {
	int hv = pt->hf(k);
	Slot cSlot;
	if (LFirst(&(pt->tbl[hv]), &cSlot)) {  //key에 리스트의 노드가 비어있지 않은경우=데이터가 있는경우
		LRemove(&(pt->tbl[hv]));
		return cSlot.val;  //제거후 밸류 반환
	}
	else
	{
		while (LNext(&(pt->tbl[hv]), &cSlot)) //리스트의 다음 노드 확인했는데 데이터가 있는경우
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