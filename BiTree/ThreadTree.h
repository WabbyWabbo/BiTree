#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct ThreadNode {
	ElemType data;
	ThreadNode *lchild, *rchild;
	int ltag, rtag;//0 means lchild/rchild, 1 means pre/next
}ThreadNode, *ThreadTree;

void InThread(ThreadTree p, ThreadTree &pre) {
	if (p) {
		InThread(p->lchild, pre);
		if (!p->lchild) {
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre && !pre->rchild) {
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		InThread(p->rchild, pre);
	}
}

void CreateInThread(ThreadTree T) {
	ThreadTree pre = NULL;
	InThread(T, pre);
	pre->rchild = NULL;
	pre->rtag = 1;
}

//first node
ThreadNode* first_node_InThread(ThreadTree T) {
	ThreadNode *p = T;
	while (p->ltag == 0) {
		p = p->lchild;
	}
	return p;
}

//last node
ThreadNode* last_node_InThread(ThreadTree T) {
	ThreadNode* p = T;
	while (p->rtag == 0) {
		p = p->rchild;
	}
	return p;
}

//node before p
ThreadNode* pre_node_InThread(ThreadTree T, ThreadNode* node) {
	ThreadNode* p = node;
	if (p->ltag == 1) {
		p = p->lchild;
	}
	else {
		p = p->lchild;
		while (p->rtag != 1) {
			p = p->rchild;
		}
	}
	return p;
}

//node after p
ThreadNode* suc_node_InThread(ThreadTree T, ThreadNode* node) {
	ThreadNode* p = node;
	if (p->rtag == 1) {
		p = p->rchild;
	}
	else {
		p = p->rchild;
		while (p->ltag != 1) {
			p = p->lchild;
		}
	}
	return p;
}

//use threadtree to traverse
void TraverseInOrder(ThreadTree T) {
	ThreadNode* p = first_node_InThread(T);
	while (p != NULL) {
		cout << p->data << "\t";
		p = suc_node_InThread(T, p);
	}
}
