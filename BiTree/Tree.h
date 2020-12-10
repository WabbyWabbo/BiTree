/*
chapter 4.4
*/

#define MAX_TREE_SIZE 100
typedef int ElemType;

//1.parent 
typedef struct {
	ElemType data;
	int parent;
}PTNode;
typedef struct {
	ElemType nodes[MAX_TREE_SIZE];
	int n;//number of nodes
}PTree;

//2.child
typedef struct CNode {
	ElemType data;
	CNode* next;
}CNode;
typedef struct {
	CNode nodes[MAX_TREE_SIZE];
	int n;
}CTree;

//3.parent-child
typedef struct CSNode{
	ElemType data;
	CSNode* firstchild, * nextsibling;
}CSNode,*CSTree;

