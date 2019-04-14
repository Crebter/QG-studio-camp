#define _CRT_SECURE_NO_WARNINGS

#include"qgsort.h"



/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
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
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a, int begin, int mid, int end, int *temp) {
	temp = (int *)malloc((end - begin + 1) * sizeof(int));
	//申请空间，使其大小为两个
	int left_begin = begin;
	int left_end = mid;
	int right_begin = mid + 1;
	int right_end = end;

	int i, k;
	for (k = 0; left_begin <= left_end && right_begin <= right_end; k++) {  // 比较两个指针所指向的元素
		if (a[left_begin] <= a[right_begin]) {
			temp[k] = a[left_begin++];
		}
		else {
			temp[k] = a[right_begin++];
		}
	}

	if (left_begin <= left_end) {  //若第一个序列有剩余，直接复制出来粘到合并序列尾
	//memcpy(tmp+k, arr+left_low, (left_high-left_low+l)*sizeof(int));
		for (i = left_begin; i <= left_end; i++)
			temp[k++] = a[i];
	}

	if (right_begin <= right_end) {
		//若第二个序列有剩余，直接复制出来粘到合并序列尾
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
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a, int begin, int end, int *temp) {
	int mid = 0;
	if (begin < end) {
		mid = (begin + end) / 2; /* 注意防止溢出 */
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
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end) {
	if (begin < end)
	{
		//把基准数排好
		int base = Partition(a, begin, end);
		//递归
		QuickSort_Recursion(a, end, base - 1);
		QuickSort_Recursion(a, base + 1, end);
	}
	return;
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a, int size) {
	int base;
	int left = 0;
	int right = size - 1;
	int n;
	LinkStack stack;
	//初始栈
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
		//左侧先入栈
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

/*用于快速排序中交换元素*/
void Swap(int a[], int begin, int end)
{
	int temp = a[begin];
	a[begin] = a[end];
	a[end] = temp;
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end) {
	//选取基准数
	int base = a[begin];
	while (begin < end)
	{
		//从后边开始，找到比基准数小的
		while (begin < end && a[end] >= base)
		{
			end--;
		}
		Swap(a, begin, end);
		//从前面开始，找到比基准数大的
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
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size, int max) {
	int *temp, *result;
	//用来计数
	temp = (int *)malloc(sizeof(int)*max);
	//临时存放排序结果
	result = (int *)malloc(sizeof(int)*size);
	//把计数数组初始化
	memset(temp, 0, sizeof(int)*max);
	//统计各个元素出现次数
	for (int i = 0; i < size; i++) {
		temp[a[i]] += 1;
	}
	//统计小于等于它的元素个数
	for (int i = 1; i < max; i++) {
		temp[i] = temp[i - 1] + temp[i];
	}
	//从后面开始，把每个元素填到对应位置
	for (int i = size - 1; i >= 0; i--)
	{
		result[temp[a[i]] - 1] = a[i];
		temp[a[i]]--;
	}
	//按照排序的结果填到原来的数组中
	for (int i = 0; i < size; i++) {
		a[i] = result[i];
	}
	free(temp);
	free(result);
}


//取出本次排序的位置上的数字
int getBit(int num, int pos) {
	int temp = 1;
	for (int i = 0; i < pos - 1; i++) {
		temp *= 10;
	}
	return (num / temp) % 10;
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a, int size) {
	//索引数组
	int *radixArrays[BASE_SIZE];

	//分配空间
	for (int i = 0; i < 10; i++)
	{
		//给每个0-BASE_SIZE每个位置分配一个数组
		radixArrays[i] = (int *)malloc(sizeof(int) * (size + 1));
		//每个位置的数组第一个位置用来存元素个数
		radixArrays[i][0] = 0;
	}

	//计算数组中最长数字长度
	int len = 1, p = 10;
	for (int i = 0; i < size; i++) {
		while (a[i] > p) {
			p *= 10;
			len++;
		}
	}

	for (int pos = 1; pos <= len; pos++)    //从个位开始到31位
	{
		//排序
		for (int i = 0; i < size; i++)
		{
			//取出本次排序的位置上的数字
			int num = getBit(a[i], pos);
			//让对应位置计数加一
			int index = ++radixArrays[num][0];
			//把元素放到对应位置
			radixArrays[num][index] = a[i];
		}
		//回收，准备下轮排序
		for (int i = 0, j = 0; i < BASE_SIZE; i++)
		{
			for (int k = 1; k <= radixArrays[i][0]; k++) {
				a[j++] = radixArrays[i][k];
			}
			//计数复位
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
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
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

//检查用于颜色排序的数据是否合法
int ChecColorData(int *a, int size) {
	for (int i = 0; i < size; i++) {
		if (a[i] > 2 || a[i] < 0) {
			return -1;
		}
	}
	return 0;
}


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
 //强行翻译。。。。。
int NumberKBig(int * a, int size, int k) {
	//假设第一个是第K大
	int begin = 0;
	int end = size - 1;
	//第K大，解释为从小到大排，第(size-k)+1个
	return GetK(a, begin, end, (size - k) + 1);
}


int GetK(int * a, int begin, int end, int k) {

	if (begin == end) {
		return a[begin];
	}
	//选中位数做基准
	int base = a[begin];

	//把它排到它所在位置
	int index = Partition(a, begin, end);

	if (index + 1 == k) {
		//如果刚好是K,返回
		return base;
	}
	else {
		if (index + 1 < k) {
			//说明第K大在它右边
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
	printf("输入排序数字个数：\n");
	n = InputNumber();
	for (int i = 0; i < MAX_SIZE&&i < n; i++) {
		printf("请输入第%d个数字：", i + 1);
		data[i] = InputNumber();
	}
	return n;
}

Print(int*data, int n) {
	if (n == 0) {
		printf("当前没有数据\n");
		return n;
	}
	printf("当前排序的结果如下：\n");

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

int test(int* a, int *n) {
	printf("请输入数据量:");
	do {
		*n = InputNumber();
		if (*n > MAX_SIZE || *n < 0) {
			printf("您输入的数据不合理，请重新输入[0-%d]:",MAX_SIZE);
		}
		else
		{
			break;
		}
	} while (1);
	for (int i = 0; i < *n; i++) {
		a[i] = rand();
		printf("正在生成随机数：[%d]\n", a[i]);
	}
	printf("\n随机数据已生成完成！数据量：%d\n",*n);
	printf("======================================================\n");
	printf(" 1. -----插入排序\n");
	printf(" 2. -----归并排序\n");
	printf(" 3. -----快速排序（递归）\n");
	printf(" 4. -----快速排序（非递归）\n");
	printf(" 5. -----计数排序\n");
	printf(" 6. -----基数计数排序\n");
	printf(" 7. -----颜色排序\n");
	printf(" 8. -----找出第K大\n");
	printf(" 9. -----退出\n");
	printf(" 开发者：@黄钰朝\n");
	printf("======================================================\n\n");
	printf("\n");
}