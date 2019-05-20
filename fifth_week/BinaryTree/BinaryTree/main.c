#include"main.h"


int main()
{
	menu();

}

void menu()
{ // 菜单
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
		printf("*****************二叉树实现前缀表达式的求值**************\n\n");
		printf(" 1. -----初始化空二叉树\n");
		printf(" 2. -----销毁二叉树\n");
		printf(" 3. -----先序遍历\n");
		printf(" 4. -----中序遍历\n");
		printf(" 5. -----后序遍历\n");
		printf(" 6. -----层次遍历\n");
		printf(" 7. -----表达式求值\n");
		printf(" 8. -----退出\n");
		printf(" 开发者：@黄钰朝\n");
		printf("==========================================+============\n\n");
		printf("\n");
		printf("请选择您想要执行的操作: ");
		char opr;
		switch (InputNumber())
		{
		case 1:
			printf("请按前缀表达式输入数字和运算符，如+1*34\n");
			status = InitBiTree(T);
			break;
		case 2:
			status = DestroyBiTree(T);
			if (status == SUCEESS) {
				printf("销毁二叉树成功");
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
				printf("该树还没有被初始化，请先对该树进行初始化");
				break;
			}
			printf("您输入的表达式的值为：%d", Value(*T));
			break;
		case 8:
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
