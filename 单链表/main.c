/*****************************************************************************
* @author      : hunter                                                      *
* @date        :                                                             *
* @file        :                                                             *
* @brief       :                                                             *
* @description :                                                             *
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS


// 定义节点类型
typedef struct Node {
	int data;			// 数据类型，你可以把int型的data换成任意数据类型，包括结构体struct等复合类型
	struct Node* next;	// 单链表的指针域
}Node, *LinkedList;
//Node表示结点的类型，LinkedList表示指向Node结点类型的指针类型

// 初始化链表
LinkedList listinit() {
	Node* L;
	L = (Node*)malloc(sizeof(Node));   // 开辟空间
	if (L == NULL) {				 // 判断开辟空间是否失败，这一步很重要
		exit(-1);
	}
	L->next = NULL;					// 指针指向空
}

//单链表的建立1，头插法建立单链表
LinkedList LinkedListCreateH() {
	Node* L  = (Node*)malloc(sizeof(Node));
	if (L == NULL)
		return NULL;
	L->next = NULL;

	printf("请输入5个数字\n");
	int count = 0;
	int x;
	while (count < 5) {
		scanf_s("%d", &x);
		Node* p = (Node*)malloc(sizeof(Node));
		if (p == NULL)
			return NULL;
		p->data = x;
		p->next = L->next;
		L->next = p;
		count++;
	}
	return L;
}

//单链表的建立2，尾插法建立单链表
LinkedList LinkedListCreateT() { 
	Node* L = (Node*)malloc(sizeof(Node));		// 申请头结点空间
	if (L == NULL)
		return NULL;
	L->next = NULL;								// 初始化一个空链表

	Node* r = L;								// r始终指向终端节点，开始时指向头节点

	printf("请输入5个数字\n");
	int count = 0;
	int x;										// x为链表数据域中的数据
	while (count < 5) {
		scanf_s("%d", &x);
		Node* p = (Node*)malloc(sizeof(Node));	// 申请新的结点
		if (p == NULL)
			return NULL;
		p->data = x;							// 结点数据域赋值
		r->next = p;							// 将结点插入到表头L-->|1|-->|2|-->NULL
		r = p;									// 将r指向当前节点
		count++;
	}
	r->next = NULL;
	return L;
}

//便利输出单链表
void printList(LinkedList L) {
	Node* p = L->next;
	int i = 0;
	while (p) {
		printf("第%d个元素的值为:%d\n", ++i, p->data);
		p = p->next;
	}
}

int main() {
	Node* p;
	p = LinkedListCreateT();
	printList(p);
	return 0;
}