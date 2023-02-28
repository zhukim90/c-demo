/*****************************************************************************
* @author      : hunter                                                      *
* @date        :                                                             *
* @file        :                                                             *
* @brief       :                                                             *
* @description : 链表栈测试                                                            *
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// 栈的节点设计
typedef struct Node {
	int data;
	struct Node* next;
}Node;

// 定义栈
typedef struct stack {
	Node* top;		// 指向头节点
	int count;		// 计数
}Link_Stack;

//创建栈
Link_Stack* Creat_stack()
{
	Link_Stack* p;
	//p = new Link_Stack;
	p = (Link_Stack*)malloc(sizeof(Link_Stack));
	if (p == NULL) {
		printf("创建失败，即将退出程序");
		exit(0);
	}
	p->count = 0;
	p->top = NULL;
	return p;
}

// 入栈
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
		printf("错误，栈为空");
		return p;
	}
	else {
		p->top = p->top->next;
		free(tmp);
		p->count--;
		return p;
	}
}

//遍历栈：输出栈中所有元素
int show_stack(Link_Stack* p)
{
	Node* temp;
	temp = p->top;
	if (p->top == NULL)
	{
		printf("");
		printf("错误：栈为空");
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