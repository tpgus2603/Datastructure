#include"수식트리.h"
#include<stdio.h>
int main() {
	char exp[] = "12+7*";
	BTreeNode * etree = MakeExpTree(exp);
	printf("전위 표기법의 수식: ");
	ShowPrefixTypeExp(etree); printf("\n");
	printf("중위 표기법의 수식: ");
	ShowInfixTypeExp(etree); printf("\n");
	printf("후위 표기법의 수식 ");
	ShowPostfixTypeExp(etree); printf("\n");
	printf("연산의 결과 : %d\n", EvalutateExpTree(etree));

	return 0;


}