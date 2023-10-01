#include<stdio.h>
#include<stdlib.h>
#include"이진트리.h"

BTreeNode* MakeTreeNode() { //노드 생성 후 초기화
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}
BTData GetData(BTreeNode* bt) {
	return bt->data;
}
void SetData(BTreeNode* bt, BTData data) {
	bt->data = data;
}
BTreeNode* GetLeftSubTree(BTreeNode* bt) { //왼쪽 서브트리의 루트노드의 주소값 반환
	return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt) {
	return bt->right;
}
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {//왼쪽 서브트리를 연결
	if (main->left != NULL)
		free(main->left);   //메인의 왼쪽 트리가 이미 연결되어있으면 기존 트리 제거
	main->left = sub;
}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->right != NULL)
		free(main->right);
	main->right = sub;
}
void DeleteTree(BTreeNode* bt) {
	if(bt == NULL)
		return;
	DeleteTree(bt->left);
	DeleteTree(bt->right);
	printf("del tree data: %d\n", bt -> data);
	free(bt);
}

void InorderTraverse(BTreeNode* bt,VisitFuncPtr action) {  //중위 순회:왼쪽->루트->오른쪽
	if (bt == NULL) 
		return;
	InorderTraverse(bt->left,action);
	action(bt->data); //루트 노드 데이터 출력
	InorderTraverse(bt->right,action);

}
void PreorderTraverse(BTreeNode* bt,VisitFuncPtr action) { //전위 순회  루트 왼 오
	if (bt == NULL)
		return;
	action(bt->data);
	PreorderTraverse(bt->left,action);
	PreorderTraverse(bt->right,action);
}
void PostorderTraverse(BTreeNode* bt,VisitFuncPtr action) { //후위 순회:왼오루
	if (bt == NULL)
		return;
	PostorderTraverse(bt->left,action);
	PostorderTraverse(bt->right,action);
	action(bt->data);
}
