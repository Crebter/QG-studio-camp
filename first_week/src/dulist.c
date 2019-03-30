
#include <stdlib.h>
#include <stdio.h>
/***************************************************************************************
 *	File Name				:	duLinkedList.h
 *	CopyRight				:	2019 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2019.3.20
 *	Author/Corportation		:	ed1son
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode *prior, *next;
} DuLNode, *DuLinkedList;

// define status
typedef enum Status
{
	ERROR,
	SUCCESS,
} Status;

/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L);

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Status DestroyList_DuL(DuLinkedList *L);

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e);

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif

/**
 *  @name        : InputNumber
 *	@description : to input a checked number
 *	@param		 : none
 *	@return		 : int
 *  @notice      : None
 */
int InputNumber()
{
	int num = 0; //存放转化后的数字
	int ret = 0; //控制循环
	int i = 0;
	char str[100]; //接收字符串
	printf("\nPlease input number:");

	do
	{

		scanf("%s", str);
		ret = 0;
		for (i = 0; str[i] != '\0'; i++)
		{
			//检查其中是否存在非法字符
			if (str[i] < '0' || str[i] > '9')
			{
				ret = -1;
			}
		}
		if (ret != -1)
		{
			//将字符串转成数字
			for (i = 0, num = 0; str[i] != '\0'; i++)
			{
				num *= 10;
				num += (str[i] - 48);
			}
			//检查输入的数字是否越界
			if (i >= 10)
			{
				ret = -1;
				printf("what you input is too big, input again : ");
			}
		}
		else
		{
			printf("what you input is not allowed,input again : ");
		}

	} while (ret == -1);
	printf("input success ! value = %d \n", num);
	return num;
}

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L)
{
	//创建头结点
	int i = 0;
	int value = 0;

	//如果头指针非空，不允许新建链表
	if ((*L) != NULL)
	{
		printf("\na list has already exist,please destroy it before create a new list!\n");
		system("pause");
		return ERROR;
	}
	printf("\nplease input value to create list : ");
	*L = (DuLNode *)malloc(sizeof(DuLNode));
	(*L)->data = 1234567890; //头结点赋值为超出允许输入的数值范围，防止对头结点非法操作
	(*L)->prior = NULL;
	(*L)->next = NULL;
	//指向头结点
	DuLNode *p = *L;
	//创建新结点并连接到当前结点的后面
	for (; *L; p = p->next)
	{
		value = InputNumber();
		if (value == 0)
			break;
		p->next = (DuLNode *)malloc(sizeof(DuLNode));
		p->next->data = value;
		p->next->prior = p;
	}
	if ((*L)->next == NULL)
	{
		printf("\ncan not create an empty list !\n");
		free((*L));
		(*L) = NULL;
		system("pause");
		return ERROR;
	}
	return SUCCESS;
}

/**
 *  @name        : Status PrintList(DuLinkedList *L);
 *	@description : print a list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status PrintList(DuLinkedList *L)
{
	DuLNode *p;
	//不输出空链表
	if (L == NULL || (*L) == NULL)
	{
		printf("No Linklist right now \n\n");
		return ERROR;
	}
	printf("the linklist is as follow:\n");
	for (p = (*L)->next; p; p = p->next)
	{
		if (p != (*L)->next)
			printf("->"); //在相邻两个结点的值之间插入箭头
		printf("%d", p->data);
	}
	printf("\n");
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Status DestroyList_DuL(DuLinkedList *L)
{
	DuLNode *p = *L;
	//检查链表是否为空
	if (L == NULL || (*L) == NULL)
	{
		printf("no list to free\n\n");
		system("pause");
		return ERROR;
	}
	while (p)
	{
		p = (*L)->next;
		free(*L);
		(*L) = p;
	}
	(*L) = NULL;
	printf("\nthe list has been free\n");
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
	//检查链表是否为空
	if (p == NULL || q == NULL)
	{
		printf("can not insert");
		getchar();
		return ERROR;
	}
	DuLNode *pre = p->prior;
	p->prior = q;
	q->next = p;
	q->prior = pre;
	pre->next = q;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
	//检查链表是否为空
	if (p == NULL || q == NULL)
	{
		printf("can not insert");
		getchar();
		return ERROR;
	}
	DuLNode *next = p->next;
	if (next == NULL)
	{
		p->next = q;
		q->prior = p;
		q->next = NULL;
	}
	else
	{
		p->next = q;
		next->prior = q;
		q->next = next;
		q->prior = p;
	}
	return SUCCESS;
}

/**
*  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
*	@description : delete the first node after the node p and assign its value to e
*	@param		 : p, e
*	@return		 : status
*  @notice      : None
*/
//删除其后面的节点，并记录其值给e
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{

	DuLNode *q; //q为p后面的一个节点

	//检查链表是否为空，所删除的结点是否存在
	if (p == NULL || p->next == NULL)
	{
		printf("\nthere is no node after it\n");
		system("pause");
		return ERROR;
	}
	if (p->next->next == NULL)
	{
		q = p->next;
		p->next = NULL;
		*e = q->data;
		free(q);
	}
	else
	{
		q = p->next;
		q->next->prior = p;
		p->next = q->next;
		*e = q->data;
		free(q);
	}

	return SUCCESS;
}

