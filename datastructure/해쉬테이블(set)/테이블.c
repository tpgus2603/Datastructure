#include"테이블.h"
#include<stdio.h>
#include<stdlib.h>

void TBLInit(Table* pt, HashFunc* f) {
	int i;
	for (i = 0; i < MAX_TBL; i++) //Empty상태로 초기화
		(pt->tbl[i].status = EMPTY);
	pt->hf = f;  //해쉬 함수 등록
}
void TBLInsert(Table* pt, Key k, Value v) {  //테이블의 키에 해당하는 슬롯에 값과 키 저장
	int hv = pt->hf(k); //key값에 해쉬함수 적용->다른key값에 대해 해쉬값이 같은 경우가 충돌
	pt->tbl[hv].val = v;  //슬롯에 값 저장
	pt->tbl[hv].key = k;
	pt->tbl[hv].status = INUSE;
}
Value TBLDelete(Table* pt, Key k) {
	int hv = pt->hf(k);
	if (pt->tbl[hv].status != INUSE)  //사용중이 아닌 슬롯이라면 NULL반환
		return NULL;  
	else {
		pt->tbl[hv].status = DELETED; //status를 삭제로 놓는것으로 삭제과정 수행 
		return pt->tbl[hv].val;
	}
}
Value TBLSearch(Table* pt, Key k) {
	int hv = pt->hf(k);
	if (pt->tbl[hv].status != INUSE) {
		return NULL;
	}
	else
		return pt->tbl[hv].val; //탐색 대상의 값 반혼
}