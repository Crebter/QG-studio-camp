#include"list.h"


int Print(Node * head)
{
	Node * p = NULL;
	//输出本次创建的链表

	printf("the Linklist you have created is as follow:\n");
	if (head == NULL) {
		printf("no list now");
		system("pause");
		return -1;
	}
	for (p = head; p; p = p->next) {
		if (p != head)printf("->");//在相邻两个结点的值之间插入箭头
		printf("%d", p->value);
	}
	printf("\n");
	return 0;
}


Node*CreateList() {
	//创建头结点
	int x;
	int i;
	printf("please input value to create list");
	x = GetNumber();
	if (x == 0)return 0;
	struct Node*head = (struct Node*)malloc(sizeof(struct Node));
	head->id = 1;
	head->value = x;
	//指向头结点
	struct Node*p = head;
	//创建新结点并连接到当前结点的后面
	for (i = 2;; i++, p = p->next) {
		x = GetNumber();
		if (x == 0)break;
		p->next = (struct Node*)malloc(sizeof(struct Node));
		p->next->id = i;
		p->next->value = x;
	}
	p->next = NULL;//使最后一个结点的next为空指针
	return head;
}


Node* CreateNode(int x) { //创建节点
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL) {
		perror("Malloc fail");
		exit(1);
	}

	tmp->value = x;
	tmp->next = NULL;

	return tmp;
}

Node* SearchNode(Node* pHead, int x) { //查找结点
	Node* tmp = pHead;
	if (pHead == NULL) {
		printf("no list here");
		system("pause");
		return NULL;
	}
	while (tmp) {
		if (tmp->value == x)
			return tmp;
		else
			tmp = tmp->next;
	}
	return NULL;
}

int Insert(Node** ppHead, Node* pN, int  x) { //插入
	if (ppHead == NULL || pN == NULL) {
		printf("can not insert");
		getchar();
		return -1;
	}

	Node *p = (*ppHead);
	Node *q = CreateNode(x);

	while (p->next != pN) {
		p = p->next;
	}
	p->next = q;
	q->next = pN;
	return 0;
}


int DeleteNode(Node** ppHead, Node* pN) { //删除
	if (ppHead == NULL || pN == NULL) {
		printf("can not delete");
		getchar();
		return -1;
	}

	Node* tmp = *ppHead;
	while (tmp->next != pN) {
		tmp = tmp->next;
	}
	tmp->next = pN->next;

	free(pN);
	pN = NULL;
	return 0;
}

int GetNumber() {//输入一个数字，输入限制
	int n;
	int ret = 0;
	int cnt;
	do {
		ret = 0;
		printf("\n\n\tPlease enter number:");
		cnt = scanf("%d", &n);
		if (cnt == 0) {
			printf("\n\n\tWhat you imput is not a number!\n");
			for (; getchar() != '\n';);
			ret = -1;
		}
	} while (ret == -1);
	return n;
}


int FreeList(Node* L)
{
	Node* p = L;
	if (L == NULL) {
		printf("no list to free");
		system("pause");
		return -1;
	}
	while (p)
	{
		p = L->next;
		free(L);
		L = p;
	}
	printf("the list has been free\n");
	return 1;
}
void menu() { // 菜单

	Node*head = NULL;
	int ret = 1, x = 0;
	int n;
	int position;
	Node*q = NULL;
	Node*t = NULL;
	do {
		system("cls");
		printf("\n");
		printf("<-<-<-<-<-<-<-<-<-<->->->->->->->->->->\n");
		printf("\n");
		printf("链表的增删改查\n");
		printf(" \n");
		printf(" 1. 创建一个新链表\n");
		printf(" 2. 插入一个结点\n");
		printf(" 3. 删除一个结点\n");
		printf(" 4. 修改一个结点 \n");
		printf(" 5. 清空链表\n");
		printf(" 6. 退出\n");
		printf(" \n");
		printf(" 开发者：@黄钰朝\n");
		printf(" \n");
		printf(" 提示：创建链表时输入各个结点的值，以0代表结束，如：1回车2回车3回车0回车=1->2->3\n");
		printf("<-<-<-<-<-<-<-<-<-<->->->->->->->->->->\n\n");

		Print(head);

		do {
			printf("please input your choose:");
			x = GetNumber();
			if (x < 1 || x>6) {
				ret = 1;
				printf("what you input is beyond 1-6 \n");
			}
			else break;
		} while (ret == 1);
		switch (x) {
		case 1:
			head = CreateList();
			printf("\n\nA new list is already created");
			system("pause");
			break;
		case 2:
			if (head != NULL) {
				printf("please input the value you want to insert into list");
				n = GetNumber();
				printf("please select the position you want to insert into list");
				position = GetNumber();
				q = SearchNode(head, position);
				if (q != NULL) {
					if (q != head) {
						Insert(&head, q, n);
					}
					else {
						printf("can not insert into head node");
						system("pause");
					}

				}
				else {
					printf("no such node");
					system("pause");
				}

			}
			else {
				printf("there is no list now");
				system("pause");
			}


			break;
		case 3:
			if (head != NULL) {
				printf("please input the node you want to delete from list");
				n = GetNumber();
				q = SearchNode(head, n);
				if (q != NULL) {
					DeleteNode(&head, q);
				}
				else {
					printf("no such node");
					system("pause");
				}
			}
			else {
				printf("there is no list now");
				system("pause");
			}


			break;
		case 4:
			if (head != NULL) {
				printf("please input the node you want to midify");
				position = GetNumber();
				q = SearchNode(head, position);
				if (q != NULL) {
					printf("please input the new value");
					n = GetNumber();
					q->value = n;
				}
				else {
					printf("no such node");
					system("pause");
				}
			}
			else {
				printf("there is no list now");
				system("pause");
			}

			break;
		case 5:
			if (head != NULL) {

			}
			else {
				printf("there is no list now");
				system("pause");
			}
			FreeList(head);
			head = NULL;
			break;
		case 6:
			printf("\n\n========================Bye===========================\n\n");
			exit(0);

		}
	} while (1);
}

