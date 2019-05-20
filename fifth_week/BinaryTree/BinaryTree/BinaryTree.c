#include"BinaryTree.h"

bool isInited = false;

//操作结果：构造空二叉树T
Status InitBiTree(BiTree T) {
	if (T == NULL) {
		printf("没有空间以进行树的创建");
		return ERROR;
	}
	if (T->data != NULL) {
		printf("该树已经被初始化，请先销毁该树再进行初始化");
		return ERROR;
	}
	char n = InputOperator();
	CreateBiTree(T, &n);
	isInited = true;
	printf("\n创建二叉树成功");
	return SUCEESS;
}
//初始条件：二叉树T存在
//操作结果：摧毁二叉树T
Status DestroyBiTree(BiTree T) {
	if (T == NULL) {
		printf("没有一个已存在的树");
		return ERROR;
	}
	if (T->data==NULL) {
		printf("该树还没有被初始化，请先对该树进行初始化");
		return ERROR;
	}
	if (T->lchild)
	{
		DestroyBiTree(T->lchild);
		T->lchild = NULL;
	}
	if (T->rchild)
	{
		DestroyBiTree(T->rchild);
		T->rchild = NULL;
	}
	if (T != NULL)
	{
		free(T);
		T = NULL;
	}
	isInited = false;
	return SUCEESS;
}


//初始条件： definition给出二叉树的定义
//操作结果：按definition构造二叉树T
Status CreateBiTree(BiTree T, char* definition) {
	if (T == NULL) {
		printf("没有一个已存在的树");
		return ERROR;
	}
	T->data = *definition;
	//如果不是运算符则生成叶子
	if (T->data >= 48 && T->data <= 57) {
		T->lchild = NULL;
		T->rchild = NULL;
	}
	else
	{
		T->lchild = (BiTNode*)malloc(sizeof(BiTNode));
		T->rchild = (BiTNode*)malloc(sizeof(BiTNode));
		char n;
		n = InputOperator();
		CreateBiTree(T->lchild, &n);
		n = InputOperator();
		CreateBiTree(T->rchild, &n);
	}
}


//以下部分函数定义未指定参数类型
//初始条件：二叉树T存在，visit为对结点的操作的应用函数
//操作结果：先序遍历T，对每个结点调用visit函数一次且仅一次，一旦visit失败，则操作失败
Status PreOrderTraverse(BiTNode T, Status(*visit)(TElemType e)) {
	if (T.data == NULL) {
		printf("该树还没有被初始化，请先对该树进行初始化");
		return ERROR;
	}
	visit(T.data);
	if (T.lchild != NULL) {
		PreOrderTraverse(*(T.lchild), visit);
	}
	if (T.rchild != NULL) {
		PreOrderTraverse(*(T.rchild), visit);
	}
}
//中序遍历
Status InOrderTraverse(BiTNode T, Status(*visit)(TElemType e)) {
	if (T.data == NULL) {
		printf("该树还没有被初始化，请先对该树进行初始化");
		return ERROR;
	}
	if (T.lchild != NULL) {
		InOrderTraverse(*(T.lchild), visit);
	}
	visit(T.data);
	if (T.rchild != NULL) {
		InOrderTraverse(*(T.rchild), visit);
	}
}
//后序遍历
Status PostOrderTraverse(BiTNode T, Status(*visit)(TElemType e)) {
	if (T.data == NULL) {
		printf("该树还没有被初始化，请先对该树进行初始化");
		return ERROR;
	}
	if (T.lchild != NULL) {
		PostOrderTraverse(*(T.lchild), visit);
	}
	if (T.rchild != NULL) {
		PostOrderTraverse(*(T.rchild), visit);
	}
	visit(T.data);
}

//层序遍历
Status LevelOrderTraverse(BiTNode T, Status(*visit)(TElemType e)) {
	if (T.data == NULL) {
		printf("该树还没有被初始化，请先对该树进行初始化");
		return ERROR;
	}
	LQueue Q;
	BiTNode t;
	Q.front = Q.rear = NULL;
	Q.length = 0;
	InitLQueue(&Q);
	EnLQueue(&Q, &T);
	while (!IsEmptyLQueue(&Q))
	{
		GetHeadLQueue(&Q,&t);
		DeLQueue(&Q);
		visit(t.data);
		if (t.lchild != NULL)
			EnLQueue(&Q, t.lchild);
		if (t.rchild != NULL)
			EnLQueue(&Q, t.rchild);
	}
}	
int Value(BiTNode T) {

	if (T.data >= 48 && T.data <= 57) {
		return T.data-48;
	}
	return Operate(Value(*T.lchild), Value(*T.rchild), T.data);
}//构造出的二叉树求值


void Print(char data) {

	printf("%c", data);
}

int Operate(int n1, int n2, char operate)   
{
	int result = 0;
	switch (operate)
	{
	case '+':
		result = n1 + n2;
		break;
	case '-':
		result = n1 - n2;
		break;
	case '*':
		result = n1 * n2;
		break;
	case '/':
		if (n2 == 0)
		{
			printf("错误：分母不可以为零!\n");
			return 0;
		}
		else
			result = n1 / n2;
		break;
	}
	return result;
}
/*
提示：可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
可根据需要自行增加操作.
*/


/**
 *  @name        : InputNumber
 *	@description : to input a checked number
 *	@param		 : none
 *	@return		 : int
 *  @notice      : None
 */
int InputNumber()
{
	typedef enum
	{
		FALSE = 0, TRUE = 1
	} Status;

	int n = 0;
	int num = 0; //存放输入数字
	int status = 0; //标志状态
	do
	{
		status = TRUE;
		n = scanf_s("%d", &num, 4);
		if (getchar() != '\n') {
			for (; getchar() != '\n';);
			printf("输入不合法,请重新输入：");
			status = FALSE;
		}
	} while (status == FALSE);
	printf("输入成功！您输入的数字为：%d\n", num);
	return num;
}


/**
 *  @name        : InputOperator
 *	@description : to input a checked operator
 *	@param		 : none
 *	@return		 : char
 *  @notice      : None
 */
char InputOperator()
{
	typedef enum
	{
		FALSE = 0, TRUE = 1
	} Status;

	char n;
	Status status = TRUE;
	do
	{
		status = TRUE;
		n = getch();
		/*printf("\n请输入元素");
		if (getchar() != '\n') {
			for (; getchar() != '\n';);
			printf("您的输入有误,请重新输入：");
			status = FALSE;
		}*/
		if ((n < 47 || n>58) && n != '+'&&n != '-'&&n != '*'&&n != '/') {

			status = FALSE;
		}
	} while (status == FALSE);
	printf("%c", n);
	return n;
}

