#include "BST.h"
int main(void) {
	//different sequence in str[] will create different BST
	int str1[] = { 45,24,55,12,37,53,60,28,40,70 };
	int str2[] = { 12,24,28,37,40,45,53,55,60,70 };
	BiTree T1;
	BST_Create(T1, str1, 10);//ASL=2.9
	BiTree T2;
	BST_Create(T2, str2, 10);//ASL=5.5

	return 0;
}