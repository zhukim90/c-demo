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


// ˫��������
line* initline(line* head) {
	int number, pos = 1, input_data; // �ֱ����ڵ���������ǰλ�ã����������
	printf("�����봴���ڵ�Ĵ�С\n");
	scanf_s("%d", &number);

	if (number < 1) {
		return NULL;
	}

	// ͷ�ڵ㴴��
	head = (line*)malloc(sizeof(line));
	head->pre = NULL;
	head->next = NULL;

	printf("�����%d������", pos++);
	scanf_s("%d", &input_data);
	head->data = input_data;

	line* list = head;
	while (pos <= number) {
		line* body = (line*)malloc(sizeof(line));
		body->pre = NULL;
		body->next = NULL;
		printf("�����%d������", pos++);
		scanf_s("%d", &input_data);
		body->data = input_data;
		list->next = body;
		body->pre = list;
		list = list->next;
	}
	return head;
}

// ��������
line* insertline(line* head, int data, int add) { // �ֱ�Ϊ���в����������������ݣ������λ��
	line* tmp = (line*)malloc(sizeof(line));	  // �����½ڵ�
	if (tmp == NULL)
		return NULL;
	tmp->data = data;
	tmp->pre = NULL;
	tmp->next = NULL;

	if (add == 1) { // ���뵽����ͷ���� Ҫ���⿼��
		tmp->next = head;
		head->pre = tmp;
		head = tmp;
	}
	else {
		line* body = head;
		// �ҵ�Ҫ����λ�õ�ǰһ���ڵ�
		for (int i = 0; i < add - 1; i++) {
			body = body->next;
		}
		// ���Ϊ�棬˵�������λ����β��
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

//ɾ��Ԫ��
line* deleteLine(line* head, int data) {
	//����Ĳ����ֱ�Ϊ���д˲�����˫������Ҫɾ��������
	line* list = head;
	//��������
	while (list) {
		//�ж��Ƿ����Ԫ�����
		//ɾ���õ㷽��Ϊ���ý��ǰһ����nextָ��ýڵ��һ���
		//ͬʱ���ý��ĺ�һ����preָ��ýڵ��ǰһ���
		if (list->data == data) {
			list->pre->next = list->next;
			list->next->pre = list->pre;
			free(list);
			printf("--ɾ���ɹ�--\n");
			return head;
		}
		list = list->next;
	}
	printf("Error:û���ҵ���Ԫ�أ�û�в���ɾ��\n");
	return head;
}


//����˫����,ͬʱ��ӡԪ������
void printLine(line* head) {
	line* list = head;
	int pos = 1;
	while (list) {
		printf("��%d��������:%d\n", pos++, list->data);
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