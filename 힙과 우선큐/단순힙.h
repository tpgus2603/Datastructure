#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct _headElem {  //힙의 노드 우선순위와 데이터
	Priority pr;  //노드의 우선순위 고유 번호 =힙 배열의 인덱스
	HData data;
}HeapElem;

typedef struct _heap {
	int numOfData; //총 데이터 수
	HeapElem heapArr[HEAP_LEN];   //힙 배열
}Heap; 

void HeapInit(Heap* ph);
int HIsEmpty(Heap* ph);
void HInsert(Heap* ph, HData data, Priority pr);
HData HDelete(Heap* ph);
#endif
