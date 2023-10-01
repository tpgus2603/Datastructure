#include<stdio.h>
#include<string.h>
#include"배열스택.h""
#include"연결리스트.h"
#include"ALGrapghKru.h"



int WhoIsPrecede(int data1, int data2) {  //그래프의 인접 연결리스트들을 알파벳순으로 정렬
	if (data1 < data2)
		return 0;
	else
		return 1;
}
int PQWeightComp(Edge d1, Edge d2) {  //내림차순 정보 꺼내기 위함  ->크루스칼 2
	return d1.weight - d2.weight;
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
	PQueueInit(&(pg->pqueue), PQWeightComp);
}
void GraphDestory(ALGraph* pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);  //할당된 메모리 초기화
	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}
void AddEdge(ALGraph* pg, int fromV, int toV,int weight) {
	Edge edge = { fromV,toV,weight };  //간선의 가중치 정보를 담음 
	LInsert(&(pg->adjList[fromV]), toV);  //정점 fromV의 연결리스트에 toV정보 추가
	LInsert(&(pg->adjList[toV]), fromV);  //toV에도 정보 추가
	pg->numE++;
	PEnqueue(&(pg->pqueue), edge); //간선의 정점과 가중치를 우선큐에 저장 

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
void DFShowGraphVertex(ALGraph* pg, int startV) {  //visitV는 인덱스로 표현한다
	Stack stack;
	int visitV = startV;//방문한 정점
	int nextV;  //다음에 방문할 정점 
	StackInit(&stack);
	VisitVertex(pg, visitV);//시작점 방문
	//SPush(&stack, visitV);
	//첫 방문에 성공한 정점과 연결된 정점들을 방문시도하는 반복문
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)//텀색하려는 정점과 연결된 정점이 있을때 
	{
		int visitFlag = FALSE;
		if (VisitVertex(pg, nextV) == TRUE) { //연결된 정점에 방문 성공했을때
			SPush(&stack, visitV);  //백 트랙킹을 위한 이전 정점 스택에 넣기
			visitV = nextV;
			visitFlag = TRUE;
		}
		else//방문에 실패->이미 방문한적이 있는경우
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)//다른 연결된 정점이 있는경우
			{
				if (VisitVertex(pg, nextV) == TRUE) //방문 가능할때 
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}
		if (visitFlag == FALSE)//방문에 실패한경우
		{
			if (SIsEmpty(&stack) == TRUE)//스택이 다 빈경우==처음으로 돌아온경우
				break;
			else
				visitV = SPop(&stack);
		}
	}
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV); //이후의 탐색을 위해 정보 초기화
}
void conKruMST(ALGraph* pg) //MST구성 
{
	Edge recvEdge[20];  //복원할 간선의 정보를 저장할 배열
	Edge edge;
	int eidx = 0;
	int i;
	while (pg->numE + 1 > pg->numV)  //간선의수+1==정점의수가 될때 까지 반복
	{
		edge = PDequeue(&(pg->pqueue)); //가중치가 제일 높은 간선 정보 
		RemoveEdge(pg, edge.v1, edge.v2); //간선 삭제
		if (!IsConnVertex(pg, edge.v1, edge.v2)) {//삭제하면 연결된 패스가 없을때
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);  //간선 회복
			recvEdge[eidx++] = edge; //배열에 저장 큐에넣으면 반복문에서 다시 꺼내기에 반복문 밖에서 복원할 간선 넣기 
		}
	}
	for (i = 0; i < eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);  //복원할 간선 다시 큐에넣기(큐를 복구해야 추후에 다시 추가 및 출력가능) 

}
void ShowGraphEdgeWeight(ALGraph* pg) {
	PQueue copyPQ = pg->pqueue;  //원래 큐를 손상시키지않고 출력하기위해 깊은복사 
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
	//fromV와 연결된 간선 찾기 리스트안에 있음
	if (LFirst(&(pg->adjList[fromV]),&edge)){
		if (edge == toV)  //toV와 연결되어있으면
		{
			LRemove(&(pg->adjList[fromV]));
			return;//삭제후 종료
		}
		while (LNext(&(pg->adjList[fromV]), &edge)){
			if (edge == toV) {
				LRemove(&(pg->adjList[fromV]));
				return;
			}

		}
	}
}
void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight) { //가중치에 상관없이 큐에 추가하지 않고 간선만 회복 
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE++;
}
int IsConnVertex(ALGraph* pg, int v1, int v2) //두 정점이 연결된 통로가 있으면 TRUE(직접연결이 아니어도)
{
	Stack stack;
	int visitV = v1;
	int nextV;
	StackInit(&stack);
	VisitVertex(pg, visitV);  //v1방문
	SPush(&stack, visitV);
	//dfs탐색으로 연결여부 찾기 
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) { //v1에대해 연결된 정점 찾기
		int visitFlag = FALSE;
		if (nextV == v2) {//v2와 일치하면 TRUE
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return TRUE;
		}
		if (VisitVertex(pg, nextV) == TRUE) //연결된 정점에 방문 성공하면
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else {// 일치하지 않는경우 
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)//다른 연결된 정점이 있는경우
			{
				if (VisitVertex(pg, nextV) == TRUE) //방문 가능할때 
				{
					if (nextV == v2) {
						memset(pg->visitInfo, 0, sizeof(int) * pg->numV); //방문기록 초기화
						return TRUE;
					}
					if (VisitVertex(pg, nextV) == TRUE) //연결된 정점에 방문 성공하면
					{
						SPush(&stack, visitV);
						visitV = nextV;
						visitFlag = TRUE;
						break;
					}

				}
			}
			if (visitFlag == FALSE)//v1에대해 연결된 정점이 없는경우 
			{
				if (SIsEmpty(&stack) == TRUE) //스택이 텅빈경우
					break;
				else
					visitV = SPop(&stack);

			}

		}
	}
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	return FALSE; //여기까지 오면 목표를 못찾은것

}
