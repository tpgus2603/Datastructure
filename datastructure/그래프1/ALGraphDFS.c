//#include<stdio.h>
//#include<string.h>
//#include"배열스택.h"
//#include"ALGrapnDFS.h"
//#include"연결리스트.h"
//
//
//int WhoIsPrecede(int data1, int data2) {  //그래프의 인접 연결리스트들을 알파벳순으로 정렬
//	if (data1 < data2)
//		return 0;
//	else
//		return 1;
//}
//
//void GraphInit(ALGraph* pg, int v) {
//	int i;
//	pg->adjList = (List*)malloc(sizeof(List));  //리스트 포인터 메모리 할당 
//	pg->numE = 0; pg->numV = v;
//	for (i = 0; i < v; i++) {
//		ListInit(&(pg->adjList[i])); //그래프속 모든 리스트 초기화 (포인터는 배열이다)
//		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);  //리스트 요소들 정렬 
//	}
//	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);//정점의 수 만큼 배열 할당 
//	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);// 배열의 요소 0으로 초기화
//}
//void GraphDestory(ALGraph* pg) {
//	if (pg->adjList != NULL)
//		free(pg->adjList);  //할당된 메모리 초기화
//	if (pg->visitInfo != NULL)
//		free(pg->visitInfo);
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
//			printf("%c ", vx + 65);
//
//		}
//		printf("\n");
//	}
//
//}
//int VisitVertex(ALGraph* pg, int visitV) {
//	if (pg->visitInfo[visitV] == 0)  //처음 방문일때 
//	{
//		pg->visitInfo[visitV] = 1; //1이라는 방문 플래그를 남김
//		printf("%c ",visitV + 65);
//		return TRUE; //1반환
//	}
//	return FALSE; //처음 방문이 아닌경우 
//}
//void DFShowGraphVertex(ALGraph* pg, int startV) {  //visitV는 인덱스로 표현한다
//	Stack stack;
//	int visitV = startV;//방문한 정점
//	int nextV;  //다음에 방문할 정점 
//	StackInit(&stack);
//	VisitVertex(pg, visitV);//시작점 방문
//	//SPush(&stack, visitV);
//	//첫 방문에 성공한 정점과 연결된 정점들을 방문시도하는 반복문
//	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)//텀색하려는 정점과 연결된 정점이 있을때 
//	{
//		int visitFlag = FALSE;
//		if (VisitVertex(pg, nextV)==TRUE) { //연결된 정점에 방문 성공했을때
//			SPush(&stack, visitV);  //백 트랙킹을 위한 이전 정점 스택에 넣기
//			visitV = nextV; 
//			visitFlag = TRUE;
//		}
//		else//방문에 실패->이미 방문한적이 있는경우
//		{
//			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)//다른 연결된 정점이 있는경우
//			{
//				if (VisitVertex(pg, nextV) == TRUE) //방문 가능할때 
//				{
//					SPush(&stack, visitV);
//					visitV = nextV;
//					visitFlag = TRUE;
//					break;
//				}
//			}
//		}
//		if (visitFlag == FALSE)//방문에 실패한경우
//		{
//			if (SIsEmpty(&stack) == TRUE)//스택이 다 빈경우==처음으로 돌아온경우
//				break;
//			else
//				visitV = SPop(&stack);
//		}
//	}
//	memset(pg->visitInfo, 0, sizeof(int) * pg->numV); //이후의 탐색을 위해 정보 초기화
//
//}