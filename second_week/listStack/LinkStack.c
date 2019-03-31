#include"LinkStack.h"

StackNode * bottom = NULL;
//链栈(基于链表的)
Status initLStack(LinkStack *s) {
	s->count = 0;
	s->top = (StackNode*)malloc(sizeof(StackNode));
	s->top->data = 1234567890;
	s->top->next = NULL;
	bottom = s->top;
	printf("成功创建一个栈\n");
	return SUCCESS;
}

bool isEmptyLStack(LinkStack *s) {
	if (s->count == 0) {
		return true;
	}
	else
	{
		return false;
	}
}

Status getTopLStack(LinkStack *s, ElemType *e) {
	*e = s->top->data;
	return SUCCESS;
}
Status clearLStack(LinkStack *s) {
	StackNode* p = NULL;
	s->count = 0;
	s->top = bottom;
	p = bottom = bottom->next;
	while (p)
	{
		p = bottom->next;
		free(bottom);
		bottom = p;
	}
	return SUCCESS;
}
Status destroyLStack(LinkStack *s) {
	StackNode* p = NULL;
	s->count = 0;
	s->top = NULL;
	while (p)
	{
		p = bottom->next;
		free(bottom);
		bottom = p;
	}
	return SUCCESS;
}
Status LStackLength(LinkStack *s, int *length) {
	*length = s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack *s, ElemType data) {
	StackNode * p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	p->next = NULL;
	s->top->next = p;
	s->top = p;
	s->count++;
	printf("成功将元素%d压入栈\n", data);
	return SUCCESS;
}
Status popLStack(LinkStack *s, ElemType *data) {
	StackNode * p = bottom;
	if (s->count == 0) {
		printf("当前栈已空\n");
		return ERROR;
	}
	else
	{
		*data = s->top->data;
		for (; p; p = p->next) {
			if (p->next == s->top) {
				free(p->next);
				p->next = NULL;
				s->top = p;
				s->count--;
				break;
			}
		}
		printf("成功将元素%d推出栈\n", *data);
		return SUCCESS;
	}
}

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
	int status = 0; //标志状态
	char str[100]; //接收字符串
	do
	{
		scanf("%s", str);
		status = SUCCESS;
		for (int i = 0; str[i] != '\0'; i++)
		{
			//检查其中是否存在非法字符
			if (i == 0) {
				if (str[i] == '-' || str[i] == '+')
					continue;
			}
			else {
				if (str[i] < '0' || str[i] > '9')
				{
					status = ERROR;
				}
			}
		}
		if (status == ERROR) {
			printf("\n您的输入中含有非法字符，请重新输入：");
		}
		else
		{
			int i = 0;
			//将字符串转成数字

			for (i = 0, num = 0; str[i] != '\0'; i++)
			{
				if (i == 0) {
					if (str[i] == '-' || str[i] == '+') {
						continue;
					}
					else
					{
						num *= 10;
						num += (str[i] - 48);
					}
				}
				else {
					num *= 10;
					num += (str[i] - 48);
				}
			}
			if (str[0] == '-') {
				num = -num;
			}
			//检查输入的数字是否越界
			if (i >= 10)
			{
				printf("\n你输入的数字已经越界，请重新输入: ");
				status = ERROR;
			}
		}
	} while (status == ERROR);
	printf("\n输入成功！您输入的数字为：%d\n", num);
	return num;
}

Status printStack(LinkStack * s)
{
	StackNode * p = NULL;
	if (s->top == NULL) {
		printf("当前没有已经创建的栈\n");
		return ERROR;
	}
	else if (isEmptyLStack(s)) {
		printf("当前栈的元素为 ： 空\n");
		return ERROR;
	}
	printf("当前栈的元素为 ：");
	for (p = bottom->next; p; p = p->next) {
		if (p != bottom->next) {
			printf("->");//在相邻两个结点的值之间插入箭头
		}
		printf("%d", p->data);
	}
	printf("\n");
	return SUCCESS;
}


void menu()
{ // 菜单

	//栈顶指针
	LinkStack head;
	head.count = 0;
	head.top = NULL;
	int n = 0;
	int e = 0;
	do {
		system("cls");
		printf("\n");
		printf("======================================================\n");
		printf("\n");
		printf("*****************链栈的基本操作*******************\n\n");
		printf(" 1. -----初始化一个新栈\n");
		printf(" 2. -----判断当前栈是否为空\n");
		printf(" 3. -----得到栈顶元素\n");
		printf(" 4. -----清空当前栈\n");
		printf(" 5. -----销毁当前栈\n");
		printf(" 6. -----检测栈的长度\n");
		printf(" 7. -----入栈\n");
		printf(" 8. -----出栈\n");
		printf(" 9. -----退出\n");
		printf(" 开发者：@黄钰朝\n");
		printf("=======================================================\n\n");
		//输出当前创建的栈
		printStack(&head);
		printf("请选择您想要执行的操作: ");
		switch (InputNumber())
		{
		case 1:
			if (head.top != NULL) {
				printf("已经存在一个栈，请先销毁当前栈\n");
				break;
			}
			else
			{
				initLStack(&head);

			}
			break;
		case 2:
			if (head.top == NULL) {
				printf("当前没有已存的栈，请先初始化一个栈\n");
				break;
			}
			else
			{
				if (isEmptyLStack(&head)) {
					printf("当前栈为空\n");
				}
				else
				{
					printf("当前栈非空\n");
				}
			}
			break;
		case 3:
			if (head.top == NULL) {
				printf("当前没有已存的栈，请先初始化一个栈\n");
				break;
			}
			else
			{
				if (isEmptyLStack(&head))
				{
					printf("当前栈为空，请先压入元素\n");
				}
				else
				{
					getTopLStack(&head, &e);
					printf("栈顶元素为%d\n", e);
				}
			}
			break;
		case 4:
			if (head.top == NULL) {
				printf("当前没有已存的栈，请先初始化一个栈\n");
				break;
			}
			else
			{
				if (isEmptyLStack(&head))
				{
					printf("当前栈为空，不需要清空\n");
				}
				else
				{
					clearLStack(&head);
					printf("成功清空当前栈\n");
				}
			}
			break;
		case 5:
			if (head.top == NULL) {
				printf("当前没有已存的栈，请先初始化一个栈\n");
				break;
			}
			else
			{
				destroyLStack(&head);
				printf("成功销毁当前栈\n");
			}
			break;
		case 6:
			if (head.top == NULL) {
				printf("当前没有已存的栈，请先初始化一个栈\n");
				break;
			}
			else
			{
				LStackLength(&head, &n);
				printf("当前栈的长度为%d\n", n);
			}
			break;
		case 7:
			if (head.top == NULL) {
				printf("当前没有已存的栈，请先初始化一个栈\n");
				break;
			}
			else
			{
				printf("请输入要压入栈的元素：");
				pushLStack(&head, InputNumber());
			}
			break;
		case 8:
			if (head.top == NULL) {
				printf("当前没有已存的栈，请先初始化一个栈\n");
				break;
			}
			else
			{
				popLStack(&head, &n);
			}
			break;

		case 9:
			printf("\n\n========================Bye===========================\n\n");
			exit(0);
			break;
		default:
			//如果输入的字符无法匹配功能，则输出错误
			printf("您输入的选项已经超出范围！\n");
		}
		system("pause");
	} while (1);
}
