//#include<stdio.h>
//#include<stdlib.h>
//#include"ALGrapgh.h"
//int WhoIsPrecede(int data1, int data2) {
//	if (data1 < data2)
//		return 0;
//	else
//		return 1;
//}
//
//void GraphInit(ALGraph* pg, int v) {
//	int i;
//	pg->adjList = (List*)malloc(sizeof(List)*v);  //����Ʈ ������ �޸� �Ҵ� 
//	pg->numE = 0; pg->numV = v;
//	for (i = 0; i < v; i++) {
//		ListInit(&(pg->adjList[i])); //�׷����� ��� ����Ʈ �ʱ�ȭ (�����ʹ� �迭�̴�)
//		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
//	}
//}
//void GraphDestory(ALGraph* pg) {
//	if (pg->adjList != NULL)
//		free(pg->adjList);  //�Ҵ�� �޸� �ʱ�ȭ
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
//				printf("%c ", vx + 65);
//
//		}
//		printf("\n");
//	}
//
//}