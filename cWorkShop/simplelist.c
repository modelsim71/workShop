#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tag_simple_list {
	int data;
    struct tag_simple_list * link;
} SIMPLE_LIST_T, *SIMPLE_LIST_P;


SIMPLE_LIST_P pHead = NULL;

int simple_list_add(int data)
{
	SIMPLE_LIST_P  next  = NULL;
	SIMPLE_LIST_P  prev  = NULL;
    SIMPLE_LIST_P  pNode = NULL;

	pNode = malloc(sizeof(SIMPLE_LIST_T));
	if (NULL == pNode) {
		return -1;
	}
	memset(pNode, 0, sizeof(SIMPLE_LIST_T));
	pNode->data = data;
	pNode->link = NULL;
    
    if (NULL == pHead) {
		pHead = pNode;
	}
	else {
		prev  = pHead;
		next  = pHead->link;
		while ((NULL != next) && (next->data > data)) {
			prev  = next;
			next  = next->link;
		}
	    if (/*(next == NULL) && */(prev->data < data)) {
			pNode->link = pHead;
			pHead = pNode;
		} else {
			prev->link = pNode;
            pNode->link = next;
		}
	}
	simple_list_print();
    return 0;
}	
		 
int simple_list_del(int data)
{
	SIMPLE_LIST_P  pTemp = NULL;
	SIMPLE_LIST_P  prev= NULL;

	prev = pHead;
	pTemp = pHead->link;

	while (NULL != pTemp) {
		if (data == pTemp->data) {
			prev->link = pTemp->link;
			free(pTemp);
			break ;
		}
		prev = pTemp;
		pTemp = pTemp->link;
	}

	return 0;
}

int simple_list_print(void)
{
	SIMPLE_LIST_P pTemp = NULL;

	printf("\narray print :\n");

	pTemp = pHead;
	while (NULL != pTemp) {
	    printf("%d ", pTemp->data);
		pTemp = pTemp->link;
	}
	printf("\n");
    return ;
}






