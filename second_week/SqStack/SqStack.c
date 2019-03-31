#include "SqStack.h"

//顺序栈(基于数组的)
//初始化栈
Status initStack(SqStack *s, int sizes) {

	if (sizes <= 0) {
		printf("栈的大小必须大于0\n");
		return ERROR;
	}
	else {
		s->size = sizes;
		s->top = 0;
		s->elem = (ElemType*)malloc(sizeof(ElemType)*sizes);
		printf("成功创建一个大小为%d的栈\n", sizes);
		return SUCCESS;
	}
}

//判断栈是否为空
bool isEmptyStack(SqStack *s) {
	if (s->top == 0) {
		return true;
	}
	else
	{
		return false;
	}
}

//得到栈顶元素
Status getTopStack(SqStack *s, ElemType *e) {
	*e = *(s->elem + s->top - 1);
	return SUCCESS;
}
//清空栈
Status clearStack(SqStack *s) {
	s->top = 0;
	return SUCCESS;
}
//销毁栈
Status destroyStack(SqStack *s) {
	free(s->elem);
	s->elem = NULL;
	s->size = 0;
	return SUCCESS;
}
//检测栈长度
Status stackLength(SqStack *s, int *length) {
	*length = s->top;
	return SUCCESS;
}
//入栈
Status pushStack(SqStack *s, ElemType data) {
	if (s->top < s->size) {
		*(s->elem + s->top++) = data;
		printf("成功将元素%d压入栈\n", data);
		return SUCCESS;
	}
	else
	{
		printf("当前栈已满，不可压入新元素\n");
		return ERROR;
	}
}
//出栈
Status popStack(SqStack *s, ElemType *data) {
	if (s->top != 0) {
		*data = *(s->elem + s->top - 1);
		s->top--;
		printf("成功将元素%d推出栈\n", *data);
		return SUCCESS;
	}
	else
	{
		printf("当前栈已空\n");
		return ERROR;
	}
}

//打印当前栈的元素
Status printStack(SqStack * s) {
	if (s->size == 0) {
		printf("当前没有已经创建的栈\n");
		return ERROR;
	}
	else if (isEmptyStack(s)) {
		printf("当前栈的元素为 ： 空\n");
		return ERROR;
	}
	printf("当前栈的元素为 ：");
	for (int i = 0; i < s->top; i++) {
		if (i != 0) {
			//在相邻两个结点的值之间插入箭头
			printf("->");
		}
		printf("%d", *(s->elem + i));
	}
	printf("\n");
	return SUCCESS;
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


void menu()
{ // 菜单

	//栈顶指针
	SqStack head;
	head.elem = NULL;
	head.top = head.size = 0;
	//用于接收用户输入的数值
	int n = 0;
	ElemType e;
	do
	{
		system("cls");
		printf("\n");
		printf("======================================================\n");
		printf("\n");
		printf("*****************顺序栈的基本操作*******************\n\n");
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
			if (head.size != 0) {
				printf("已经存在一个栈，请先销毁当前栈\n");
				break;
			}
			else
			{
				do {
					printf("请输入栈的大小：");
				} while (initStack(&head, InputNumber()) == ERROR);
			}
			break;
		case 2:
			if (head.size == 0) {
				printf("当前没有已存的栈，请先初始化一个栈\n");
				break;
			}
			else
			{
				if (isEmptyStack(&head)) {
					printf("当前栈为空\n");
				}
				else
				{
					printf("当前栈非空\n");
				}
			}
			break;
		case 3:
			if (head.size == 0) {
				printf("当前没有已存的栈，请先初始化一个栈\n");
				break;
			}
			else
			{
				if (isEmptyStack(&head))
				{
					printf("当前栈为空，请先压入元素\n");
				}
				else
				{
					getTopStack(&head, &e);
					printf("栈顶元素为%d\n", e);
				}
			}
			break;
		case 4:
			if (head.size == 0) {
				printf("当前没有已存的栈，请先初始化一个栈\n");
				break;
			}
			else
			{
				if (isEmptyStack(&head))
				{
					printf("当前栈为空，不需要清空\n");
				}
				else
				{
					clearStack(&head);
					printf("成功清空当前栈\n");
				}
			}
			break;
		case 5:
			if (head.size == 0) {
				printf("当前没有已存的栈，请先初始化一个栈\n");
				break;
			}
			else
			{
				destroyStack(&head);
				printf("成功销毁当前栈\n");
			}
			break;
		case 6:
			if (head.size == 0) {
				printf("当前没有已存的栈，请先初始化一个栈\n");
				break;
			}
			else
			{
				stackLength(&head, &n);
				printf("当前栈的长度为%d\n", n);
			}
			break;
		case 7:
			if (head.size == 0) {
				printf("当前没有已存的栈，请先初始化一个栈\n");
				break;
			}
			else
			{
				printf("请输入要压入栈的元素：");
				pushStack(&head, InputNumber());
			}
			break;
		case 8:
			if (head.size == 0) {
				printf("当前没有已存的栈，请先初始化一个栈\n");
				break;
			}
			else
			{
				popStack(&head, &n);
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


