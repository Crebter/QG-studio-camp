#include"LQueue.h"
int data_size = 0;
char type;


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	if (Q->front == NULL) {
		printf("创建队列失败...");
		return;
	}
	data_size = InputType();
	Q->front->data = (void*)malloc(data_size);
	Q->length = 0;
	Q->front->data = 1234567890;
	Q->front->next = NULL;
	printf("创建队列成功...\n");
	return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q) {
	ClearLQueue(Q);
	free(Q->front);
	Q->front = Q->rear = NULL;
	Q = NULL;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q) {
	if (Q->length == 0) {
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e) {

	memcpy(e, Q->front->data, data_size);
	if (e == NULL) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data) {
	Node*p = (Node*)malloc(sizeof(Node));
	p->data = (void*)malloc(data_size);
	if (p == NULL) {
		printf("无法入队新元素...");
		return FALSE;
	}
	memcpy(p->data, data, data_size);
	p->next = NULL;

	if (Q->length == 0) {
		Q->front = Q->rear = p;
	}
	else
	{
		Q->rear->next = p;
		Q->rear = p;
	}
	Q->length++;
	printf("入队成功\n");
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q) {

	Node*  p = Q->front;
	if (Q->length == 1) {
		Q->front = Q->rear = (Node*)malloc(sizeof(Node));
		Q->length = 0;
	}
	else
	{
		Q->front = p->next;
		Q->length--;
		free(p);
		p = NULL;
	}

	printf("出队成功");
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
	if (Q->length == 0) {
		return;
	}
	Node*p = Q->front;
	Node*q = p;
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	Q->length = 0;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q->data);
		free(q);
	}
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void(*foo)(void *q)) {
	if (Q == NULL || IsEmptyLQueue(Q)) {
		return FALSE;
	}
	Node* p = Q->front;
	while (p) {
		(*foo)(p->data);
		if (p->next == NULL) {
			return TRUE;
		}
		printf("->");
		p = p->next;
	}
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void *q) {
	if (q == NULL) {
		return;
	}

	if (type == 's' || type == 'S') {
		short * e = (short*)q;
		printf("%d", *e);
	}
	else
		if (type == 'i' || type == 'I') {
			int *e = (int*)q;
			printf("%d", *e);
		}
		else
			if (type == 'l' || type == 'L')
			{
				long*e = (long*)q;
				printf("%ld", *e);
			}
			else
				if (type == 'f' || type == 'F')
				{
					float*e = (float*)q;
					printf("%f", *e);
				}
				else
					if (type == 'd' || type == 'D')
					{
						double *e = (double*)q;
						printf("%lf", *e);
					}
					else
						if (type == 'c' || type == 'C')
						{
							char* e = (char*)q;
							printf("%c", *e);
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
		status = TRUE;
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
					status = FALSE;
				}
			}
		}
		if (status == FALSE) {
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
				status = FALSE;
			}
		}
	} while (status == FALSE);
	printf("\n输入成功！您输入的数字为：%d\n", num);
	return num;
}

/*
* 接收用户输入的数据类型，返回该类型数据的大小
*/
int InputType()
{
	int ret = 0;
	do
	{
		ret = 0;
		printf("请选择队列的数据类型：[s]hort | [i]nt | [l]ong | [f]loat | [d]ouble | [c]har \n");
		printf("请输入一个字符：");
		type = getch();
		printf("\n");
		if (type == 's' || type == 'S')
			return 2;
		else
			if (type == 'i' || type == 'I')
				return 4;
			else
				if (type == 'l' || type == 'L')
					return 8;
				else
					if (type == 'f' || type == 'F')
						return 4;
					else
						if (type == 'd' || type == 'D')
							return 8;
						else
							if (type == 'c' || type == 'C')
								return 1;
							else
							{
								ret = -1;
								printf("\n不支持这种类型的数据!\n");
								system("pause");
							}
	} while (ret == -1);
	return 0;
}

