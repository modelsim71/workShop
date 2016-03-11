#include <stdio.h>
#include "quick_sort.h"


static int quick_sort_test(void);

int main(int argc, char **argv)
{
	//quick_sort_test();
    simple_list_test();

    return 0;
}

int quick_sort_test(void)
{
	int i = 0;
    int a[10] = {100, 2, 54, 23, 7, 25, 28, 99, 11};

	printf("Array before sort : \n");
	
	for (i=0; i<10; i++)
	{
		printf(" %d", a[i]);
	}
	printf("\n");
    
	quick_sort(a, 0, 9);

	printf("Array after sort : \n");

	for (i=0; i<10; i++)
	{
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}


int simple_list_test(void)
{
	int i = 0;
    int data[7] = {4, 1, 15, 165, -1, 15, 17};

	printf("Array before sort : \n");
    for (i=0; i<7; i++) {
		printf("%d ", data[i]);
	}

	printf("\ninsert data int array:\n");
	for (i=0; i<7; i++) {
	    simple_list_add(data[i]);
	}

	printf("Array afert sort : \n");

    simple_list_print();

	return 0;
}

