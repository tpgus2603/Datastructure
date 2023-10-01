//#include "단순힙.h"
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
//int GetHiPriChildIdx(Heap* ph, int idx) {  // 자식 노드중 우선 순위 높은 인덱스 반환
//	if (GetLChildIdx(idx) > ph->numOfData) // idx가 단말노드인 경우 
//		return 0;
//	else if (GetLChildIdx(idx) == ph->numOfData) { //왼쪽 자식이 마지막일때
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
//void HInsert(Heap * ph, HData data, Priority pr){  // 궁극 적으로 인덱스==pr
//	int idx = ph->numOfData + 1; //idx는 삽입 할 놈의 인덱스 
//	HeapElem nelem = { pr,data };
//	while (idx != 1) { //루트 노드의 인덱스가 1이므로 루트노드 까지 비교 
//		if (pr < (ph->heapArr[GetParentIdX(idx)].pr)) { //부모 우선순위 보다 높은 경우 부모랑 위치 바꾸기
//			ph->heapArr[idx] = ph->heapArr[GetParentIdX(idx)];
//			idx = GetParentIdX(idx);
//			}
//		else
//			break;
//		}
//	ph->heapArr[idx] = nelem;
//	ph->numOfData += 1;
//	}
//HData HDelete(Heap* ph) {  //루트 노드 삭제?...  자식노드가 마지막노드보다 우선순위가 높으면 부모자리로 이동 
//	HData retData = ph->heapArr[1].data;
//	HeapElem lastElem = ph->heapArr[ph->numOfData];
//	int parentIdx = 1; int childIdx;
//	while (childIdx = GetHiPriChildIdx(ph, parentIdx)) { // 단말노드 인경우도 반복문 종료 
//		if (lastElem.pr <= ph->heapArr[childIdx].pr) //마지막 배열의 우선순위에 다가가면 + 인덱스 범위 넘어서면 0번 인덱스  
//			break;
//		ph->heapArr[parentIdx] = ph->heapArr[childIdx];  //부모노드 자리에 자식 노드 
//		parentIdx = childIdx;
//	}
//	ph->heapArr[parentIdx] = lastElem;
//	ph->numOfData -= 1;
//	return retData;
//}
//
//
