#include"AQueue.h"
int data_size = 0;
char type;

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q) {
	data_size = InputType();
	for (int i = 0; i < MAXQUEUE; i++) {
		Q->data[i] = (void*)malloc(sizeof(data_size));
	}
	Q->front = Q->rear = Q->length = 0;
	printf("创建队列成功...\n");
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q) {
	if (Q == NULL) {
		return;
	}
	for (int i = 0; i < MAXQUEUE; i++) {
		free(Q->data[i]);
		Q->data[0] = NULL;
	}
	Q->front = Q->rear = Q->length = 0;
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q) {
	if (Q->front == Q->rear + 1 || Q->front == 0 && Q->rear == MAXQUEUE) {
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q) {
	if (Q->length == 0) {
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e) {
	if (Q == NULL) {
		return FALSE;
	}
	memcpy(e, Q->data[Q->front], data_size);
	return TRUE;
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q) {
	if (Q == NULL) {
		return 0;
	}
	return Q->length;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data) {
	if (Q->length == MAXQUEUE) {
		printf("当前队列已满，不可添加新元素\n");
		system("pause");
		return FALSE;
	}
	if (Q->rear == MAXQUEUE - 1) {
		memcpy(Q->data[Q->rear = 0], data, data_size);
	}
	else
	{
		if (Q->length == 0) {
			memcpy(Q->data[Q->rear], data, data_size);
		}
		else
		{
			memcpy(Q->data[Q->rear + 1], data, data_size);
			Q->rear++;
		}
	}
	Q->length++;
	return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q) {

	if (Q->front == MAXQUEUE - 1) {
		Q->front = 0;
	}
	else
	{
		Q->front++;
	}
	Q->length--;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q) {
	Q->length = Q->front = Q->rear = 0;

}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void(*foo)(void *q)) {
	if (Q == NULL || IsEmptyAQueue(Q)) {
		return FALSE;
	}
	int cnt = 0;
	for (int i = Q->front;; i++) {
		if (i == MAXQUEUE) {
			i = 0;
		}
		(*foo)(Q->data[i]);
		cnt++;
		if (cnt == Q->length) {
			return TRUE;
		}
		printf("->");
	}
}



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q) {
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

	AQueue queue;
	queue.front = queue.rear = queue.length = 0;
	queue.data[0] = NULL;
	int n = 0;
	int e = 0;
	do {
		system("cls");
		printf("\n");
		printf("======================================================\n");
		printf("\n");
		printf("*****************循环泛型队列的基本操作*******************\n\n");
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
		TraverseAQueue(&queue, &APrint);
		printf("\n");
		printf("请选择您想要执行的操作: ");
		switch (InputNumber())
		{
		case 1:
			if (queue.data[0] != NULL) {
				printf("已经存在一个队列，请先销毁当前队列\n");
				break;
			}
			else
			{
				InitAQueue(&queue);
			}
			break;
		case 2:
			if (queue.data[0] == NULL) {
				printf("当前没有已存的队列，请先初始化一个队列\n");
				break;
			}
			else
			{
				if (IsEmptyAQueue(&queue))
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
			if (queue.data[0] == NULL) {
				printf("当前没有已存的队列，请先初始化一个队列\n");
				break;
			}
			else
			{
				if (IsEmptyAQueue(&queue))
				{
					printf("当前队列为空，请先入队元素\n");
				}
				else
				{
					GetHeadAQueue(&queue, &e);
					printf("队首元素为");
					APrint(&e);
				}
			}
			break;
		case 4:
			if (queue.data[0] == NULL) {
				printf("当前没有已存的队列，请先初始化一个队列\n");
				break;
			}
			else
			{
				if (IsEmptyAQueue(&queue))
				{
					printf("当前队列为空，请先入队元素\n");
				}
				else
				{
					ClearAQueue(&queue);
					printf("成功清空当前队列\n");
				}
			}
			break;
		case 5:
			if (queue.data[0] == NULL) {
				printf("当前没有已存的队列，请先初始化一个队列\n");
				break;
			}
			else
			{
				DestoryAQueue(&queue);
				printf("成功销毁当前队列\n");
			}
			break;
		case 6:
			if (queue.data[0] == NULL) {
				printf("当前没有已存的队列，请先初始化一个队列\n");
				break;
			}
			else
			{
				n = LengthAQueue(&queue);
				printf("当前队列的长度为%d\n", n);
			}
			break;
		case 7:
			if (queue.data[0] == NULL) {
				printf("当前没有已存的队列，请先初始化一个队列\n");
				break;
			}
			else
			{
				printf("请输入要入队的元素：");
				void * e = NULL;
				e = (void*)malloc(data_size);
				InputData(e);
				EnAQueue(&queue, e);
			}
			break;
		case 8:
			if (queue.data[0] == NULL) {
				printf("当前没有已存的队列，请先初始化一个队列\n");
				break;
			}
			else if (IsEmptyAQueue(&queue)) {
				printf("当前队列为空，请先入队元素\n");
			}
			else
			{

				DeAQueue(&queue);
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