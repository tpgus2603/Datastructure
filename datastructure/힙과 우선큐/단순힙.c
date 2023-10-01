//#include "�ܼ���.h"
//void HeapInit(Heap* ph) {
//	ph->numOfData = 0;
//}
//int HIsEmpty(Heap* ph) {
//	if (ph->numOfData == 0)
//		return TRUE;
//	else
//		return FALSE;
//}
//int GetParentIdX(int idx) {
//	return idx / 2;
//}
//int GetLChildIdx(int idx) {
//	return idx * 2;
//}
//int GetRChildIdx(int idx) {
//	return idx * 2 + 1;
//}
//int GetHiPriChildIdx(Heap* ph, int idx) {  // �ڽ� ����� �켱 ���� ���� �ε��� ��ȯ
//	if (GetLChildIdx(idx) > ph->numOfData) // idx�� �ܸ������ ��� 
//		return 0;
//	else if (GetLChildIdx(idx) == ph->numOfData) { //���� �ڽ��� �������϶�
//		return GetLChildIdx(idx);
//	}
//	else {
//		if (ph->heapArr[GetLChildIdx(idx)].pr > ph->heapArr[GetRChildIdx(idx)].pr)
//			return GetRChildIdx(idx);
//		else
//			return GetLChildIdx(idx);
//
//	}
//}
//void HInsert(Heap * ph, HData data, Priority pr){  // �ñ� ������ �ε���==pr
//	int idx = ph->numOfData + 1; //idx�� ���� �� ���� �ε��� 
//	HeapElem nelem = { pr,data };
//	while (idx != 1) { //��Ʈ ����� �ε����� 1�̹Ƿ� ��Ʈ��� ���� �� 
//		if (pr < (ph->heapArr[GetParentIdX(idx)].pr)) { //�θ� �켱���� ���� ���� ��� �θ�� ��ġ �ٲٱ�
//			ph->heapArr[idx] = ph->heapArr[GetParentIdX(idx)];
//			idx = GetParentIdX(idx);
//			}
//		else
//			break;
//		}
//	ph->heapArr[idx] = nelem;
//	ph->numOfData += 1;
//	}
//HData HDelete(Heap* ph) {  //��Ʈ ��� ����?...  �ڽĳ�尡 ��������庸�� �켱������ ������ �θ��ڸ��� �̵� 
//	HData retData = ph->heapArr[1].data;
//	HeapElem lastElem = ph->heapArr[ph->numOfData];
//	int parentIdx = 1; int childIdx;
//	while (childIdx = GetHiPriChildIdx(ph, parentIdx)) { // �ܸ���� �ΰ�쵵 �ݺ��� ���� 
//		if (lastElem.pr <= ph->heapArr[childIdx].pr) //������ �迭�� �켱������ �ٰ����� + �ε��� ���� �Ѿ�� 0�� �ε���  
//			break;
//		ph->heapArr[parentIdx] = ph->heapArr[childIdx];  //�θ��� �ڸ��� �ڽ� ��� 
//		parentIdx = childIdx;
//	}
//	ph->heapArr[parentIdx] = lastElem;
//	ph->numOfData -= 1;
//	return retData;
//}
//
//
