#include "BiTree.h"

/*
@return key's parent if found
@p point to the key's parent, used for insert or delete
*/
BiTNode* BST_Search(BiTree T, ElemType key, BiTNode*& p) {
	p = NULL;
	while (T != NULL && key != T->data) {
		p = T;
		if (key < T->data)
			T = T->lchild;
		else
			T = T->rchild;
	}
	return T;
}

int BST_Insert(BiTree& T, ElemType key) {
	if (T == NULL) {
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = key;
		T->lchild = T->rchild = NULL;
		return 1;//sucess
	}
	else if (key == T->data)
		return 0;//already existed
	else if (key < T->data)
		return BST_Insert(T->lchild, key);
	else
		return BST_Insert(T->rchild, key);
}

void BST_Create(BiTree& T, ElemType str[], int n) {
	T = NULL;
	for (int i = 0; i < n; i++) {
		BST_Insert(T, str[i]);
	}
}

int BST_Delete(BiTree& T, ElemType key) {
	BiTNode* parent;
	BiTNode* result = BST_Search(T, key, parent);
	if (result == NULL) {
		return 0;//not such key
	}
	else {
		if (result->lchild == NULL && result->rchild == NULL) {

			if(parent->lchild == result)
				parent->lchild = NULL;
			else
				parent->rchild = NULL;

			free(result);
			return 1;
		}
		else if (result->rchild != NULL) {
			if (parent->lchild == result)
				parent->lchild = result->rchild;
			else
				parent->rchild = result->rchild;
			free(result);
			return 1;
		}
		else if (result->lchild != NULL) {
			if (parent->lchild == result)
				parent->lchild = result->lchild;
			else
				parent->rchild = result->lchild;
			free(result);
			return 1;
		}
		else {
			//find result's next element q
			//parent move with q to make sure parent is q's parent
			BiTNode* q = result->rchild;
			while (q->lchild != NULL) {
				parent = q;
				q = q->lchild;
			}
			//copy q's data to replace result's
			result->data = q->data;
			//delete q, q may have rchild
			if (q->rchild == NULL) {
				parent->lchild = NULL;
				free(q);
				return 1;
			}
			else{
				parent->lchild = q->rchild;
				free(q);
				return 1;
			}
		}
	}
}
