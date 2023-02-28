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


// ����ڵ�����
typedef struct Node {
	int data;			// �������ͣ�����԰�int�͵�data���������������ͣ������ṹ��struct�ȸ�������
	struct Node* next;	// �������ָ����
}Node, *LinkedList;
//Node��ʾ�������ͣ�LinkedList��ʾָ��Node������͵�ָ������

// ��ʼ������
LinkedList listinit() {
	Node* L;
	L = (Node*)malloc(sizeof(Node));   // ���ٿռ�
	if (L == NULL) {				 // �жϿ��ٿռ��Ƿ�ʧ�ܣ���һ������Ҫ
		exit(-1);
	}
	L->next = NULL;					// ָ��ָ���
}

//������Ľ���1��ͷ�巨����������
LinkedList LinkedListCreateH() {
	Node* L  = (Node*)malloc(sizeof(Node));
	if (L == NULL)
		return NULL;
	L->next = NULL;

	printf("������5������\n");
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

//������Ľ���2��β�巨����������
LinkedList LinkedListCreateT() { 
	Node* L = (Node*)malloc(sizeof(Node));		// ����ͷ���ռ�
	if (L == NULL)
		return NULL;
	L->next = NULL;								// ��ʼ��һ��������

	Node* r = L;								// rʼ��ָ���ն˽ڵ㣬��ʼʱָ��ͷ�ڵ�

	printf("������5������\n");
	int count = 0;
	int x;										// xΪ�����������е�����
	while (count < 5) {
		scanf_s("%d", &x);
		Node* p = (Node*)malloc(sizeof(Node));	// �����µĽ��
		if (p == NULL)
			return NULL;
		p->data = x;							// ���������ֵ
		r->next = p;							// �������뵽��ͷL-->|1|-->|2|-->NULL
		r = p;									// ��rָ��ǰ�ڵ�
		count++;
	}
	r->next = NULL;
	return L;
}

//�������������
void printList(LinkedList L) {
	Node* p = L->next;
	int i = 0;
	while (p) {
		printf("��%d��Ԫ�ص�ֵΪ:%d\n", ++i, p->data);
		p = p->next;
	}
}

int main() {
	Node* p;
	p = LinkedListCreateT();
	printList(p);
	return 0;
}