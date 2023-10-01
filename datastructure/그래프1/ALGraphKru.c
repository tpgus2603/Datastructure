#include<stdio.h>
#include<string.h>
#include"�迭����.h""
#include"���Ḯ��Ʈ.h"
#include"ALGrapghKru.h"



int WhoIsPrecede(int data1, int data2) {  //�׷����� ���� ���Ḯ��Ʈ���� ���ĺ������� ����
	if (data1 < data2)
		return 0;
	else
		return 1;
}
int PQWeightComp(Edge d1, Edge d2) {  //�������� ���� ������ ����  ->ũ�罺Į 2
	return d1.weight - d2.weight;
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
	PQueueInit(&(pg->pqueue), PQWeightComp);
}
void GraphDestory(ALGraph* pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);  //�Ҵ�� �޸� �ʱ�ȭ
	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}
void AddEdge(ALGraph* pg, int fromV, int toV,int weight) {
	Edge edge = { fromV,toV,weight };  //������ ����ġ ������ ���� 
	LInsert(&(pg->adjList[fromV]), toV);  //���� fromV�� ���Ḯ��Ʈ�� toV���� �߰�
	LInsert(&(pg->adjList[toV]), fromV);  //toV���� ���� �߰�
	pg->numE++;
	PEnqueue(&(pg->pqueue), edge); //������ ������ ����ġ�� �켱ť�� ���� 

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
void DFShowGraphVertex(ALGraph* pg, int startV) {  //visitV�� �ε����� ǥ���Ѵ�
	Stack stack;
	int visitV = startV;//�湮�� ����
	int nextV;  //������ �湮�� ���� 
	StackInit(&stack);
	VisitVertex(pg, visitV);//������ �湮
	//SPush(&stack, visitV);
	//ù �湮�� ������ ������ ����� �������� �湮�õ��ϴ� �ݺ���
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)//�һ��Ϸ��� ������ ����� ������ ������ 
	{
		int visitFlag = FALSE;
		if (VisitVertex(pg, nextV) == TRUE) { //����� ������ �湮 ����������
			SPush(&stack, visitV);  //�� Ʈ��ŷ�� ���� ���� ���� ���ÿ� �ֱ�
			visitV = nextV;
			visitFlag = TRUE;
		}
		else//�湮�� ����->�̹� �湮������ �ִ°��
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)//�ٸ� ����� ������ �ִ°��
			{
				if (VisitVertex(pg, nextV) == TRUE) //�湮 �����Ҷ� 
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}
		if (visitFlag == FALSE)//�湮�� �����Ѱ��
		{
			if (SIsEmpty(&stack) == TRUE)//������ �� ����==ó������ ���ƿ°��
				break;
			else
				visitV = SPop(&stack);
		}
	}
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV); //������ Ž���� ���� ���� �ʱ�ȭ
}
void conKruMST(ALGraph* pg) //MST���� 
{
	Edge recvEdge[20];  //������ ������ ������ ������ �迭
	Edge edge;
	int eidx = 0;
	int i;
	while (pg->numE + 1 > pg->numV)  //�����Ǽ�+1==�����Ǽ��� �ɶ� ���� �ݺ�
	{
		edge = PDequeue(&(pg->pqueue)); //����ġ�� ���� ���� ���� ���� 
		RemoveEdge(pg, edge.v1, edge.v2); //���� ����
		if (!IsConnVertex(pg, edge.v1, edge.v2)) {//�����ϸ� ����� �н��� ������
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);  //���� ȸ��
			recvEdge[eidx++] = edge; //�迭�� ���� ť�������� �ݺ������� �ٽ� �����⿡ �ݺ��� �ۿ��� ������ ���� �ֱ� 
		}
	}
	for (i = 0; i < eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);  //������ ���� �ٽ� ť���ֱ�(ť�� �����ؾ� ���Ŀ� �ٽ� �߰� �� ��°���) 

}
void ShowGraphEdgeWeight(ALGraph* pg) {
	PQueue copyPQ = pg->pqueue;  //���� ť�� �ջ��Ű���ʰ� ����ϱ����� �������� 
	Edge edge;
	while (!PQIsEmpty(&copyPQ)) {
		edge = PDequeue(&copyPQ);
		printf("(%c -%c), w: %d\n", edge.v1 + 65, edge.v2 + 65, edge.weight);
	}
}
void RemoveEdge(ALGraph* pg, int fromV, int toV) {
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
}
void RemoveWayEdge(ALGraph* pg, int fromV, int toV) {
	int edge;
	//fromV�� ����� ���� ã�� ����Ʈ�ȿ� ����
	if (LFirst(&(pg->adjList[fromV]),&edge)){
		if (edge == toV)  //toV�� ����Ǿ�������
		{
			LRemove(&(pg->adjList[fromV]));
			return;//������ ����
		}
		while (LNext(&(pg->adjList[fromV]), &edge)){
			if (edge == toV) {
				LRemove(&(pg->adjList[fromV]));
				return;
			}

		}
	}
}
void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight) { //����ġ�� ������� ť�� �߰����� �ʰ� ������ ȸ�� 
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE++;
}
int IsConnVertex(ALGraph* pg, int v1, int v2) //�� ������ ����� ��ΰ� ������ TRUE(���������� �ƴϾ)
{
	Stack stack;
	int visitV = v1;
	int nextV;
	StackInit(&stack);
	VisitVertex(pg, visitV);  //v1�湮
	SPush(&stack, visitV);
	//dfsŽ������ ���Ῡ�� ã�� 
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) { //v1������ ����� ���� ã��
		int visitFlag = FALSE;
		if (nextV == v2) {//v2�� ��ġ�ϸ� TRUE
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return TRUE;
		}
		if (VisitVertex(pg, nextV) == TRUE) //����� ������ �湮 �����ϸ�
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else {// ��ġ���� �ʴ°�� 
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)//�ٸ� ����� ������ �ִ°��
			{
				if (VisitVertex(pg, nextV) == TRUE) //�湮 �����Ҷ� 
				{
					if (nextV == v2) {
						memset(pg->visitInfo, 0, sizeof(int) * pg->numV); //�湮��� �ʱ�ȭ
						return TRUE;
					}
					if (VisitVertex(pg, nextV) == TRUE) //����� ������ �湮 �����ϸ�
					{
						SPush(&stack, visitV);
						visitV = nextV;
						visitFlag = TRUE;
						break;
					}

				}
			}
			if (visitFlag == FALSE)//v1������ ����� ������ ���°�� 
			{
				if (SIsEmpty(&stack) == TRUE) //������ �ֺ���
					break;
				else
					visitV = SPop(&stack);

			}

		}
	}
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	return FALSE; //������� ���� ��ǥ�� ��ã����

}
