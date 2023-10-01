#include"����Ʈ��ݽ���.h"
#include<stdio.h>
#include"����Ʈ��.h"
#include"����Ʈ��.h"
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
		if (isdigit(exp[i])) { //�����ΰ��
			SetData(pnode, exp[i] - '0');  //������ �ٲ㼭 ����
		}
		else {  //�������ΰ�� 
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		SPush(&stack,pnode);//��带  ���ÿ� ���� Ʈ���� �뤊�� �ֱ⵵ ��
	}
	return SPop(&stack);
}
int EvalutateExpTree(BTreeNode* bt) {
	int op1, op2;
	/*op1 = GetData(GetLeftSubTree(bt));
	op2 = GetData(GetRightSubTree(bt));*/ //�ڽ� ��忡 ����Ʈ���� �ִ°�� ������ ��
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt); //bt�� �ܸ� ����� ��� �ش� ����� �� ������ ��ȯ

	op1 = EvalutateExpTree(GetLeftSubTree(bt));
	op2 = EvalutateExpTree(GetRightSubTree(bt));  //��������� ����

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2; //return �� break�� �ǹ̸� ����
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
	if (0 <= data && data <= 9) //data 0���� 9�� ����
		printf("%d ", data);
	else
		printf("%c ", data);   //�ƴѰ�� ����

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
