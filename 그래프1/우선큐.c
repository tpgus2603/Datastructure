#include"�켱ť.h"
#include<stdio.h>
//#include "��������.h"

void PQueueInit(PQueue* pq, PriorityComp pc) {
	HeapInit(pq, pc);
}
int PQIsEmpty(PQueue* ppq) {
	return HIsEmpty(ppq);
}
void PEnqueue(PQueue* pq, PQData data) {
	HInsert(pq, data);
}
PQData PDequeue(PQueue* pq) {
	HDelete(pq);
}