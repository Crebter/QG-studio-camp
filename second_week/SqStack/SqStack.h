#define _CRT_SECURE_NO_WARNINGS
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack {
	ElemType *elem;
	int top;
	int size;
} SqStack;



#include"stdbool.h"
#include<stdio.h>
#include<stdlib.h>

//˳��ջ(���������)
Status initStack(SqStack *s, int sizes);//��ʼ��ջ
bool isEmptyStack(SqStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopStack(SqStack *s, ElemType *e); //�õ�ջ��Ԫ��
Status clearStack(SqStack *s);//���ջ
Status destroyStack(SqStack *s);//����ջ
Status stackLength(SqStack *s, int *length);//���ջ����
Status pushStack(SqStack *s, ElemType data);//��ջ
Status popStack(SqStack *s, ElemType *data);//��ջ

Status printStack(SqStack * s);//�����ǰջ
int InputNumber();//����û�����

#endif // STACK_H_INCLUDED