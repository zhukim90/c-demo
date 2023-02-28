/*****************************************************************************
* @author      : hunter                                                      *
* @date        :                                                             *
* @file        :                                                             *
* @brief       :                                                             *
* @description : ����ջ����                                                            *
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// ջ�Ľڵ����
typedef struct Node {
	int data;
	struct Node* next;
}Node;

// ����ջ
typedef struct stack {
	Node* top;		// ָ��ͷ�ڵ�
	int count;		// ����
}Link_Stack;

//����ջ
Link_Stack* Creat_stack()
{
	Link_Stack* p;
	//p = new Link_Stack;
	p = (Link_Stack*)malloc(sizeof(Link_Stack));
	if (p == NULL) {
		printf("����ʧ�ܣ������˳�����");
		exit(0);
	}
	p->count = 0;
	p->top = NULL;
	return p;
}

// ��ջ
Link_Stack* Push_stack(Link_Stack* p, int elem) {
	if (p == NULL)
		return NULL;
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
		return NULL;
	tmp->data = elem;
	tmp->next = p->top;
	p->top = tmp;
	p->count++;
	return p;
}

Link_Stack* Pop_stack(Link_Stack* p) {
	Node* tmp = p->top;
	if (p->top == NULL) {
		printf("����ջΪ��");
		return p;
	}
	else {
		p->top = p->top->next;
		free(tmp);
		p->count--;
		return p;
	}
}

//����ջ�����ջ������Ԫ��
int show_stack(Link_Stack* p)
{
	Node* temp;
	temp = p->top;
	if (p->top == NULL)
	{
		printf("");
		printf("����ջΪ��");
		return 0;
	}
	while (temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return 0;
}

int main() {
	Link_Stack* p;
	p = Creat_stack();
	int n = 6;
	int input[6] = { 12,23,45,66,44,78 };
	for (int i = 0; i < n; i++) {
		Push_stack(p, input[i]);
	}
	show_stack(p);
	Pop_stack(p);
	show_stack(p);
	return 0;

}