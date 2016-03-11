#include <stdio.h>


int quick_sort(int array[], int low, int high)
{
    int first, last;
	int key;
	
	if (low >= high) {
		//printf("quick_sort : low %d > high %d", low, high);
		return -1;
	}
    
	first = low; 
	last  = high;
    key = array[first];
 
    while (first < last) {
	    while ((first < last) && (key <= array[last])) {
		    last--;
		}
	    array[first] = array[last];
        //printf("%d %d", first, last);	    
	    while ((first < last) && (key >= array[first])) {
		    first++;
		}
	    array[last] = array[first];	
		//printf("\n");
	}
    
	array[first] = key;
    //printf("first %d key %d\n", first, key);
	quick_sort(array, low, first-1);
	quick_sort(array, first+1, high);
	
    return 0;
}	
