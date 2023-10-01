#include<stdio.h>
#include<stdlib.h>
#include"배열기반스택.h"

void StackInit(Stack* pstack) {
	pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack) {
	if (pstack->topIndex == -1)  //스택이 ㅂ,어있으면
		return TRUE;
	else
		return FALSE;
}
void SPush(Stack* pstack, Data data) {
	pstack->topIndex += 1;
	pstack->statckArr[pstack->topIndex] = data;
}
Data SPop(Stack* pstack) {
	int rIdx;
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;
	return pstack->statckArr[rIdx]; //삭제되는 데이터 반환
}
Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory error!");
		exit(1);
	}
	return pstack->statckArr[pstack->topIndex];

}