/**
 *  @name        : DuLNode* SearchNode(DuLNode* pHead, ELemType x)
 *	@description : to find a node where data = x
 *	@param		 : pHead, x
 *	@return		 : DuLNode
 *  @notice      : None
 */
DuLNode *SearchNode(DuLNode *pHead, ElemType x)
{ //查找结点
	DuLNode *tmp = pHead;
	//检查链表是否为空
	if (pHead == NULL)
	{
		printf("\nno list here\n");
		system("pause");
		return NULL;
	}
	while (tmp)
	{
		if (tmp->data == x)
			return tmp;
		else
			tmp = tmp->next;
	}
	return NULL;
}

void menu()
{ // 菜单

	DuLNode *head = NULL; //链表的头指针
	int n = 0;			  //用于接收用户输入的数值
	int position;		  //用于接收用户选择的操作位置的结点的值
	do
	{
		system("cls");
		printf("\n");
		printf("======================================================\n");
		printf("\n");
		printf("*****************双向链表的增删改查*******************\n\n");
		printf(" 1. -----创建一个新链表\n");
		printf(" 2. -----在某节点前插入一个结点\n");
		printf(" 3. -----在某节点后插入一个结点\n");
		printf(" 4. -----删除一个结点,并记录它的值\n");
		printf(" 5. -----清空链表\n");
		printf(" 6. -----退出\n\n");
		printf(" 开发者：@黄钰朝\n");
		printf("提示：创建链表时输入各个结点的值，以0代表结束.\n如：1回车2回车3回车0回车=1->2->3\n");
		printf("=======================================================\n\n");

		PrintList(&head);

		printf("please input your choose to execute : ");
		n = InputNumber();

		switch (n)
		{
		case 1:
			if (InitList_DuL(&head) == SUCCESS)
			{
				printf("\nA new list is already created\n\n");
				system("pause");
			}
			break;
		case 2:
			//检查是否存在有效链表
			if (head != NULL)
			{
				printf("\nplease input the value you want to insert into list\n");
				n = InputNumber();
				DuLNode *q = (DuLNode *)malloc(sizeof(DuLNode));
				q->data = n;
				printf("\nplease select the position you want to insert before \n");
				position = InputNumber();
				DuLNode *p = (DuLNode *)malloc(sizeof(DuLNode));
				p = SearchNode(head, position);
				//检查是否选择一个有效结点
				if (q != NULL)
				{
					if (q != head)
					{
						InsertBeforeList_DuL(p, q);
					}
					else
					{
						printf("\ncan not insert into head node\n");
						system("pause");
					}
				}
				else
				{
					printf("\nno such node\n");
					system("pause");
				}
			}
			else
			{
				printf("\nthere is no list now\n");
				system("pause");
			}
			break;
		case 3:
			//检查是否存在有效链表
			if (head != NULL)
			{
				printf("\nplease input the value you want to insert into list\n");
				n = InputNumber();
				DuLNode *q = (DuLNode *)malloc(sizeof(DuLNode));
				q->data = n;
				printf("\nplease select the position you want to insert after \n");
				position = InputNumber();
				DuLNode *p = SearchNode(head, position);
				//检查是否选择一个有效结点
				if (q != NULL)
				{
					if (q != head)
					{
						InsertAfterList_DuL(p, q);
					}
					else
					{
						printf("\ncan not insert into head node\n");
						system("pause");
					}
				}
				else
				{
					printf("\nno such node\n");
					system("pause");
				}
			}
			else
			{
				printf("\nthere is no list now\n");
				system("pause");
			}
			break;
		case 4:
			//检查是否存在有效链表
			if (head != NULL)
			{
				int e = 0;
				printf("\nplease input the node which you want to delete it's last node\n");
				n = InputNumber();
				DuLNode *p = SearchNode(head, n);
				//检查是否选择一个有效结点
				if (p != NULL)
				{
					if (DeleteList_DuL(p, &e) == SUCCESS)
					{
						printf("\nthe node you delete is %d \n", e);
						system("pause");
					}
				}
				else
				{
					printf("\nno such node\n");
					system("pause");
				}
			}
			else
			{
				printf("\nthere is no list now\n");
				system("pause");
			}
			break;
		case 5:
			//检查是否存在有效链表
			if (head != NULL)
			{
				if (DestroyList_DuL(&head))
				{
					printf("\nthe list have been destroy !\n");
				}
				else
				{
					printf("\nfail to destroy list ! \n");
				}
			}
			else
			{
				printf("\nthere is no list now\n");
				system("pause");
			}
			break;
		case 6:
			printf("\n\n========================Bye===========================\n\n");
			exit(0);
			break;
		default:
			//如果输入的字符无法匹配功能，则输出错误
			printf("\nwhat you input is beyond range\n");
			system("pause");
		}
	} while (1);
}

int main()
{
	menu();
	return 0;
}
