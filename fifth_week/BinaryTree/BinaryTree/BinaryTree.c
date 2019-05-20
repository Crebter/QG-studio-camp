#include"BinaryTree.h"

bool isInited = false;

//�������������ն�����T
Status InitBiTree(BiTree T) {
	if (T == NULL) {
		printf("û�пռ��Խ������Ĵ���");
		return ERROR;
	}
	if (T->data != NULL) {
		printf("�����Ѿ�����ʼ�����������ٸ����ٽ��г�ʼ��");
		return ERROR;
	}
	char n = InputOperator();
	CreateBiTree(T, &n);
	isInited = true;
	printf("\n�����������ɹ�");
	return SUCEESS;
}
//��ʼ������������T����
//����������ݻٶ�����T
Status DestroyBiTree(BiTree T) {
	if (T == NULL) {
		printf("û��һ���Ѵ��ڵ���");
		return ERROR;
	}
	if (T->data==NULL) {
		printf("������û�б���ʼ�������ȶԸ������г�ʼ��");
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


//��ʼ������ definition�����������Ķ���
//�����������definition���������T
Status CreateBiTree(BiTree T, char* definition) {
	if (T == NULL) {
		printf("û��һ���Ѵ��ڵ���");
		return ERROR;
	}
	T->data = *definition;
	//������������������Ҷ��
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


//���²��ֺ�������δָ����������
//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��
Status PreOrderTraverse(BiTNode T, Status(*visit)(TElemType e)) {
	if (T.data == NULL) {
		printf("������û�б���ʼ�������ȶԸ������г�ʼ��");
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
//�������
Status InOrderTraverse(BiTNode T, Status(*visit)(TElemType e)) {
	if (T.data == NULL) {
		printf("������û�б���ʼ�������ȶԸ������г�ʼ��");
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
//�������
Status PostOrderTraverse(BiTNode T, Status(*visit)(TElemType e)) {
	if (T.data == NULL) {
		printf("������û�б���ʼ�������ȶԸ������г�ʼ��");
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

//�������
Status LevelOrderTraverse(BiTNode T, Status(*visit)(TElemType e)) {
	if (T.data == NULL) {
		printf("������û�б���ʼ�������ȶԸ������г�ʼ��");
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
}//������Ķ�������ֵ


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
			printf("���󣺷�ĸ������Ϊ��!\n");
			return 0;
		}
		else
			result = n1 / n2;
		break;
	}
	return result;
}
/*
��ʾ�����ڽ��ṹ�������ø�Tagֵ��־������������������������
�ɸ�����Ҫ�������Ӳ���.
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
	int num = 0; //�����������
	int status = 0; //��־״̬
	do
	{
		status = TRUE;
		n = scanf_s("%d", &num, 4);
		if (getchar() != '\n') {
			for (; getchar() != '\n';);
			printf("���벻�Ϸ�,���������룺");
			status = FALSE;
		}
	} while (status == FALSE);
	printf("����ɹ��������������Ϊ��%d\n", num);
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
		/*printf("\n������Ԫ��");
		if (getchar() != '\n') {
			for (; getchar() != '\n';);
			printf("������������,���������룺");
			status = FALSE;
		}*/
		if ((n < 47 || n>58) && n != '+'&&n != '-'&&n != '*'&&n != '/') {

			status = FALSE;
		}
	} while (status == FALSE);
	printf("%c", n);
	return n;
}

