#include<stdio.h>
#include<stdlib.h>

//�����ṹ�����
typedef struct Node {
	int id;//����������
	int value;//����ֵ
	struct Node*next;//�ṹ���ָ����
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
