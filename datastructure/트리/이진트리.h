#ifndef  __BINARY_TREE_H__
#define __BINARY_TREE_H__
typedef int BTData;

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

BTreeNode* MakeTreeNode();
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);
BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);
typedef void (*VisitFuncPtr) (BTData data); //타입이 보이드인 함수를 인자로 사용하는 함수포인터 typedef

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void DeleteTree(BTreeNode* bt);


#endif // ! __BINARY_TREE_H__
