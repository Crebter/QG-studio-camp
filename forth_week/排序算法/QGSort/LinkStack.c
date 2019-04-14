#include"LinkStack.h"

StackNode * bottom = NULL;
//��ջ(���������)
Status initLStack(LinkStack *s) {
	s->count = 0;
	s->top = (StackNode*)malloc(sizeof(StackNode));
	s->top->data = 1234567890;
	s->top->next = NULL;
	bottom = s->top;
	printf("�ɹ�����һ��ջ\n");
	return SUCCESS;
}

bool isEmptyLStack(LinkStack *s) {
	if (s->count == 0) {
		return true;
	}
	else
	{
		return false;
	}
}

Status getTopLStack(LinkStack *s, ElemType *e) {
	*e = s->top->data;
	return SUCCESS;
}
Status clearLStack(LinkStack *s) {
	StackNode* p = NULL;
	s->count = 0;
	s->top = bottom;
	p = bottom = bottom->next;
	while (p)
	{
		p = bottom->next;
		free(bottom);
		bottom = p;
	}
	return SUCCESS;
}
Status destroyLStack(LinkStack *s) {
	StackNode* p = NULL;
	s->count = 0;
	s->top = NULL;
	while (p)
	{
		p = bottom->next;
		free(bottom);
		bottom = p;
	}
	return SUCCESS;
}
Status LStackLength(LinkStack *s, int *length) {
	*length = s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack *s, ElemType data) {
	StackNode * p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	p->next = NULL;
	s->top->next = p;
	s->top = p;
	s->count++;
	printf("�ɹ���Ԫ��%dѹ��ջ\n", data);
	return SUCCESS;
}
Status popLStack(LinkStack *s, ElemType *data) {
	StackNode * p = bottom;
	if (s->count == 0) {
		printf("��ǰջ�ѿ�\n");
		return ERROR;
	}
	else
	{
		*data = s->top->data;
		for (; p; p = p->next) {
			if (p->next == s->top) {
				free(p->next);
				p->next = NULL;
				s->top = p;
				s->count--;
				break;
			}
		}
		printf("�ɹ���Ԫ��%d�Ƴ�ջ\n", *data);
		return SUCCESS;
	}
}

