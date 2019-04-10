#include"AQueue.h"
int data_size = 0;
char type;

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q) {
	data_size = InputType();
	for (int i = 0; i < MAXQUEUE; i++) {
		Q->data[i] = (void*)malloc(sizeof(data_size));
	}
	Q->front = Q->rear = Q->length = 0;
	printf("�������гɹ�...\n");
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data) {
	if (Q->length == MAXQUEUE) {
		printf("��ǰ�������������������Ԫ��\n");
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q) {
	Q->length = Q->front = Q->rear = 0;

}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q
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
		printf("*****************ѭ�����Ͷ��еĻ�������*******************\n\n");
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
		TraverseAQueue(&queue, &APrint);
		printf("\n");
		printf("��ѡ������Ҫִ�еĲ���: ");
		switch (InputNumber())
		{
		case 1:
			if (queue.data[0] != NULL) {
				printf("�Ѿ�����һ�����У��������ٵ�ǰ����\n");
				break;
			}
			else
			{
				InitAQueue(&queue);
			}
			break;
		case 2:
			if (queue.data[0] == NULL) {
				printf("��ǰû���Ѵ�Ķ��У����ȳ�ʼ��һ������\n");
				break;
			}
			else
			{
				if (IsEmptyAQueue(&queue))
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
			if (queue.data[0] == NULL) {
				printf("��ǰû���Ѵ�Ķ��У����ȳ�ʼ��һ������\n");
				break;
			}
			else
			{
				if (IsEmptyAQueue(&queue))
				{
					printf("��ǰ����Ϊ�գ��������Ԫ��\n");
				}
				else
				{
					GetHeadAQueue(&queue, &e);
					printf("����Ԫ��Ϊ");
					APrint(&e);
				}
			}
			break;
		case 4:
			if (queue.data[0] == NULL) {
				printf("��ǰû���Ѵ�Ķ��У����ȳ�ʼ��һ������\n");
				break;
			}
			else
			{
				if (IsEmptyAQueue(&queue))
				{
					printf("��ǰ����Ϊ�գ��������Ԫ��\n");
				}
				else
				{
					ClearAQueue(&queue);
					printf("�ɹ���յ�ǰ����\n");
				}
			}
			break;
		case 5:
			if (queue.data[0] == NULL) {
				printf("��ǰû���Ѵ�Ķ��У����ȳ�ʼ��һ������\n");
				break;
			}
			else
			{
				DestoryAQueue(&queue);
				printf("�ɹ����ٵ�ǰ����\n");
			}
			break;
		case 6:
			if (queue.data[0] == NULL) {
				printf("��ǰû���Ѵ�Ķ��У����ȳ�ʼ��һ������\n");
				break;
			}
			else
			{
				n = LengthAQueue(&queue);
				printf("��ǰ���еĳ���Ϊ%d\n", n);
			}
			break;
		case 7:
			if (queue.data[0] == NULL) {
				printf("��ǰû���Ѵ�Ķ��У����ȳ�ʼ��һ������\n");
				break;
			}
			else
			{
				printf("������Ҫ��ӵ�Ԫ�أ�");
				void * e = NULL;
				e = (void*)malloc(data_size);
				InputData(e);
				EnAQueue(&queue, e);
			}
			break;
		case 8:
			if (queue.data[0] == NULL) {
				printf("��ǰû���Ѵ�Ķ��У����ȳ�ʼ��һ������\n");
				break;
			}
			else if (IsEmptyAQueue(&queue)) {
				printf("��ǰ����Ϊ�գ��������Ԫ��\n");
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
			//���������ַ��޷�ƥ�书�ܣ����������
			printf("�������ѡ���Ѿ�������Χ��\n");
		}
		system("pause");
	} while (1);
}