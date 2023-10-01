#ifndef __AB_STACK_H__
#define __AB_STACK_H__
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100
typedef int Data;

typedef struct _arrayStack {
	Data statckArr[STACK_LEN];
	int topIndex;
}ArrayStack;
typedef ArrayStack Stack;

void StackInit(Stack* pstack); //스택의 초기화
int SIsEmpty(Stack* pstack); //스택이 빈것을 확인
void SPush(Stack* pstack, Data data); //push연산
Data SPop(Stack* pstack);  //pop연산
Data SPeek(Stack* pstack);  //peek연산
#endif