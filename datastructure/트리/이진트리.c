#include<stdio.h>
#include<stdlib.h>
#include"����Ʈ��.h"

BTreeNode* MakeTreeNode() { //��� ���� �� �ʱ�ȭ
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
BTreeNode* GetLeftSubTree(BTreeNode* bt) { //���� ����Ʈ���� ��Ʈ����� �ּҰ� ��ȯ
	return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt) {
	return bt->right;
}
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {//���� ����Ʈ���� ����
	if (main->left != NULL)
		free(main->left);   //������ ���� Ʈ���� �̹� ����Ǿ������� ���� Ʈ�� ����
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

void InorderTraverse(BTreeNode* bt,VisitFuncPtr action) {  //���� ��ȸ:����->��Ʈ->������
	if (bt == NULL) 
		return;
	InorderTraverse(bt->left,action);
	action(bt->data); //��Ʈ ��� ������ ���
	InorderTraverse(bt->right,action);

}
void PreorderTraverse(BTreeNode* bt,VisitFuncPtr action) { //���� ��ȸ  ��Ʈ �� ��
	if (bt == NULL)
		return;
	action(bt->data);
	PreorderTraverse(bt->left,action);
	PreorderTraverse(bt->right,action);
}
void PostorderTraverse(BTreeNode* bt,VisitFuncPtr action) { //���� ��ȸ:�޿���
	if (bt == NULL)
		return;
	PostorderTraverse(bt->left,action);
	PostorderTraverse(bt->right,action);
	action(bt->data);
}
