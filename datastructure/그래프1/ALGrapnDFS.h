#ifndef __AL_GRAPH_DFS__
#define __AL_GRAGH_DFS__
#include"���Ḯ��Ʈ.h"

enum { A, B, C, D, E, F, G, H, I, J }; //���� ���ȭ

typedef struct {
	int numV;
	int numE;
	List* adjList;  //���� ����Ʈ �迭 
	int* visitInfo;  //Ž���� ����� ������ ���� �迭 
}ALGraph;

void GraphInit(ALGraph* pg, int v); //������ �����ڷ� �׷��� �ʱ�ȭ
void GraphDestory(ALGraph* pg);
void AddEdge(ALGraph* pg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph* pg);   //���� ���� ���
void DFShowGraphVertex(ALGraph* pg, int startV); //dfs��� ���� ���� ���


#endif