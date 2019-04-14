#define _CRT_SECURE_NO_WARNINGS

#include"qgsort.h"



/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a, int n) {
	for (int i = 1, find = i - 1, temp = 0; i < n; i++, find = i - 1)
	{
		temp = a[i];
		while (find >= 0 && temp < a[find])
		{
			a[find + 1] = a[find--];
		}
		a[++find] = temp;
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a, int begin, int mid, int end, int *temp) {
	temp = (int *)malloc((end - begin + 1) * sizeof(int));
	//����ռ䣬ʹ���СΪ����
	int left_begin = begin;
	int left_end = mid;
	int right_begin = mid + 1;
	int right_end = end;

	int i, k;
	for (k = 0; left_begin <= left_end && right_begin <= right_end; k++) {  // �Ƚ�����ָ����ָ���Ԫ��
		if (a[left_begin] <= a[right_begin]) {
			temp[k] = a[left_begin++];
		}
		else {
			temp[k] = a[right_begin++];
		}
	}

	if (left_begin <= left_end) {  //����һ��������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β
	//memcpy(tmp+k, arr+left_low, (left_high-left_low+l)*sizeof(int));
		for (i = left_begin; i <= left_end; i++)
			temp[k++] = a[i];
	}

	if (right_begin <= right_end) {
		//���ڶ���������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β
		//memcpy(tmp+k, arr+right_low, (right_high-right_low+1)*sizeof(int));
		for (i = right_begin; i <= right_end; i++)
			temp[k++] = a[i];
	}

	for (i = 0; i < end - begin + 1; i++)
		a[begin + i] = temp[i];
	free(temp);
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a, int begin, int end, int *temp) {
	int mid = 0;
	if (begin < end) {
		mid = (begin + end) / 2; /* ע���ֹ��� */
		/*mid = first/2 + last/2;*/
		//mid = (first & last) + ((first ^ last) >> 1);
		MergeSort(a, begin, mid, temp);
		MergeSort(a, mid + 1, end, temp);
		MergeArray(a, begin, mid, end, temp);
	}
	return;
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end) {
	if (begin < end)
	{
		//�ѻ�׼���ź�
		int base = Partition(a, begin, end);
		//�ݹ�
		QuickSort_Recursion(a, end, base - 1);
		QuickSort_Recursion(a, base + 1, end);
	}
	return;
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a, int size) {
	int base;
	int left = 0;
	int right = size - 1;
	int n;
	LinkStack stack;
	//��ʼջ
	initLStack(&stack);
	pushLStack(&stack, 0);
	pushLStack(&stack, right);
	while (!isEmptyLStack(&stack))
	{
		getTopLStack(&stack, &right);
		popLStack(&stack, &n);
		getTopLStack(&stack, &left);
		popLStack(&stack, &n);
		base = Partition(a, left, right);
		//�������ջ
		if (base - 1 > left)
		{
			pushLStack(&stack, left);
			pushLStack(&stack, base - 1);
		}
		if (base + 1 < right)
		{
			pushLStack(&stack, base + 1);
			pushLStack(&stack, right);
		}
	}

}

/*���ڿ��������н���Ԫ��*/
void Swap(int a[], int begin, int end)
{
	int temp = a[begin];
	a[begin] = a[end];
	a[end] = temp;
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end) {
	//ѡȡ��׼��
	int base = a[begin];
	while (begin < end)
	{
		//�Ӻ�߿�ʼ���ҵ��Ȼ�׼��С��
		while (begin < end && a[end] >= base)
		{
			end--;
		}
		Swap(a, begin, end);
		//��ǰ�濪ʼ���ҵ��Ȼ�׼�����
		while (begin < end && a[begin] <= base)
		{
			begin++;
		}
		Swap(a, begin, end);
	}
	return begin;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size, int max) {
	int *temp, *result;
	//��������
	temp = (int *)malloc(sizeof(int)*max);
	//��ʱ���������
	result = (int *)malloc(sizeof(int)*size);
	//�Ѽ��������ʼ��
	memset(temp, 0, sizeof(int)*max);
	//ͳ�Ƹ���Ԫ�س��ִ���
	for (int i = 0; i < size; i++) {
		temp[a[i]] += 1;
	}
	//ͳ��С�ڵ�������Ԫ�ظ���
	for (int i = 1; i < max; i++) {
		temp[i] = temp[i - 1] + temp[i];
	}
	//�Ӻ��濪ʼ����ÿ��Ԫ�����Ӧλ��
	for (int i = size - 1; i >= 0; i--)
	{
		result[temp[a[i]] - 1] = a[i];
		temp[a[i]]--;
	}
	//��������Ľ���ԭ����������
	for (int i = 0; i < size; i++) {
		a[i] = result[i];
	}
	free(temp);
	free(result);
}


//ȡ�����������λ���ϵ�����
int getBit(int num, int pos) {
	int temp = 1;
	for (int i = 0; i < pos - 1; i++) {
		temp *= 10;
	}
	return (num / temp) % 10;
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a, int size) {
	//��������
	int *radixArrays[BASE_SIZE];

	//����ռ�
	for (int i = 0; i < 10; i++)
	{
		//��ÿ��0-BASE_SIZEÿ��λ�÷���һ������
		radixArrays[i] = (int *)malloc(sizeof(int) * (size + 1));
		//ÿ��λ�õ������һ��λ��������Ԫ�ظ���
		radixArrays[i][0] = 0;
	}

	//��������������ֳ���
	int len = 1, p = 10;
	for (int i = 0; i < size; i++) {
		while (a[i] > p) {
			p *= 10;
			len++;
		}
	}

	for (int pos = 1; pos <= len; pos++)    //�Ӹ�λ��ʼ��31λ
	{
		//����
		for (int i = 0; i < size; i++)
		{
			//ȡ�����������λ���ϵ�����
			int num = getBit(a[i], pos);
			//�ö�Ӧλ�ü�����һ
			int index = ++radixArrays[num][0];
			//��Ԫ�طŵ���Ӧλ��
			radixArrays[num][index] = a[i];
		}
		//���գ�׼����������
		for (int i = 0, j = 0; i < BASE_SIZE; i++)
		{
			for (int k = 1; k <= radixArrays[i][0]; k++) {
				a[j++] = radixArrays[i][k];
			}
			//������λ
			radixArrays[i][0] = 0;
		}
	}

}



void ColorSwap(int* a, int p1, int p2) {
	int temp = a[p1];
	a[p1] = a[p2];
	a[p2] = temp;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a, int size) {
	int left = 0;
	int right = size - 1;
	int i = 0;
	while (i <= right) {
		if (a[i] == 0) {
			ColorSwap(a, i, left++);
		}
		else if (a[i] == 2) {
			ColorSwap(a, i, right--);
		}
		i++;
	}
}

//���������ɫ����������Ƿ�Ϸ�
int ChecColorData(int *a, int size) {
	for (int i = 0; i < size; i++) {
		if (a[i] > 2 || a[i] < 0) {
			return -1;
		}
	}
	return 0;
}


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */
 //ǿ�з��롣��������
int NumberKBig(int * a, int size, int k) {
	//�����һ���ǵ�K��
	int begin = 0;
	int end = size - 1;
	//��K�󣬽���Ϊ��С�����ţ���(size-k)+1��
	return GetK(a, begin, end, (size - k) + 1);
}


int GetK(int * a, int begin, int end, int k) {

	if (begin == end) {
		return a[begin];
	}
	//ѡ��λ������׼
	int base = a[begin];

	//�����ŵ�������λ��
	int index = Partition(a, begin, end);

	if (index + 1 == k) {
		//����պ���K,����
		return base;
	}
	else {
		if (index + 1 < k) {
			//˵����K�������ұ�
			return GetK(a, index + 1, end, k);
		}
		else
		{
			return GetK(a, begin, index - 1, k);
		}
	}
}



InputData(int * data) {
	int i = 0, n;
	printf("�����������ָ�����\n");
	n = InputNumber();
	for (int i = 0; i < MAX_SIZE&&i < n; i++) {
		printf("�������%d�����֣�", i + 1);
		data[i] = InputNumber();
	}
	return n;
}

Print(int*data, int n) {
	if (n == 0) {
		printf("��ǰû������\n");
		return n;
	}
	printf("��ǰ����Ľ�����£�\n");

	for (int i = 0; i < MAX_SIZE&&i < n; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
	system("pause");
	return n;
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

int test(int* a, int *n) {
	printf("������������:");
	do {
		*n = InputNumber();
		if (*n > MAX_SIZE || *n < 0) {
			printf("����������ݲ���������������[0-%d]:",MAX_SIZE);
		}
		else
		{
			break;
		}
	} while (1);
	for (int i = 0; i < *n; i++) {
		a[i] = rand();
		printf("���������������[%d]\n", a[i]);
	}
	printf("\n���������������ɣ���������%d\n",*n);
	printf("======================================================\n");
	printf(" 1. -----��������\n");
	printf(" 2. -----�鲢����\n");
	printf(" 3. -----�������򣨵ݹ飩\n");
	printf(" 4. -----�������򣨷ǵݹ飩\n");
	printf(" 5. -----��������\n");
	printf(" 6. -----������������\n");
	printf(" 7. -----��ɫ����\n");
	printf(" 8. -----�ҳ���K��\n");
	printf(" 9. -----�˳�\n");
	printf(" �����ߣ�@���ڳ�\n");
	printf("======================================================\n\n");
	printf("\n");
}