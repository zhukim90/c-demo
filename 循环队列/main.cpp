/*****************************************************************************
* @author      : hunter                                                      *
* @date        :                                                             *
* @file        :                                                             *
* @brief       :                                                             *
* @description :                                                             *
*****************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#define maxsize 10      //��ʾѭ�����е��������

//ѭ�����еĽṹ���
typedef struct cir_queue {
    int data[maxsize];
    int rear;
    int front;
}cir_queue;

//��ʼ��
cir_queue* init() {
    cir_queue* q = (cir_queue*)malloc(sizeof(cir_queue));
    if (q == NULL) {
        exit(0);    //�����ڴ�ʧ�ܣ��˳�����
    }
    memset(q->data, 0, sizeof(q->data));
    q->front = 0;
    q->rear = 0;
    return q;
}

//��Ӳ���push
void push(cir_queue* q, int data) {
    if ((q->rear + 1) % maxsize == q->front) {
        printf("������޷����\n");
        return;
    }
    else {
        q->rear = (q->rear + 1) % maxsize;
        q->data[q->rear] = data;
    }
}

//���Ӳ���pop
void pop(cir_queue* q) {
    if (q->rear == q->front) {
        printf("����Ϊ�գ��޷�����\n");
        return;
    }
    else {
        q->data[q->front] = 0;
        q->front = (q->front + 1) % maxsize;
    }
}

//��������
void print(cir_queue* q) {
    int i = q->front;
    while (i != q->rear) {
        i = (i + 1) % maxsize;
        printf("%d\t", q->data[i]);
    }
    printf("\n");       //�ǵû���
}

int main() {
    cir_queue* q = init();
    ////////////��Ӳ���///////////////
    printf("��Ӳ���\n");
    for (int i = 1; i <= 6; i++) {
        push(q, i);
    }
    print(q);
    ////////////���Ӳ���///////////////
    printf("���Ӳ���\n");
    for (int i = 1; i <= 3; i++) {
        pop(q);
        print(q);
    }
    return 0;
}
