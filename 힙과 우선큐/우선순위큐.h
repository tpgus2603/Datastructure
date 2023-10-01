#ifndef __PQ_H__
#define __PQ_H__

#include "À¯¿ëÇÑÈü.h"

typedef Heap PQueue;
typedef HData PQData;

void PQueueInit(PQueue* pq, PriorityComp pc);
int PQIsEmpty(PQueue* ppq);
void PEnqueue(PQueue* pq, PQData data);
PQData PDequeue(PQueue* pq);




#endif // !__PQ_H__
