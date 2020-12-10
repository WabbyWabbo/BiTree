//#include "BiTree.h"
//
//int main(void) {
//	BiTree T = (BiTree)malloc(sizeof(BiTNode));
//	T->data = 1;
//	BiTNode *N2 = (BiTNode*)malloc(sizeof(BiTNode));
//	N2->data = 2;
//	BiTNode* N3 = (BiTNode*)malloc(sizeof(BiTNode));
//	N3->data = 3;
//	BiTNode* N4 = (BiTNode*)malloc(sizeof(BiTNode));
//	N4->data = 4;
//	BiTNode* N5 = (BiTNode*)malloc(sizeof(BiTNode));
//	N5->data = 5;
//	BiTNode* N6 = (BiTNode*)malloc(sizeof(BiTNode));
//	N6->data = 6;
//
//	T->lchild = N2;
//	T->rchild = N3;
//	N2->lchild = NULL;
//	N2->rchild = N4;
//	N3->lchild = NULL;
//	N3->rchild = N5;
//	N4->lchild = N6;
//	N4->rchild = NULL;
//	N5->lchild = NULL;
//	N5->rchild = NULL;
//	N6->lchild = NULL;
//	N6->rchild = NULL;
//
//	PreOrder2(T);
//	cout << endl;
//	InOrder2(T);
//	cout << endl;
//	PostOrder2(T);
//	cout << endl;
//	LevelOrder(T);
//}