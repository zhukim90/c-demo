/*****************************************************************************
* @author      : hunter                                                      *
* @date        :                                                             *
* @file        :                                                             *
* @brief       :                                                             *
* @description :                                                             *
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct line {
	int data;
	struct line* pre;		// pre node
	struct line* next;		// next node
}line, *a;


// 双向链表创建
line* initline(line* head) {
	int number, pos = 1, input_data; // 分别代表节点数量，当前位置，输入的数据
	printf("请输入创建节点的大小\n");
	scanf_s("%d", &number);

	if (number < 1) {
		return NULL;
	}

	// 头节点创建
	head = (line*)malloc(sizeof(line));
	head->pre = NULL;
	head->next = NULL;

	printf("输入第%d个数据", pos++);
	scanf_s("%d", &input_data);
	head->data = input_data;

	line* list = head;
	while (pos <= number) {
		line* body = (line*)malloc(sizeof(line));
		body->pre = NULL;
		body->next = NULL;
		printf("输入第%d个数据", pos++);
		scanf_s("%d", &input_data);
		body->data = input_data;
		list->next = body;
		body->pre = list;
		list = list->next;
	}
	return head;
}

// 插入数据
line* insertline(line* head, int data, int add) { // 分别为进行插入的链表，插入的数据，插入的位置
	line* tmp = (line*)malloc(sizeof(line));	  // 开辟新节点
	if (tmp == NULL)
		return NULL;
	tmp->data = data;
	tmp->pre = NULL;
	tmp->next = NULL;

	if (add == 1) { // 插入到链表头部， 要特殊考虑
		tmp->next = head;
		head->pre = tmp;
		head = tmp;
	}
	else {
		line* body = head;
		// 找到要插入位置的前一个节点
		for (int i = 0; i < add - 1; i++) {
			body = body->next;
		}
		// 如果为真，说明插入的位置是尾部
		if (body->next == NULL) {
			body->next = tmp;
			tmp->pre = body;
		}
		else {
			body->next->pre = tmp;
			tmp->next = body->next;
			body->next = tmp;
			tmp->pre = body;
		}
	}
	return head;
}

//删除元素
line* deleteLine(line* head, int data) {
	//输入的参数分别为进行此操作的双链表，需要删除的数据
	line* list = head;
	//遍历链表
	while (list) {
		//判断是否与此元素相等
		//删除该点方法为将该结点前一结点的next指向该节点后一结点
		//同时将该结点的后一结点的pre指向该节点的前一结点
		if (list->data == data) {
			list->pre->next = list->next;
			list->next->pre = list->pre;
			free(list);
			printf("--删除成功--\n");
			return head;
		}
		list = list->next;
	}
	printf("Error:没有找到该元素，没有产生删除\n");
	return head;
}


//遍历双链表,同时打印元素数据
void printLine(line* head) {
	line* list = head;
	int pos = 1;
	while (list) {
		printf("第%d个数据是:%d\n", pos++, list->data);
		list = list->next;
	}
}

int main() {
	line* p = NULL;
	p= initline(p);
	printLine(p);
	p= insertline(p, 6, 3);
	printLine(p);
	p = deleteLine(p, 6);
	printLine(p);
	return 0;
}