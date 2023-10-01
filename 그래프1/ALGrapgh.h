#ifndef __AL_GRAPH__
#define __AL_GRAPH__

#include"연결리스트.h"

enum { A, B, C, D, E, F, G, H, I, J }; //정점 상수화

typedef struct{
	int numV;
	int numE;
	List * adjList;  //리스트 배열 
}ALGraph;

void GraphInit(ALGraph* pg, int v); //정점의 수인자로 그래프 초기화
void GraphDestory(ALGraph* pg);
void AddEdge(ALGraph* pg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph* pg);
#endif