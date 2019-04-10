#include"LQueue.h"
int data_size = 0;
char type;


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	if (Q->front == NULL) {
		printf("��������ʧ��...");
		return;
	}
	data_size = InputType();
	Q->front->data = (void*)malloc(data_size);
	Q->length = 0;
	Q->front->data = 1234567890;
	Q->front->next = NULL;
	printf("�������гɹ�...\n");
	return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data) {
	Node*p = (Node*)malloc(sizeof(Node));
	p->data = (void*)malloc(data_size);
	if (p == NULL) {
		printf("�޷������Ԫ��...");
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
	printf("��ӳɹ�\n");
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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

	printf("���ӳɹ�");
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q

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
	int num = 0; //���ת���������
	int status = 0; //��־״̬
	char str[100]; //�����ַ���
	do
	{
		scanf("%s", str);
		status = TRUE;
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
					status = FALSE;
				}
			}
		}
		if (status == FALSE) {
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
				status = FALSE;
			}
		}
	} while (status == FALSE);
	printf("\n����ɹ��������������Ϊ��%d\n", num);
	return num;
}

/*
* �����û�������������ͣ����ظ��������ݵĴ�С
*/
int InputType()
{
	int ret = 0;
	do
	{
		ret = 0;
		printf("��ѡ����е��������ͣ�[s]hort | [i]nt | [l]ong | [f]loat | [d]ouble | [c]har \n");
		printf("������һ���ַ���");
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
								printf("\n��֧���������͵�����!\n");
								system("pause");
							}
	} while (ret == -1);
	return 0;
}

/*
* �����û����ݵ�����
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
			printf("�������벻�Ϸ����߳������Ƴ���,���������룺", ret);
		}
		else
		{
			printf("�������ݳɹ�!\n");
			return;
		}
	} while (ret = -1);
}

void menu()
{ // �˵�

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
		printf("*****************��ʽ���Ͷ��еĻ�������*******************\n\n");
		printf(" 1. -----��ʼ��һ���¶���\n");
		printf(" 2. -----�жϵ�ǰ�����Ƿ�Ϊ��\n");
		printf(" 3. -----�õ�����Ԫ��\n");
		printf(" 4. -----��յ�ǰ����\n");
		printf(" 5. -----���ٵ�ǰ����\n");
		printf(" 6. -----�����еĳ���\n");
		printf(" 7. -----���\n");
		printf(" 8. -----����\n");
		printf(" 9. -----�˳�\n");
		printf(" �����ߣ�@���ڳ�\n");
		printf("=======================================================\n\n");
		//�����ǰ������ջ
		printf("��ǰ�����Ķ�������\n");
		TraverseLQueue(&queue, &LPrint);
		printf("\n");
		printf("��ѡ������Ҫִ�еĲ���: ");
		switch (InputNumber())
		{
		case 1:
			if (queue.front != NULL) {
				printf("�Ѿ�����һ�����У��������ٵ�ǰ����\n");
				break;
			}
			else
			{
				InitLQueue(&queue);
			}
			break;
		case 2:
			if (queue.front == NULL) {
				printf("��ǰû���Ѵ�Ķ��У����ȳ�ʼ��һ������\n");
				break;
			}
			else
			{
				if (IsEmptyLQueue(&queue))
				{
					printf("��ǰ����Ϊ�գ��������Ԫ��\n");
				}
				else
				{
					printf("��ǰ���зǿ�\n");
				}
			}
			break;
		case 3:
			if (queue.front == NULL) {
				printf("��ǰû���Ѵ�Ķ��У����ȳ�ʼ��һ������\n");
				break;
			}
			else
			{
				if (IsEmptyLQueue(&queue))
				{
					printf("��ǰ����Ϊ�գ��������Ԫ��\n");
				}
				else
				{
					GetHeadLQueue(&queue, &e);
					printf("����Ԫ��Ϊ");
					LPrint(&e);
				}
			}
			break;
		case 4:
			if (queue.front == NULL) {
				printf("��ǰû���Ѵ�Ķ��У����ȳ�ʼ��һ������\n");
				break;
			}
			else
			{
				if (IsEmptyLQueue(&queue))
				{
					printf("��ǰ����Ϊ�գ��������Ԫ��\n");
				}
				else
				{
					ClearLQueue(&queue);
					printf("�ɹ���յ�ǰ����\n");
				}
			}
			break;
		case 5:
			if (queue.front == NULL) {
				printf("��ǰû���Ѵ�Ķ��У����ȳ�ʼ��һ������\n");
				break;
			}
			else
			{
				DestoryLQueue(&queue);
				printf("�ɹ����ٵ�ǰ����\n");
			}
			break;
		case 6:
			if (queue.front == NULL) {
				printf("��ǰû���Ѵ�Ķ��У����ȳ�ʼ��һ������\n");
				break;
			}
			else
			{
				n = LengthLQueue(&queue);
				printf("��ǰ���еĳ���Ϊ%d\n", n);
			}
			break;
		case 7:
			if (queue.front == NULL) {
				printf("��ǰû���Ѵ�Ķ��У����ȳ�ʼ��һ������\n");
				break;
			}
			else
			{
				printf("������Ҫ��ӵ�Ԫ�أ�");
				void * e = (void*)malloc(data_size);
				InputData(e);
				EnLQueue(&queue, e);
			}
			break;
		case 8:
			if (queue.front == NULL) {
				printf("��ǰû���Ѵ�Ķ��У����ȳ�ʼ��һ������\n");
				break;
			}
			else if (IsEmptyLQueue(&queue)) {
				printf("��ǰ����Ϊ�գ��������Ԫ��\n");
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
			//���������ַ��޷�ƥ�书�ܣ����������
			printf("�������ѡ���Ѿ�������Χ��\n");
		}
		system("pause");
	} while (1);
}