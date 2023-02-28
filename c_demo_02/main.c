/*****************************************************************************
* @author      : hunter                                                      *
* @date        :                                                             *
* @file        :                                                             *
* @brief       :                                                             *
* @description :                                                             *
*****************************************************************************/

#include <stdio.h>

int main() {
	int i;
	char arr[10] = "ASDFGEREWS";
	for (i = 0; i < 10; i++) {
		printf("%cµÄµØÖ·ÊÇ£º%p\n", arr[i], &arr[i]);
	}
	return 0;
}