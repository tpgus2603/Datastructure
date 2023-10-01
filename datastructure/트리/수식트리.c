#include"리스트기반스택.h"
#include<stdio.h>
#include"수식트리.h"
#include"이진트리.h"
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

BTreeNode* MakeExpTree(char exp[]) { 
	Stack stack;
	BTreeNode* pnode;
	int expLen = strlen(exp);
	int i;
	StackInit(&stack);
	for (i = 0; i < expLen; i++) {
		pnode = MakeTreeNode();
		if (isdigit(exp[i])) { //숫자인경우
			SetData(pnode, exp[i] - '0');  //정수로 바꿔서 저장
		}
		else {  //연산자인경우 
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		SPush(&stack,pnode);//노드를  스택에 쌓음 트리를 통쨰로 넣기도 함
	}
	return SPop(&stack);
}
int EvalutateExpTree(BTreeNode* bt) {
	int op1, op2;
	/*op1 = GetData(GetLeftSubTree(bt));
	op2 = GetData(GetRightSubTree(bt));*/ //자식 노드에 서브트리가 있는경우 문제가 됨
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt); //bt가 단말 노드인 경우 해당 노드의 피 연산자 반환

	op1 = EvalutateExpTree(GetLeftSubTree(bt));
	op2 = EvalutateExpTree(GetRightSubTree(bt));  //재귀적으로 구현

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2; //return 이 break의 의미를 포함
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	default:
		break;
	}
	return 0;
}

void ShowNodeData(int data) {
	if (0 <= data && data <= 9) //data 0에서 9면 숫자
		printf("%d ", data);
	else
		printf("%c ", data);   //아닌경우 문자

}


void ShowPrefixTypeExp(BTreeNode* bt) {
	PreorderTraverse(bt, ShowNodeData);
}
void ShowInfixTypeExp(BTreeNode* bt){

	InorderTraverse(bt, ShowNodeData);
}
void ShowPostfixTypeExp(BTreeNode* bt) {
	PostorderTraverse(bt, ShowNodeData);
}
