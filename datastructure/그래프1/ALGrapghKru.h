#ifndef __AL_GRAPH_KRU__
#define __AL_GRAGH_KRU__
#include"연결리스트.h"
#include"우선큐.h"
#include"ALEdge.h"

enum { A, B, C, D, E, F, G, H, I, J }; //정점 상수화

typedef struct {
	int numV;
	int numE;
	List* adjList;  //인접 리스트 배열 
	int* visitInfo;  //탐색이 진행된 정점을 담을 배열 
	PQueue pqueue;
}ALGraph;


void GraphInit(ALGraph* pg, int v); //정점의 수인자로 그래프 초기화
void GraphDestory(ALGraph* pg);
void AddEdge(ALGraph* pg, int fromV, int toV,int weight);
void ShowGraphEdgeInfo(ALGraph* pg);   //간선 정보 출력
void DFShowGraphVertex(ALGraph* pg, int startV); //dfs기반 정점 정보 출력
void conKruMST(ALGraph* pg); //최소비용 신장트리 크루스칼로 구성
void ShowGraphEdgeWeightInfo(ALGraph* pg);  //가중치 정보 출력 


#endif