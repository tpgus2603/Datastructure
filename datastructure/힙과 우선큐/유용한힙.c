#include<stdio.h>
#include"유용한힙.h"

void HeapInit(Heap* ph, PriorityComp pc) {
	ph->numOfData = 0;
	ph->comp = pc;
}
int HIsEmpty(Heap* ph) {
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}
int GetParentIdx(int idx) {
	return idx / 2;
}
int GetLChildIdx(int idx) {
	return idx * 2;
}
int GetRChildIdx(int idx) {
	return GetLChildIdx(idx) + 1;
}
int GetHiPriChildIdx(Heap* ph, int idx) {
	if (GetLChildIdx(idx) > ph->numOfData)
		return 0;
	else if (GetLChildIdx(idx) == ph->numOfData)
		return GetLChildIdx(idx);
	else {
		if (ph->comp(ph->heapArr[GetLChildIdx(idx)], ph->heapArr[GetRChildIdx(idx)]) < 0)//우선순위 오른쪽이 높은
			return GetRChildIdx(idx);
		else
			return GetLChildIdx(idx);
	}
}
void HInsert(Heap* ph, HData data) {
	int idx = ph->numOfData+1; 
	while (idx != 1) {
		if (ph->comp(data, ph->heapArr[GetParentIdx(idx)]) > 0)  //data의 우선순위가 마지막 노드의 부모보다 높을때
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];//부모노드랑 마지막 노드 위치 바꿈
				idx = GetParentIdx(idx);
		}
		else {
			break;   //data의 우선순위가 같거나 낮을때 
		}
	}
	ph->heapArr[idx] = data;
	ph->numOfData += 1;

}
HData HDelete(Heap* ph) {
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];
	int parentIdx = 1;
	int childIdx = 0;
	while (childIdx = GetHiPriChildIdx(ph, parentIdx)) {
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}
	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}