/*
* 接收用户数据的数据
*/
void InputData(void * data) {
	int ret = 0;
	do {
		ret = 0;
		if (type == 's' || type == 'S') {
			scanf_s("%d", data, data_size);
		}
		else
			if (type == 'i' || type == 'I') {
				scanf_s("%d", data, data_size);
			}
			else
				if (type == 'l' || type == 'L')
				{
					scanf_s("%ld", data, data_size);
				}
				else
					if (type == 'f' || type == 'F')
					{
						scanf_s("%f", data, data_size);
					}
					else
						if (type == 'd' || type == 'D')
						{
							scanf_s("%lf", data, data_size);
						}
						else
							if (type == 'c' || type == 'C')
							{
								scanf_s("%c", data, data_size);
							}
		if (getchar() != '\n') {
			ret = -1;
			for (; getchar() != '\n';);
			printf("您的输入不合法或者超过限制长度,请重新输入：", ret);
		}
		else
		{
			printf("输入数据成功!\n");
			return;
		}
	} while (ret = -1);
}

void menu()
{ // 菜单

	LQueue queue;
	queue.front = queue.rear = NULL;
	queue.length = 0;
	int n = 0;
	int e = 0;
	do {
		system("cls");
		printf("\n");
		printf("======================================================\n");
		printf("\n");
		printf("*****************链式泛型队列的基本操作*******************\n\n");
		printf(" 1. -----初始化一个新队列\n");
		printf(" 2. -----判断当前队列是否为空\n");
		printf(" 3. -----得到队首元素\n");
		printf(" 4. -----清空当前队列\n");
		printf(" 5. -----销毁当前队列\n");
		printf(" 6. -----检测队列的长度\n");
		printf(" 7. -----入队\n");
		printf(" 8. -----出队\n");
		printf(" 9. -----退出\n");
		printf(" 开发者：@黄钰朝\n");
		printf("=======================================================\n\n");
		//输出当前创建的栈
		printf("当前创建的队列如下\n");
		TraverseLQueue(&queue, &LPrint);
		printf("\n");
		printf("请选择您想要执行的操作: ");
		switch (InputNumber())
		{
		case 1:
			if (queue.front != NULL) {
				printf("已经存在一个队列，请先销毁当前队列\n");
				break;
			}
			else
			{
				InitLQueue(&queue);
			}
			break;
		case 2:
			if (queue.front == NULL) {
				printf("当前没有已存的队列，请先初始化一个队列\n");
				break;
			}
			else
			{
				if (IsEmptyLQueue(&queue))
				{
					printf("当前队列为空，请先入队元素\n");
				}
				else
				{
					printf("当前队列非空\n");
				}
			}
			break;
		case 3:
			if (queue.front == NULL) {
				printf("当前没有已存的队列，请先初始化一个队列\n");
				break;
			}
			else
			{
				if (IsEmptyLQueue(&queue))
				{
					printf("当前队列为空，请先入队元素\n");
				}
				else
				{
					GetHeadLQueue(&queue, &e);
					printf("队首元素为");
					LPrint(&e);
				}
			}
			break;
		case 4:
			if (queue.front == NULL) {
				printf("当前没有已存的队列，请先初始化一个队列\n");
				break;
			}
			else
			{
				if (IsEmptyLQueue(&queue))
				{
					printf("当前队列为空，请先入队元素\n");
				}
				else
				{
					ClearLQueue(&queue);
					printf("成功清空当前队列\n");
				}
			}
			break;
		case 5:
			if (queue.front == NULL) {
				printf("当前没有已存的队列，请先初始化一个队列\n");
				break;
			}
			else
			{
				DestoryLQueue(&queue);
				printf("成功销毁当前队列\n");
			}
			break;
		case 6:
			if (queue.front == NULL) {
				printf("当前没有已存的队列，请先初始化一个队列\n");
				break;
			}
			else
			{
				n = LengthLQueue(&queue);
				printf("当前队列的长度为%d\n", n);
			}
			break;
		case 7:
			if (queue.front == NULL) {
				printf("当前没有已存的队列，请先初始化一个队列\n");
				break;
			}
			else
			{
				printf("请输入要入队的元素：");
				void * e = (void*)malloc(data_size);
				InputData(e);
				EnLQueue(&queue, e);
			}
			break;
		case 8:
			if (queue.front == NULL) {
				printf("当前没有已存的队列，请先初始化一个队列\n");
				break;
			}
			else if (IsEmptyLQueue(&queue)) {
				printf("当前队列为空，请先入队元素\n");
			}
			else
			{

				DeLQueue(&queue);
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