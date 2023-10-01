#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE  1
#define FALSE 0

#define HEAP_LEN 100
typedef char HData;
typedef int PriorityComp(HData h1, HData h2);
typedef struct _heap {
	PriorityComp* comp; //�켱���� �� �Լ�
	int numOfData;  //�迭�� ũ��
	HData heapArr[HEAP_LEN];  //�� �迭

}Heap;
void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);
void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);
#endif