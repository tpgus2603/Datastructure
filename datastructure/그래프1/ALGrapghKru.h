#ifndef __AL_GRAPH_KRU__
#define __AL_GRAGH_KRU__
#include"���Ḯ��Ʈ.h"
#include"�켱ť.h"
#include"ALEdge.h"

enum { A, B, C, D, E, F, G, H, I, J }; //���� ���ȭ

typedef struct {
	int numV;
	int numE;
	List* adjList;  //���� ����Ʈ �迭 
	int* visitInfo;  //Ž���� ����� ������ ���� �迭 
	PQueue pqueue;
}ALGraph;


void GraphInit(ALGraph* pg, int v); //������ �����ڷ� �׷��� �ʱ�ȭ
void GraphDestory(ALGraph* pg);
void AddEdge(ALGraph* pg, int fromV, int toV,int weight);
void ShowGraphEdgeInfo(ALGraph* pg);   //���� ���� ���
void DFShowGraphVertex(ALGraph* pg, int startV); //dfs��� ���� ���� ���
void conKruMST(ALGraph* pg); //�ּҺ�� ����Ʈ�� ũ�罺Į�� ����
void ShowGraphEdgeWeightInfo(ALGraph* pg);  //����ġ ���� ��� 


#endif