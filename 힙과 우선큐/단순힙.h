#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct _headElem {  //���� ��� �켱������ ������
	Priority pr;  //����� �켱���� ���� ��ȣ =�� �迭�� �ε���
	HData data;
}HeapElem;

typedef struct _heap {
	int numOfData; //�� ������ ��
	HeapElem heapArr[HEAP_LEN];   //�� �迭
}Heap; 

void HeapInit(Heap* ph);
int HIsEmpty(Heap* ph);
void HInsert(Heap* ph, HData data, Priority pr);
HData HDelete(Heap* ph);
#endif
