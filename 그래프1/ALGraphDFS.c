//#include<stdio.h>
//#include<string.h>
//#include"�迭����.h"
//#include"ALGrapnDFS.h"
//#include"���Ḯ��Ʈ.h"
//
//
//int WhoIsPrecede(int data1, int data2) {  //�׷����� ���� ���Ḯ��Ʈ���� ���ĺ������� ����
//	if (data1 < data2)
//		return 0;
//	else
//		return 1;
//}
//
//void GraphInit(ALGraph* pg, int v) {
//	int i;
//	pg->adjList = (List*)malloc(sizeof(List));  //����Ʈ ������ �޸� �Ҵ� 
//	pg->numE = 0; pg->numV = v;
//	for (i = 0; i < v; i++) {
//		ListInit(&(pg->adjList[i])); //�׷����� ��� ����Ʈ �ʱ�ȭ (�����ʹ� �迭�̴�)
//		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);  //����Ʈ ��ҵ� ���� 
//	}
//	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);//������ �� ��ŭ �迭 �Ҵ� 
//	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);// �迭�� ��� 0���� �ʱ�ȭ
//}
//void GraphDestory(ALGraph* pg) {
//	if (pg->adjList != NULL)
//		free(pg->adjList);  //�Ҵ�� �޸� �ʱ�ȭ
//	if (pg->visitInfo != NULL)
//		free(pg->visitInfo);
//}
//void AddEdge(ALGraph* pg, int fromV, int toV) {
//	LInsert(&(pg->adjList[fromV]), toV);  //���� fromV�� ���Ḯ��Ʈ�� toV���� �߰�
//	LInsert(&(pg->adjList[toV]), fromV);  //toV���� ���� �߰�
//	pg->numE++;
//}
//void ShowGraphEdgeInfo(ALGraph* pg) {
//	int i, vx;
//	for (i = 0; i < pg->numV; i++) {
//		printf("%c�� ����� ���� ", i + 65); //i�� �ش��ϴ� ĳ���Ͱ� ��ȯ
//		if (LFirst(&(pg->adjList[i]), &vx)); //i������Ʈ�� ���� ���� vx=���� ����Ʈ ��ġ�� ������ 
//		{
//			printf("%c ", vx + 65);
//			while (LNext(&(pg->adjList[i]), &vx)) //i�� ����Ʈ������ ��� �����ϸ鼭 ����� ���� ���
//			printf("%c ", vx + 65);
//
//		}
//		printf("\n");
//	}
//
//}
//int VisitVertex(ALGraph* pg, int visitV) {
//	if (pg->visitInfo[visitV] == 0)  //ó�� �湮�϶� 
//	{
//		pg->visitInfo[visitV] = 1; //1�̶�� �湮 �÷��׸� ����
//		printf("%c ",visitV + 65);
//		return TRUE; //1��ȯ
//	}
//	return FALSE; //ó�� �湮�� �ƴѰ�� 
//}
//void DFShowGraphVertex(ALGraph* pg, int startV) {  //visitV�� �ε����� ǥ���Ѵ�
//	Stack stack;
//	int visitV = startV;//�湮�� ����
//	int nextV;  //������ �湮�� ���� 
//	StackInit(&stack);
//	VisitVertex(pg, visitV);//������ �湮
//	//SPush(&stack, visitV);
//	//ù �湮�� ������ ������ ����� �������� �湮�õ��ϴ� �ݺ���
//	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)//�һ��Ϸ��� ������ ����� ������ ������ 
//	{
//		int visitFlag = FALSE;
//		if (VisitVertex(pg, nextV)==TRUE) { //����� ������ �湮 ����������
//			SPush(&stack, visitV);  //�� Ʈ��ŷ�� ���� ���� ���� ���ÿ� �ֱ�
//			visitV = nextV; 
//			visitFlag = TRUE;
//		}
//		else//�湮�� ����->�̹� �湮������ �ִ°��
//		{
//			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)//�ٸ� ����� ������ �ִ°��
//			{
//				if (VisitVertex(pg, nextV) == TRUE) //�湮 �����Ҷ� 
//				{
//					SPush(&stack, visitV);
//					visitV = nextV;
//					visitFlag = TRUE;
//					break;
//				}
//			}
//		}
//		if (visitFlag == FALSE)//�湮�� �����Ѱ��
//		{
//			if (SIsEmpty(&stack) == TRUE)//������ �� ����==ó������ ���ƿ°��
//				break;
//			else
//				visitV = SPop(&stack);
//		}
//	}
//	memset(pg->visitInfo, 0, sizeof(int) * pg->numV); //������ Ž���� ���� ���� �ʱ�ȭ
//
//}