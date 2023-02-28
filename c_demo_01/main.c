/*****************************************************************************
* @author      : hunter                                                      *
* @date        :                                                             *
* @file        :                                                             *
* @brief       :                                                             *
* @description :                                                             *
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int *p;							// 定义一个指向整型的指针变量
	p = malloc(5 * sizeof(int));	// 申请5个整形大小的内存空间并返回起始地址给p
	if (p == NULL) {				// 判断是否申请失败
		exit(1);					// 退出
	}

	p[0] = 100;						// 给空间添加数据
	printf("%d", p[0]);				// 打印数据
	free(p);						// 释放p的内存空间，此时p依旧存在，只不过失去了指向的对象，成了野指针
	p = NULL;						// 为其赋NULL，此时它不再是一个野指针
	return 0;
}