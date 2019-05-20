
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"

typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�

typedef struct  BiTNode {
	TElemType      data;     // ������
	struct BiTNode  *lchild, *rchild;  // ���Һ���ָ��
} BiTNode, *BiTree;   // ��������

typedef enum Status {
	SUCEESS,
	ERROR
}Status;


Status InitBiTree(BiTree T);
//�������������ն�����T

Status DestroyBiTree(BiTree T);
//��ʼ������������T����
//����������ݻٶ�����T

Status CreateBiTree(BiTree T, char* definition);
//��ʼ������ definition�����������Ķ���
//�����������definition���������T

//���²��ֺ�������δָ����������
Status PreOrderTraverse(BiTNode T, Status(*visit)(TElemType e));
//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��
Status InOrderTraverse(BiTNode T, Status(*visit)(TElemType e));	//�������
Status PostOrderTraverse(BiTNode T, Status(*visit)(TElemType e));	//�������
Status LevelOrderTraverse(BiTNode T, Status(*visit)(TElemType e));	//�������
int Value(BiTNode T);			//������Ķ�������ֵ
char InputOperator();
void Print(char data);
int Operate(int n1, int n2, char operate);


/*
��ʾ�����ڽ��ṹ�������ø�Tagֵ��־������������������������
�ɸ�����Ҫ�������Ӳ���.
*/
