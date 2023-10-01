#ifndef __TABLE2_HH
#define __TABLE2_HH

#include"슬롯2.h"
#include"연결리스트.h"

#define MAX_TBL	100
typedef int HashFunc(Key k);
typedef struct {
	List tbl[MAX_TBL];
	HashFunc* hf;
}Table;

void TBLInit(Table* pt, HashFunc* f);
void TBLInsert(Table* pt, Key k, Value v);
Value TBLDelete(Table* pt, Key k);
Value TBLSearch(Table* pt, Key k);

#endif