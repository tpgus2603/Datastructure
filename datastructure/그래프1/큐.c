#include<stdio.h>
#include<stdlib.h>
#include "ť.h"

//ť ��� ��Ʈ�� f,r,Data �迭
void QueueInit(Queue* pq) {
	pq->front = 0;
	pq->rear = 0;
}
int QIsEmpty(Queue* pq) {
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}
int NextPosIdx(int pos) {
	if (pos == QUE_LEN - 1)
		return 0;  //���� �迭�� ������ �ε������ 0���� ��ȯ
	else
		return pos + 1;   //���� ���� �ε����� ���� �ε��� ��ȯ
}
void Enqueue(Queue* pq, Data data) {
	if (NextPosIdx(pq->rear) == pq->front) {  //ť�� �������
		printf("Queue Memory Error");
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);   //���� ��ĭ �ű�
	pq->queArr[pq->rear] = data;  //������ ������ ����
}
Data Dequeue(Queue* pq) {
	if (QIsEmpty(pq))
	{
		printf("Queue MemoryError!");
		exit(-1);
	}
	pq->front = NextPosIdx(pq->front); //�Ǿ��� ����Ű�� �ε��� �ű�� 
	return pq->queArr[pq->front]; //����Ʈ
}
Data QPeek(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}
	return pq->queArr[NextPosIdx(pq->front)]; //ó���� ����ȵ����� ��ȯ


}

