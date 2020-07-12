#include <iostream>
#include <stack>
#include <queue>

using namespace std;
typedef int ElemType;

typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, *BiTree;

void PreOrder(BiTree T) {
	if (T) {
		cout << T->data << "\t";
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BiTree T) {
	if (T) {
		InOrder(T->lchild);
		cout << T->data << "\t";
		InOrder(T->rchild);
	}
}

void PostOrder(BiTree T) {
	if (T) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data << "\t";
	}
}

void PreOrder2(BiTree T) {
	stack<BiTNode*> s;
	BiTNode* p = T;
	while (p || !s.empty())
	{
		if (p) {
			cout << p->data << "\t";
			s.push(p);
			p = p->lchild;
		}
		else {
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}

void InOrder2(BiTree T) {
	stack<BiTNode*> s;
	BiTNode* p = T;
	while (p || !s.empty()) {//p has not point every Node
							//or stil has node not print
		if (p) {
			s.push(p);
			p = p->lchild;
		}
		else {
			p = s.top();
			cout << p->data << "\t";
			s.pop();
			p = p->rchild;
		}
	}
}

void PostOrder2(BiTree T) {
	stack<BiTNode*> s;
	BiTNode* p = T;
	BiTNode* r = NULL;
	while (p || !s.empty()) {
		if (p) {//go to the left utill p is null
			s.push(p);
			p = p->lchild;

		}
		else {
			//back 1 step
			p = s.top();
			//p's rchid is not null and has not been visited
			if (p->rchild && p->rchild != r) {
				p = p->rchild;
			}
			//rchild is null or has been visited
			else {
				cout << p->data << "\t";
				s.pop();
				r = p;
				p = NULL;//go back to line 84 to eusure p will not go left agiain
			}
		}
	}
}


void LevelOrder(BiTree T) {
	queue<BiTNode*> q;
	BiTNode* p;

	q.push(T);
	while (!q.empty())
	{
		p = q.front();
		q.pop();

		cout << p->data << "\t";
		if (p->lchild)
		{
			q.push((p->lchild));
		}
		if (p->rchild)
		{
			q.push(p->rchild);
		}

	}
}