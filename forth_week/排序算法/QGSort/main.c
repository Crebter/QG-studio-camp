#include"main.h"

int main()
{
	menu();

}

void menu()
{ // �˵�
	/*������������*/
	int data[MAX_SIZE] = { 0 };
	/*��������*/
	int temp[MAX_SIZE] = { 0 };
	int n = 0;//����Ԫ�ظ���
	int choice = 0;
	do {
		system("cls");
		printf("\n");
		printf("======================================================\n");
		printf("\n");
		printf("*****************�����㷨��ʵ��*******************\n\n");
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
		Print(&data, n);
		printf("��ѡ��������ʽ��[0]�ֶ�����,[1]��������ݲ���");
		do {
			choice = InputNumber();
			//�ֶ�����
			if (choice == 0) {
				//��������
				if (n == 0) {
					printf("��������������\n");
					n = InputData(&data);
				}
				else
				{
					printf("��ѡ���Ƿ�����¼�����ݣ�[0]��,[1]��");
					do {
						choice = InputNumber();
						//��������
						if (choice == 0) { break; }
						else if (choice == 1)
						{
							n = InputData(&data); break;
						}
						printf("û�и�ѡ��,���������룺");
					} while (1);
				}
				break; 
			}
			//�����
			else if (choice == 1)
			{
				//��������
				if (n == 0) {
					test(&data, &n);
					break;
				}
				else
				{
					printf("��ѡ���Ƿ������������ݣ�[0]��,[1]��");
					do {
						choice = InputNumber();
						//��������
						if (choice == 0) { break; }
						else if (choice == 1)
						{
							test(&data, &n);
							break;
						}
						printf("û�и�ѡ��,���������룺");
					} while (1);
				}
				break;
			}
			printf("û�и�ѡ��,���������룺");
		} while (1);
		
		printf("��ѡ������Ҫִ�еĲ���: ");
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
				printf("����������ݲ���[0,1,2]�ķ�Χ���޷�ʹ����ɫ����\n");
				system("pause");
			}
			break;
		case 8:
			printf("�����ҵڼ����������");
			int k = InputNumber();
			if (k > 0 && k < n) {
				printf("��%d�����Ϊ%d\n", k, NumberKBig(&data, n, k));
			}
			else
			{
				printf("����������ֳ�������Ĵ�С��\n");
			}
			system("pause");
			break;
		case 9:
			printf("===================bye====================\n");
			system("pause");
			exit(0);
			break;
		default:
			//���������ַ��޷�ƥ�书�ܣ����������
			printf("�������ѡ���Ѿ�������Χ��\n");
			system("pause");
		}
	} while (1);
}
