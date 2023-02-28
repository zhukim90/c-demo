/*****************************************************************************
* @author      : hunter                                                      *
* @date        :                                                             *
* @file        :                                                             *
* @brief       :                                                             *
* @description : ����ջ����                                                            *
*****************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 10000

//������
typedef struct stack {
    int data[maxn];
    int top;
}stack;

//����
stack* init() {
    stack* s = (stack*)malloc(sizeof(stack));
    if (s == NULL) {
        printf("�����ڴ�ռ�ʧ��");
        exit(0);
    }
    memset(s->data, 0, sizeof(s->data));
    //memset���������ڿ��ļ�string.h�����ʾ�������ռ���г�ʼ��
    //�������Բ��İٶȰٿ�https://baike.baidu.com/item/memset/4747579?fr=aladdin
    s->top = 0;     //ջ��top��bottom��Ϊ0����ʾΪ�գ�
    return s;
}

//��ջpush
void push(stack* s, int data) {
    s->data[s->top] = data;
    s->top++;
}

//��ջpop
void pop(stack* s) {
    if (s->top != 0) {
        s->data[s->top] = 0;  //����ع�0ģ���ʾδ��ʼ������
        s->top--;
    }
}

//ģ���ӡջ��Ԫ��
void print_stack(stack* s) {
    for (int n = s->top - 1; n >= 0; n--) {
        printf("%d\t", s->data[n]);
    }
    printf("\n");   //ϰ���Ի���
}

int main() {
    stack* s = init();
    int input[5] = { 11,22,33,44,55 };  //ģ�������������
    for (int i = 0; i < 5; i++) {
        push(s, input[i]);
    }
    print_stack(s);
    /////////////
    pop(s);
    print_stack(s);
    return 0;
}