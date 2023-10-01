#include<stdio.h>
#include<string.h>
#include"AlGraphBFS.h"
#include"���Ḯ��Ʈ.h"
#include"ť.h"


int WhoIsPrecede(int data1, int data2) {  //�׷����� ���� ���Ḯ��Ʈ���� ���ĺ������� ����
	if (data1 < data2)
		return 0;
	else
		return 1;
}

void GraphInit(ALGraph* pg, int v) {
	int i;
	pg->adjList = (List*)malloc(sizeof(List));  //����Ʈ ������ �޸� �Ҵ� 
	pg->numE = 0; pg->numV = v;
	for (i = 0; i < v; i++) {
		ListInit(&(pg->adjList[i])); //�׷����� ��� ����Ʈ �ʱ�ȭ (�����ʹ� �迭�̴�)
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);  //����Ʈ ��ҵ� ���� 
	}
	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);//������ �� ��ŭ �迭 �Ҵ� 
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);// �迭�� ��� 0���� �ʱ�ȭ
}
void GraphDestory(ALGraph* pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);  //�Ҵ�� �޸� �ʱ�ȭ
	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}
void AddEdge(ALGraph* pg, int fromV, int toV) {
	LInsert(&(pg->adjList[fromV]), toV);  //���� fromV�� ���Ḯ��Ʈ�� toV���� �߰�
	LInsert(&(pg->adjList[toV]), fromV);  //toV���� ���� �߰�
	pg->numE++;
}
void ShowGraphEdgeInfo(ALGraph* pg) {
	int i, vx;
	for (i = 0; i < pg->numV; i++) {
		printf("%c�� ����� ���� ", i + 65); //i�� �ش��ϴ� ĳ���Ͱ� ��ȯ
		if (LFirst(&(pg->adjList[i]), &vx)); //i������Ʈ�� ���� ���� vx=���� ����Ʈ ��ġ�� ������ 
		{
			printf("%c ", vx + 65);
			while (LNext(&(pg->adjList[i]), &vx)) //i�� ����Ʈ������ ��� �����ϸ鼭 ����� ���� ���
				printf("%c ", vx + 65);

		}
		printf("\n");
	}

}
int VisitVertex(ALGraph* pg, int visitV) {
	if (pg->visitInfo[visitV] == 0)  //ó�� �湮�϶� 
	{
		pg->visitInfo[visitV] = 1; //1�̶�� �湮 �÷��׸� ����
		printf("%c ", visitV + 65);
		return TRUE; //1��ȯ
	}
	return FALSE; //ó�� �湮�� �ƴѰ�� 
}
void BFShowGraphVertex(ALGraph* pg, int startV) {
	Queue queue;
	int visitV = startV;
	int nextV;
	QueueInit(&queue);
	VisitVertex(pg, visitV); //ù ���� �湮
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)//ù ������ ����� ���� ã��
	{
		if (VisitVertex(pg, nextV) == TRUE) //����� ������ ���� �湮
			Enqueue(&queue, nextV);  //���̸� ť�� ���� 
		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) //����� ���� ���� ã��
		{
			if (VisitVertex(pg, nextV) == TRUE)  //����� �����̸� ť�� ���� 
				Enqueue(&queue, nextV);
		}
		if (QIsEmpty(&queue) == TRUE)
			break;  //ť�� ������� �ݺ��� ����
		else
			visitV = Dequeue(&queue);  //ť�� �ִ� ������ ����� ���� Ž�� 

	}
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

}

