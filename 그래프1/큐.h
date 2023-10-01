#ifndef __C_QUEUE_H
#define __C_QUEUE_H

#define TRUE	1
#define	FALSE	0

#define QUE_LEN	6
typedef int Data;

typedef struct _cQueue {
	int front;  // �Ӹ� �ε���
	int rear;   //���� �ε���
	Data queArr[QUE_LEN];
}CQueue;
typedef CQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);

#endif