#include"main.h"


int main()
{
	menu();

}

void menu()
{ // �˵�
	int choice = 0;
	BiTree T = malloc(sizeof(BiTNode));
	T->data = NULL;
	Status status = ERROR;
	do {
		printf("\n");
		system("pause");
		system("cls");
		printf("\n");
		printf("======================================================\n");
		printf("\n");
		printf("*****************������ʵ��ǰ׺���ʽ����ֵ**************\n\n");
		printf(" 1. -----��ʼ���ն�����\n");
		printf(" 2. -----���ٶ�����\n");
		printf(" 3. -----�������\n");
		printf(" 4. -----�������\n");
		printf(" 5. -----�������\n");
		printf(" 6. -----��α���\n");
		printf(" 7. -----���ʽ��ֵ\n");
		printf(" 8. -----�˳�\n");
		printf(" �����ߣ�@���ڳ�\n");
		printf("==========================================+============\n\n");
		printf("\n");
		printf("��ѡ������Ҫִ�еĲ���: ");
		char opr;
		switch (InputNumber())
		{
		case 1:
			printf("�밴ǰ׺���ʽ�������ֺ����������+1*34\n");
			status = InitBiTree(T);
			break;
		case 2:
			status = DestroyBiTree(T);
			if (status == SUCEESS) {
				printf("���ٶ������ɹ�");
				T = malloc(sizeof(BiTNode));
				T->data = NULL;
			}
			break;
		case 3:
			status = PreOrderTraverse(*T, &Print);
			break;
		case 4:
			status = InOrderTraverse(*T, &Print);
			break;
		case 5:
			status = PostOrderTraverse(*T, &Print);
			break;
		case 6:
			status = LevelOrderTraverse(*T, &Print);
			break;
		case 7:
			if (T->data == NULL) {
				printf("������û�б���ʼ�������ȶԸ������г�ʼ��");
				break;
			}
			printf("������ı��ʽ��ֵΪ��%d", Value(*T));
			break;
		case 8:
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
