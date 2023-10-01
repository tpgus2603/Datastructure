#ifndef __TABLE__H__
#define __TABLE__H__
#include "슬롯.h"

#define MAX_TBL	100
typedef int HashFunc(Key k); //반환형이 int인 함수를 담을수 있는 함수 포인터 정의 int (*HashFunc)(key)보다 덜 번거로움
typedef struct {  //해쉬함수랑 슬롯을 멤버로
	Slot tbl[MAX_TBL]; //슬롯도 키와 밸류, 슬롯 열거체를 멤버로 하는 구조체 
	HashFunc* hf;
}Table;
void TBLInit(Table* pt, HashFunc* f);
void TBLInsert(Table* pt, Key k,Value v);
Value TBLDelete(Table* pt, Key k); //키를 입력받고 테이블에서 삭제
Value TBLSearch(Table* pt, Key k);


#endif