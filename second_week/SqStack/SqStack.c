#include "SqStack.h"

//˳��ջ(���������)
//��ʼ��ջ
Status initStack(SqStack *s, int sizes) {

	if (sizes <= 0) {
		printf("ջ�Ĵ�С�������0\n");
		return ERROR;
	}
	else {
		s->size = sizes;
		s->top = 0;
		s->elem = (ElemType*)malloc(sizeof(ElemType)*sizes);
		printf("�ɹ�����һ����СΪ%d��ջ\n", sizes);
		return SUCCESS;
	}
}

//�ж�ջ�Ƿ�Ϊ��
bool isEmptyStack(SqStack *s) {
	if (s->top == 0) {
		return true;
	}
	else
	{
		return false;
	}
}

//�õ�ջ��Ԫ��
Status getTopStack(SqStack *s, ElemType *e) {
	*e = *(s->elem + s->top - 1);
	return SUCCESS;
}
//���ջ
Status clearStack(SqStack *s) {
	s->top = 0;
	return SUCCESS;
}
//����ջ
Status destroyStack(SqStack *s) {
	free(s->elem);
	s->elem = NULL;
	s->size = 0;
	return SUCCESS;
}
//���ջ����
Status stackLength(SqStack *s, int *length) {
	*length = s->top;
	return SUCCESS;
}
//��ջ
Status pushStack(SqStack *s, ElemType data) {
	if (s->top < s->size) {
		*(s->elem + s->top++) = data;
		printf("�ɹ���Ԫ��%dѹ��ջ\n", data);
		return SUCCESS;
	}
	else
	{
		printf("��ǰջ����������ѹ����Ԫ��\n");
		return ERROR;
	}
}
//��ջ
Status popStack(SqStack *s, ElemType *data) {
	if (s->top != 0) {
		*data = *(s->elem + s->top - 1);
		s->top--;
		printf("�ɹ���Ԫ��%d�Ƴ�ջ\n", *data);
		return SUCCESS;
	}
	else
	{
		printf("��ǰջ�ѿ�\n");
		return ERROR;
	}
}

//��ӡ��ǰջ��Ԫ��
Status printStack(SqStack * s) {
	if (s->size == 0) {
		printf("��ǰû���Ѿ�������ջ\n");
		return ERROR;
	}
	else if (isEmptyStack(s)) {
		printf("��ǰջ��Ԫ��Ϊ �� ��\n");
		return ERROR;
	}
	printf("��ǰջ��Ԫ��Ϊ ��");
	for (int i = 0; i < s->top; i++) {
		if (i != 0) {
			//��������������ֵ֮������ͷ
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


void menu()
{ // �˵�

	//ջ��ָ��
	SqStack head;
	head.elem = NULL;
	head.top = head.size = 0;
	//���ڽ����û��������ֵ
	int n = 0;
	ElemType e;
	do
	{
		system("cls");
		printf("\n");
		printf("======================================================\n");
		printf("\n");
		printf("*****************˳��ջ�Ļ�������*******************\n\n");
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
			if (head.size != 0) {
				printf("�Ѿ�����һ��ջ���������ٵ�ǰջ\n");
				break;
			}
			else
			{
				do {
					printf("������ջ�Ĵ�С��");
				} while (initStack(&head, InputNumber()) == ERROR);
			}
			break;
		case 2:
			if (head.size == 0) {
				printf("��ǰû���Ѵ��ջ�����ȳ�ʼ��һ��ջ\n");
				break;
			}
			else
			{
				if (isEmptyStack(&head)) {
					printf("��ǰջΪ��\n");
				}
				else
				{
					printf("��ǰջ�ǿ�\n");
				}
			}
			break;
		case 3:
			if (head.size == 0) {
				printf("��ǰû���Ѵ��ջ�����ȳ�ʼ��һ��ջ\n");
				break;
			}
			else
			{
				if (isEmptyStack(&head))
				{
					printf("��ǰջΪ�գ�����ѹ��Ԫ��\n");
				}
				else
				{
					getTopStack(&head, &e);
					printf("ջ��Ԫ��Ϊ%d\n", e);
				}
			}
			break;
		case 4:
			if (head.size == 0) {
				printf("��ǰû���Ѵ��ջ�����ȳ�ʼ��һ��ջ\n");
				break;
			}
			else
			{
				if (isEmptyStack(&head))
				{
					printf("��ǰջΪ�գ�����Ҫ���\n");
				}
				else
				{
					clearStack(&head);
					printf("�ɹ���յ�ǰջ\n");
				}
			}
			break;
		case 5:
			if (head.size == 0) {
				printf("��ǰû���Ѵ��ջ�����ȳ�ʼ��һ��ջ\n");
				break;
			}
			else
			{
				destroyStack(&head);
				printf("�ɹ����ٵ�ǰջ\n");
			}
			break;
		case 6:
			if (head.size == 0) {
				printf("��ǰû���Ѵ��ջ�����ȳ�ʼ��һ��ջ\n");
				break;
			}
			else
			{
				stackLength(&head, &n);
				printf("��ǰջ�ĳ���Ϊ%d\n", n);
			}
			break;
		case 7:
			if (head.size == 0) {
				printf("��ǰû���Ѵ��ջ�����ȳ�ʼ��һ��ջ\n");
				break;
			}
			else
			{
				printf("������Ҫѹ��ջ��Ԫ�أ�");
				pushStack(&head, InputNumber());
			}
			break;
		case 8:
			if (head.size == 0) {
				printf("��ǰû���Ѵ��ջ�����ȳ�ʼ��һ��ջ\n");
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
			//���������ַ��޷�ƥ�书�ܣ����������
			printf("�������ѡ���Ѿ�������Χ��\n");
		}
		system("pause");
	} while (1);
}


