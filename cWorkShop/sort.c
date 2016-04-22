#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/*
 ************************************************************************************************  
 * Function     : void bubble_sort(int array[], int n)
 * Descriptions : bubble sort;
 * Arguments    :
 * Returns      : None
 * Author       :
 * Date         : 2016-03-19
 ************************************************************************************************  
 */
void bubble_sort(int array[], int n)
{
    int i = 0, j = 0, temp = 0;

    for (i=0; i<n; i++) {
        for (j=0; j<n-i-1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    return ;
}

/*
 ************************************************************************************************  
 * Function     : void select_sort(int array[], int n)
 * Descriptions : select sort;
 * Arguments    :
 * Returns      : None
 * Author       :
 * Date         : 2016-03-19
 ************************************************************************************************  
 */
void select_sort(int array[], int n)
{
    int i = 0, j = 0, min = 0, temp = 0;

    for (i=0; i<n; i++) {
        min = i;
        for (j=i+1; j<n; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (i != min) {
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
    return ;
}

/*
 ************************************************************************************************  
 * Function     : void insert_sort(int array[], int n)
 * Descriptions : insert sort;
 * Arguments    :
 * Returns      : None
 * Author       :
 * Date         : 2016-03-19
 ************************************************************************************************  
 */
void insert_sort(int array[], int n)
{
    int i = 0, j = 0, temp = 0;

    for (i=1; i<n; i++) {
        temp = array[i];
        for (j=i; j>0 && array[j-1]>temp; j--) {
            array[j] = array[j-1];
        }
        array[j] = temp;
    }
    return ;
}

/*
 ************************************************************************************************  
 * Function     : void quick_sort(int array[], int begin, int end)
 * Descriptions : quick sort;
 * Arguments    :
 * Returns      : None
 * Author       :
 * Date         : 2016-03-19
 ************************************************************************************************  
*/
void quick_sort(int array[], int begin, int end)
{
    int i = begin, j = end, temp = 0;

    if (begin >= end) 
        return ;
     
    temp = array[i];
    while (i<j) {
        while (array[j]>=temp && i<j) j--;
        array[i] = array[j];
        while (array[i]<=temp && i<j) i++;
        array[j] = array[i];
    }
    array[i] = temp;

    quick_sort(array, begin, i-1);
    quick_sort(array, i+1, end);

    return ;
}

/*
 ************************************************************************************************  
 * Function     : void merge_sort(int array[], int n)
 * Descriptions : merge sort;
 * Arguments    :
 * Returns      : None
 * Author       :
 * Date         : 2016-03-19
 ************************************************************************************************  
*/
void merge_sort(int array[], int n) 
{
    int i = 0, j = 0, k = 0, mid = 0;
    int *temp = NULL;

    if (n <= 1)
        return ;

    mid = n/2;
    merge_sort(array, mid);
    merge_sort(&array[mid], n-mid);
    
    j += mid;
    temp = malloc(n*sizeof(int));
    while (i<mid && j<n) temp[k++] = (array[i]<array[j]) ? array[i++] : array[j++]; 
    while (i < mid) temp[k++] = array[i++];
    while (j < n) temp[k++] = array[j++];
    for (i=0; i<n; i++) array[i] = temp[i];
    free(temp);

    return ;
}

/*
 ************************************************************************************************  
 * Function     : void heap_adjust(int array[], int begin, int end)
 * Descriptions : heap adjust;
 * Arguments    :
 * Returns      : None
 * Author       :
 * Date         : 2016-03-19
 ************************************************************************************************  
*/
void heap_adjust(int array[], int begin, int end)
{
    int i = 0, j = 0, temp = 0;

    for (i=begin; j<end; i=j) {
        j = 2*i+1;
        if (array[j]<array[j+1] && j<end-1) j++;
        if (array[i]<array[j] && j<end) {
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        } else break ;
    }

    return ;
}
/*
 ************************************************************************************************  
 * Function     : void heap_sort(int array[], int n)
 * Descriptions : heap sort;
 * Arguments    :
 * Returns      : None
 * Author       :
 * Date         : 2016-03-19
 ************************************************************************************************  
*/
void heap_sort(int array[], int n) 
{
    int i = 0, temp = 0;

    for (i=n/2; i>=0; i--) {
        heap_adjust(array, i, n);
    }
    for (i=n-1; i>0; i--) {
        temp = array[i];
        array[i] = array[0];  
        array[0] = temp;
        heap_adjust(array, 0, i);
    }

    return ;
}

/*
 ************************************************************************************************  
 * Function     : void shell_sort(int array[], int n)
 * Descriptions : shell sort;
 * Arguments    :
 * Returns      : None
 * Author       :
 * Date         : 2016-03-31
 ************************************************************************************************  
*/
void shell_sort(int array[], int n)
{
    int i=0, j=0, k=0, temp=0;

    for (i=n/2; i>0; i=i/2) {
       for (j=i; j<n; j=j+i) {
            temp = array[j];
            for (k=j; k>0 && array[k]<array[k-i]; k=k-i) {
                array[k] = array[k-i];
            }
            array[k] = temp;
       }
    }

    return ;
}
/*
 ************************************************************************************************  
 * Function     : void generate_array(int array[], int n)
 * Descriptions : generate int array;
 * Arguments    :
 * Returns      : None
 * Author       :
 * Date         : 2016-03-16
 ************************************************************************************************  
*/
void generate_array(int array[], int n)
{
    int i = 0;

    for (i=0; i<n; i++) {
        array[i] = random() % n;
    }
    
    return ;
}
/*
 ************************************************************************************************  
 * Function     : void print_array(int array[], int n)
 * Descriptions : print int array;
 * Arguments    :
 * Returns      : None
 * Author       :
 * Date         : 2016-03-16
 ************************************************************************************************  
*/
void print_array(int array[], int n)
{
    int i = 0;

    for (i=0; i<n; i++) {
        printf("%2d  ", array[i]);
        if ((0 == (i + 1) % SORT_DISPLAY_WIDTH) && (0 != i)) printf("\n");
    }
    printf("\r");

    return ;
}

