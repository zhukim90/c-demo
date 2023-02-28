/*****************************************************************************
* @author      : hunter                                                      *
* @date        :                                                             *
* @file        :                                                             *
* @brief       :                                                             *
* @description :                                                             *
*****************************************************************************/

#include<stdio.h>
#include<stdlib.h>
//��㶨��
typedef struct node {
    int data;
    struct node* next;
}node;
//���ж��壬����ָ��Ͷ�βָ��
typedef struct queue {
    node* front;
    node* rear;
}queue;

//��ʼ�����
node* init_node() {
    node* n = (node*)malloc(sizeof(node));
    if (n == NULL) {    //����ʧ�ܣ��˳�
        exit(0);
    }
    return n;
}

//��ʼ������
queue* init_queue() {
    queue* q = (queue*)malloc(sizeof(queue));
    if (q == NULL) {    //����ʧ�ܣ��˳�
        exit(0);
    }
    //ͷβ������ֵNULL
    q->front = NULL;
    q->rear = NULL;
    return q;
}

//�����п�
int empty(queue* q) {
    if (q->front == NULL) {
        return 1;   //1--��ʾ�棬˵�����зǿ�
    }
    else {
        return 0;   //0--��ʾ�٣�˵������Ϊ��
    }
}

//��Ӳ���
void push(queue* q, int data) {
    node* n = init_node();
    n->data = data;
    n->next = NULL;   //����β���뷨
    //if(q->rear==NULL){  
    if (empty(q)) {
        q->front = n;
        q->rear = n;
    }
    else {
        q->rear->next = n;    //n��Ϊ��ǰβ������һ���
        q->rear = n;  //��βָ��ָ��n
    }
}

//���Ӳ���
void pop(queue* q) {
    node* n = q->front;
    if (empty(q)) {
        return;    //��ʱ����Ϊ�գ�ֱ�ӷ��غ�������
    }
    if (q->front == q->rear) {
        q->front = NULL;  //ֻ��һ��Ԫ��ʱֱ�ӽ�����ָ���ƿռ���
        q->rear = NULL;
        free(n);        //�ǵù黹�ڴ�ռ�
    }
    else {
        q->front = q->front->next;
        free(n);
    }
}

//��ӡ����Ԫ��
void print_queue(queue* q) {
    node* n = init_node();
    n = q->front;
    if (empty(q)) {
        return;    //��ʱ����Ϊ�գ�ֱ�ӷ��غ�������
    }
    while (n != NULL)
    {
        printf("%d\t", n->data);
        n = n->next;
    }
    printf("\n");   //�ǵû���
}

//���������ã�����ֻ�Ǽ򵥽����÷�
int main() {
    queue* q = init_queue();
    ///////////////��Ӳ���/////////////////
    printf("���\n");
    for (int i = 1; i <= 5; i++) {
        push(q, i);
        print_queue(q);
    }
    ///////////////���Ӳ���/////////////////
    printf("����\n");
    for (int i = 1; i <= 5; i++) {
        pop(q);
        print_queue(q);
    }
    return 0;
}
