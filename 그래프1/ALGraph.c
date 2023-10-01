//#include<stdio.h>
//#include<stdlib.h>
//#include"ALGrapgh.h"
//int WhoIsPrecede(int data1, int data2) {
//	if (data1 < data2)
//		return 0;
//	else
//		return 1;
//}
//
//void GraphInit(ALGraph* pg, int v) {
//	int i;
//	pg->adjList = (List*)malloc(sizeof(List)*v);  //리스트 포인터 메모리 할당 
//	pg->numE = 0; pg->numV = v;
//	for (i = 0; i < v; i++) {
//		ListInit(&(pg->adjList[i])); //그래프속 모든 리스트 초기화 (포인터는 배열이다)
//		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
//	}
//}
//void GraphDestory(ALGraph* pg) {
//	if (pg->adjList != NULL)
//		free(pg->adjList);  //할당된 메모리 초기화
//}
//void AddEdge(ALGraph* pg, int fromV, int toV) {
//	LInsert(&(pg->adjList[fromV]), toV);  //정점 fromV의 연결리스트에 toV정보 추가
//	LInsert(&(pg->adjList[toV]), fromV);  //toV에도 정보 추가
//	pg->numE++;
//}
//void ShowGraphEdgeInfo(ALGraph* pg) {
//	int i, vx;
//	for (i = 0; i < pg->numV; i++) {
//		printf("%c와 연결된 정점 ", i + 65); //i에 해당하는 캐릭터값 반환
//		if (LFirst(&(pg->adjList[i]), &vx)); //i번리스트에 대해 진행 vx=현재 리스트 위치의 데이터 
//		{
//			printf("%c ", vx + 65);
//			while (LNext(&(pg->adjList[i]), &vx)) //i번 리스트에대해 계속 진행하면서 연결된 정점 출력
//				printf("%c ", vx + 65);
//
//		}
//		printf("\n");
//	}
//
//}