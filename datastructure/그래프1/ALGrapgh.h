#ifndef __AL_GRAPH__
#define __AL_GRAPH__

#include"���Ḯ��Ʈ.h"

enum { A, B, C, D, E, F, G, H, I, J }; //���� ���ȭ

typedef struct{
	int numV;
	int numE;
	List * adjList;  //����Ʈ �迭 
}ALGraph;

void GraphInit(ALGraph* pg, int v); //������ �����ڷ� �׷��� �ʱ�ȭ
void GraphDestory(ALGraph* pg);
void AddEdge(ALGraph* pg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph* pg);
#endif