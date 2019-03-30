#include<stdio.h>
#include<stdlib.h>

//声明结构体变量
typedef struct Node {
	int id;//代表结点的序号
	int value;//结点的值
	struct Node*next;//结构体的指针域
} Node;


int Print(Node * head) ;
Node*CreateList();
Node* CreateNode(int x) ;
Node* SearchNode(Node* pHead, int x);
int Insert(Node** ppHead, Node* pN, int  x);
int DeleteNode(Node** ppHead, Node* pN);
int GetNumber();
int FreeList(Node* L)  ;
void menu();
