
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
	int num = 0; //���ת���������
	int ret = 0; //����ѭ��
	int i = 0;
	char str[100]; //�����ַ���
	printf("\nPlease input number:");

	do
	{

		scanf("%s", str);
		ret = 0;
		for (i = 0; str[i] != '\0'; i++)
		{
			//��������Ƿ���ڷǷ��ַ�
			if (str[i] < '0' || str[i] > '9')
			{
				ret = -1;
			}
		}
		if (ret != -1)
		{
			//���ַ���ת������
			for (i = 0, num = 0; str[i] != '\0'; i++)
			{
				num *= 10;
				num += (str[i] - 48);
			}
			//�������������Ƿ�Խ��
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
	//����ͷ���
	int i = 0;
	int value = 0;

	//���ͷָ��ǿգ��������½�����
	if ((*L) != NULL)
	{
		printf("\na list has already exist,please destroy it before create a new list!\n");
		system("pause");
		return ERROR;
	}
	printf("\nplease input value to create list : ");
	*L = (DuLNode *)malloc(sizeof(DuLNode));
	(*L)->data = 1234567890; //ͷ��㸳ֵΪ���������������ֵ��Χ����ֹ��ͷ���Ƿ�����
	(*L)->prior = NULL;
	(*L)->next = NULL;
	//ָ��ͷ���
	DuLNode *p = *L;
	//�����½�㲢���ӵ���ǰ���ĺ���
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
	//�����������
	if (L == NULL || (*L) == NULL)
	{
		printf("No Linklist right now \n\n");
		return ERROR;
	}
	printf("the linklist is as follow:\n");
	for (p = (*L)->next; p; p = p->next)
	{
		if (p != (*L)->next)
			printf("->"); //��������������ֵ֮������ͷ
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
	//��������Ƿ�Ϊ��
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
	//��������Ƿ�Ϊ��
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
	//��������Ƿ�Ϊ��
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
//ɾ�������Ľڵ㣬����¼��ֵ��e
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{

	DuLNode *q; //qΪp�����һ���ڵ�

	//��������Ƿ�Ϊ�գ���ɾ���Ľ���Ƿ����
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
{ //���ҽ��
	DuLNode *tmp = pHead;
	//��������Ƿ�Ϊ��
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
{ // �˵�

	DuLNode *head = NULL; //�����ͷָ��
	int n = 0;			  //���ڽ����û��������ֵ
	int position;		  //���ڽ����û�ѡ��Ĳ���λ�õĽ���ֵ
	do
	{
		system("cls");
		printf("\n");
		printf("======================================================\n");
		printf("\n");
		printf("*****************˫���������ɾ�Ĳ�*******************\n\n");
		printf(" 1. -----����һ��������\n");
		printf(" 2. -----��ĳ�ڵ�ǰ����һ�����\n");
		printf(" 3. -----��ĳ�ڵ�����һ�����\n");
		printf(" 4. -----ɾ��һ�����,����¼����ֵ\n");
		printf(" 5. -----�������\n");
		printf(" 6. -----�˳�\n\n");
		printf(" �����ߣ�@���ڳ�\n");
		printf("��ʾ����������ʱ�����������ֵ����0�������.\n�磺1�س�2�س�3�س�0�س�=1->2->3\n");
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
			//����Ƿ������Ч����
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
				//����Ƿ�ѡ��һ����Ч���
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
			//����Ƿ������Ч����
			if (head != NULL)
			{
				printf("\nplease input the value you want to insert into list\n");
				n = InputNumber();
				DuLNode *q = (DuLNode *)malloc(sizeof(DuLNode));
				q->data = n;
				printf("\nplease select the position you want to insert after \n");
				position = InputNumber();
				DuLNode *p = SearchNode(head, position);
				//����Ƿ�ѡ��һ����Ч���
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
			//����Ƿ������Ч����
			if (head != NULL)
			{
				int e = 0;
				printf("\nplease input the node which you want to delete it's last node\n");
				n = InputNumber();
				DuLNode *p = SearchNode(head, n);
				//����Ƿ�ѡ��һ����Ч���
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
			//����Ƿ������Ч����
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
			//���������ַ��޷�ƥ�书�ܣ����������
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
