#include"����Ʈ��.h"
#include<stdio.h>
int main() {
	char exp[] = "12+7*";
	BTreeNode * etree = MakeExpTree(exp);
	printf("���� ǥ����� ����: ");
	ShowPrefixTypeExp(etree); printf("\n");
	printf("���� ǥ����� ����: ");
	ShowInfixTypeExp(etree); printf("\n");
	printf("���� ǥ����� ���� ");
	ShowPostfixTypeExp(etree); printf("\n");
	printf("������ ��� : %d\n", EvalutateExpTree(etree));

	return 0;


}