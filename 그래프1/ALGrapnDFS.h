#ifndef __AL_GRAPH_DFS__
#define __AL_GRAGH_DFS__
#include"연결리스트.h"

enum { A, B, C, D, E, F, G, H, I, J }; //정점 상수화

typedef struct {
	int numV;
	int numE;
	List* adjList;  //인접 리스트 배열 
	int* visitInfo;  //탐색이 진행된 정점을 담을 배열 
}ALGraph;

void GraphInit(ALGraph* pg, int v); //정점의 수인자로 그래프 초기화
void GraphDestory(ALGraph* pg);
void AddEdge(ALGraph* pg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph* pg);   //간선 정보 출력
void DFShowGraphVertex(ALGraph* pg, int startV); //dfs기반 정점 정보 출력


#endif