#include"LinkStack.h"

StackNode * bottom = NULL;
//��ջ(���������)
Status initLStack(LinkStack *s) {
	s->count = 0;
	s->top = (StackNode*)malloc(sizeof(StackNode));
	s->top->data = 1234567890;
	s->top->next = NULL;
	bottom = s->top;
	printf("�ɹ�����һ��ջ\n");
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
	printf("�ɹ���Ԫ��%dѹ��ջ\n", data);
	return SUCCESS;
}
Status popLStack(LinkStack *s, ElemType *data) {
	StackNode * p = bottom;
	if (s->count == 0) {
		printf("��ǰջ�ѿ�\n");
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
		printf("�ɹ���Ԫ��%d�Ƴ�ջ\n", *data);
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
	int num = 0; //���ת���������
	int status = 0; //��־״̬
	char str[100]; //�����ַ���
	do
	{
		scanf("%s", str);
		status = SUCCESS;
		for (int i = 0; str[i] != '\0'; i++)
		{
			//��������Ƿ���ڷǷ��ַ�
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
			printf("\n���������к��зǷ��ַ������������룺");
		}
		else
		{
			int i = 0;
			//���ַ���ת������

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
			//�������������Ƿ�Խ��
			if (i >= 10)
			{
				printf("\n������������Ѿ�Խ�磬����������: ");
				status = ERROR;
			}
		}
	} while (status == ERROR);
	printf("\n����ɹ��������������Ϊ��%d\n", num);
	return num;
}

Status printStack(LinkStack * s)
{
	StackNode * p = NULL;
	if (s->top == NULL) {
		printf("��ǰû���Ѿ�������ջ\n");
		return ERROR;
	}
	else if (isEmptyLStack(s)) {
		printf("��ǰջ��Ԫ��Ϊ �� ��\n");
		return ERROR;
	}
	printf("��ǰջ��Ԫ��Ϊ ��");
	for (p = bottom->next; p; p = p->next) {
		if (p != bottom->next) {
			printf("->");//��������������ֵ֮������ͷ
		}
		printf("%d", p->data);
	}
	printf("\n");
	return SUCCESS;
}


void menu()
{ // �˵�

	//ջ��ָ��
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
		printf("*****************��ջ�Ļ�������*******************\n\n");
		printf(" 1. -----��ʼ��һ����ջ\n");
		printf(" 2. -----�жϵ�ǰջ�Ƿ�Ϊ��\n");
		printf(" 3. -----�õ�ջ��Ԫ��\n");
		printf(" 4. -----��յ�ǰջ\n");
		printf(" 5. -----���ٵ�ǰջ\n");
		printf(" 6. -----���ջ�ĳ���\n");
		printf(" 7. -----��ջ\n");
		printf(" 8. -----��ջ\n");
		printf(" 9. -----�˳�\n");
		printf(" �����ߣ�@���ڳ�\n");
		printf("=======================================================\n\n");
		//�����ǰ������ջ
		printStack(&head);
		printf("��ѡ������Ҫִ�еĲ���: ");
		switch (InputNumber())
		{
		case 1:
			if (head.top != NULL) {
				printf("�Ѿ�����һ��ջ���������ٵ�ǰջ\n");
				break;
			}
			else
			{
				initLStack(&head);

			}
			break;
		case 2:
			if (head.top == NULL) {
				printf("��ǰû���Ѵ��ջ�����ȳ�ʼ��һ��ջ\n");
				break;
			}
			else
			{
				if (isEmptyLStack(&head)) {
					printf("��ǰջΪ��\n");
				}
				else
				{
					printf("��ǰջ�ǿ�\n");
				}
			}
			break;
		case 3:
			if (head.top == NULL) {
				printf("��ǰû���Ѵ��ջ�����ȳ�ʼ��һ��ջ\n");
				break;
			}
			else
			{
				if (isEmptyLStack(&head))
				{
					printf("��ǰջΪ�գ�����ѹ��Ԫ��\n");
				}
				else
				{
					getTopLStack(&head, &e);
					printf("ջ��Ԫ��Ϊ%d\n", e);
				}
			}
			break;
		case 4:
			if (head.top == NULL) {
				printf("��ǰû���Ѵ��ջ�����ȳ�ʼ��һ��ջ\n");
				break;
			}
			else
			{
				if (isEmptyLStack(&head))
				{
					printf("��ǰջΪ�գ�����Ҫ���\n");
				}
				else
				{
					clearLStack(&head);
					printf("�ɹ���յ�ǰջ\n");
				}
			}
			break;
		case 5:
			if (head.top == NULL) {
				printf("��ǰû���Ѵ��ջ�����ȳ�ʼ��һ��ջ\n");
				break;
			}
			else
			{
				destroyLStack(&head);
				printf("�ɹ����ٵ�ǰջ\n");
			}
			break;
		case 6:
			if (head.top == NULL) {
				printf("��ǰû���Ѵ��ջ�����ȳ�ʼ��һ��ջ\n");
				break;
			}
			else
			{
				LStackLength(&head, &n);
				printf("��ǰջ�ĳ���Ϊ%d\n", n);
			}
			break;
		case 7:
			if (head.top == NULL) {
				printf("��ǰû���Ѵ��ջ�����ȳ�ʼ��һ��ջ\n");
				break;
			}
			else
			{
				printf("������Ҫѹ��ջ��Ԫ�أ�");
				pushLStack(&head, InputNumber());
			}
			break;
		case 8:
			if (head.top == NULL) {
				printf("��ǰû���Ѵ��ջ�����ȳ�ʼ��һ��ջ\n");
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
			//���������ַ��޷�ƥ�书�ܣ����������
			printf("�������ѡ���Ѿ�������Χ��\n");
		}
		system("pause");
	} while (1);
}
