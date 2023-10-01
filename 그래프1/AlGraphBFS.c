#include<stdio.h>
#include<string.h>
#include"AlGraphBFS.h"
#include"연결리스트.h"
#include"큐.h"


int WhoIsPrecede(int data1, int data2) {  //그래프의 인접 연결리스트들을 알파벳순으로 정렬
	if (data1 < data2)
		return 0;
	else
		return 1;
}

void GraphInit(ALGraph* pg, int v) {
	int i;
	pg->adjList = (List*)malloc(sizeof(List));  //리스트 포인터 메모리 할당 
	pg->numE = 0; pg->numV = v;
	for (i = 0; i < v; i++) {
		ListInit(&(pg->adjList[i])); //그래프속 모든 리스트 초기화 (포인터는 배열이다)
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);  //리스트 요소들 정렬 
	}
	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);//정점의 수 만큼 배열 할당 
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);// 배열의 요소 0으로 초기화
}
void GraphDestory(ALGraph* pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);  //할당된 메모리 초기화
	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}
void AddEdge(ALGraph* pg, int fromV, int toV) {
	LInsert(&(pg->adjList[fromV]), toV);  //정점 fromV의 연결리스트에 toV정보 추가
	LInsert(&(pg->adjList[toV]), fromV);  //toV에도 정보 추가
	pg->numE++;
}
void ShowGraphEdgeInfo(ALGraph* pg) {
	int i, vx;
	for (i = 0; i < pg->numV; i++) {
		printf("%c와 연결된 정점 ", i + 65); //i에 해당하는 캐릭터값 반환
		if (LFirst(&(pg->adjList[i]), &vx)); //i번리스트에 대해 진행 vx=현재 리스트 위치의 데이터 
		{
			printf("%c ", vx + 65);
			while (LNext(&(pg->adjList[i]), &vx)) //i번 리스트에대해 계속 진행하면서 연결된 정점 출력
				printf("%c ", vx + 65);

		}
		printf("\n");
	}

}
int VisitVertex(ALGraph* pg, int visitV) {
	if (pg->visitInfo[visitV] == 0)  //처음 방문일때 
	{
		pg->visitInfo[visitV] = 1; //1이라는 방문 플래그를 남김
		printf("%c ", visitV + 65);
		return TRUE; //1반환
	}
	return FALSE; //처음 방문이 아닌경우 
}
void BFShowGraphVertex(ALGraph* pg, int startV) {
	Queue queue;
	int visitV = startV;
	int nextV;
	QueueInit(&queue);
	VisitVertex(pg, visitV); //첫 정점 방문
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)//첫 정점과 연결된 정점 찾기
	{
		if (VisitVertex(pg, nextV) == TRUE) //연결된 정점에 대해 방문
			Enqueue(&queue, nextV);  //참이면 큐에 넣음 
		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) //연결된 다음 정점 찾기
		{
			if (VisitVertex(pg, nextV) == TRUE)  //연결된 정점이면 큐에 넣음 
				Enqueue(&queue, nextV);
		}
		if (QIsEmpty(&queue) == TRUE)
			break;  //큐가 비었으면 반보문 종료
		else
			visitV = Dequeue(&queue);  //큐에 있는 정점과 연결된 정점 탐색 

	}
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

}

