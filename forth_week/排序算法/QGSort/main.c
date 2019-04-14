#include"main.h"

int main()
{
	menu();

}

void menu()
{ // 菜单
	/*定义数据数组*/
	int data[MAX_SIZE] = { 0 };
	/*承载数组*/
	int temp[MAX_SIZE] = { 0 };
	int n = 0;//排序元素个数
	int choice = 0;
	do {
		system("cls");
		printf("\n");
		printf("======================================================\n");
		printf("\n");
		printf("*****************排序算法的实现*******************\n\n");
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
		Print(&data, n);
		printf("请选择数据形式：[0]手动输入,[1]随机大数据测试");
		do {
			choice = InputNumber();
			//手动输入
			if (choice == 0) {
				//初次输入
				if (n == 0) {
					printf("请输入排序数据\n");
					n = InputData(&data);
				}
				else
				{
					printf("请选择是否重新录入数据：[0]否,[1]是");
					do {
						choice = InputNumber();
						//重新输入
						if (choice == 0) { break; }
						else if (choice == 1)
						{
							n = InputData(&data); break;
						}
						printf("没有该选项,请重新输入：");
					} while (1);
				}
				break; 
			}
			//随机数
			else if (choice == 1)
			{
				//初次输入
				if (n == 0) {
					test(&data, &n);
					break;
				}
				else
				{
					printf("请选择是否重新生成数据：[0]否,[1]是");
					do {
						choice = InputNumber();
						//重新输入
						if (choice == 0) { break; }
						else if (choice == 1)
						{
							test(&data, &n);
							break;
						}
						printf("没有该选项,请重新输入：");
					} while (1);
				}
				break;
			}
			printf("没有该选项,请重新输入：");
		} while (1);
		
		printf("请选择您想要执行的操作: ");
		switch (InputNumber())
		{
		case 1:
			insertSort(&data, n);
			break;
		case 2:
			MergeSort(&data, 0, n - 1, temp);
			break;

		case 3:
			QuickSort_Recursion(&data, 0, n - 1);
			break;
		case 4:
			QuickSort(&data, n);
			break;
		case 5:
			CountSort(&data, n, MAX_SIZE);
			break;
		case 6:
			RadixCountSort(&data, n);
			break;
		case 7:
			if (ChecColorData(&data, n) == 0) {
				ColorSort(&data, n);
			}
			else
			{
				printf("您输入的数据不是[0,1,2]的范围，无法使用颜色排序\n");
				system("pause");
			}
			break;
		case 8:
			printf("您想找第几大的数？：");
			int k = InputNumber();
			if (k > 0 && k < n) {
				printf("第%d大的数为%d\n", k, NumberKBig(&data, n, k));
			}
			else
			{
				printf("您输入的数字超过数组的大小了\n");
			}
			system("pause");
			break;
		case 9:
			printf("===================bye====================\n");
			system("pause");
			exit(0);
			break;
		default:
			//如果输入的字符无法匹配功能，则输出错误
			printf("您输入的选项已经超出范围！\n");
			system("pause");
		}
	} while (1);
}
