//#include "ThreadTree.h"
//
//int main(void) {
//	ThreadTree T = (ThreadTree)malloc(sizeof(ThreadNode));
//	T->data = 1;
//	ThreadNode* N2 = (ThreadNode*)malloc(sizeof(ThreadNode));
//	N2->data = 2;
//	ThreadNode* N3 = (ThreadNode*)malloc(sizeof(ThreadNode));
//	N3->data = 3;
//	ThreadNode* N4 = (ThreadNode*)malloc(sizeof(ThreadNode));
//	N4->data = 4;
//	ThreadNode* N5 = (ThreadNode*)malloc(sizeof(ThreadNode));
//	N5->data = 5;
//	ThreadNode* N6 = (ThreadNode*)malloc(sizeof(ThreadNode));
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
//	CreateInThread(T);
//
//	
//	//first node
//	cout << first_node_InThread(T)->data << "\t";
//	//last node
//	cout << last_node_InThread(T)->data << "\t";
//	//node before N4
//	cout << pre_node_InThread(T,N4)->data << "\t";
//	//node after N2
//	cout << suc_node_InThread(T,N2)->data << "\t" << endl;
//
//	//traverse
//	TraverseInOrder(T);
//}