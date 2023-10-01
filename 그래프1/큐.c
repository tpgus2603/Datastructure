#include<stdio.h>
#include<stdlib.h>
#include "큐.h"

//큐 멤버 인트형 f,r,Data 배열
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
		return 0;  //꽉찬 배열의 마지막 인덱스라면 0으로 순환
	else
		return pos + 1;   //다음 현재 인덱스의 다음 인덱스 반환
}
void Enqueue(Queue* pq, Data data) {
	if (NextPosIdx(pq->rear) == pq->front) {  //큐가 꽉찬경우
		printf("Queue Memory Error");
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);   //꼬리 한칸 옮김
	pq->queArr[pq->rear] = data;  //꼬리에 데이터 저장
}
Data Dequeue(Queue* pq) {
	if (QIsEmpty(pq))
	{
		printf("Queue MemoryError!");
		exit(-1);
	}
	pq->front = NextPosIdx(pq->front); //맨앞을 가르키는 인덱스 옮기기 
	return pq->queArr[pq->front]; //프론트
}
Data QPeek(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}
	return pq->queArr[NextPosIdx(pq->front)]; //처음에 저장된데이터 반환


}

