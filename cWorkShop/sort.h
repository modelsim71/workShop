#ifndef __SORT_H__
#define __SORT_H__

/*************************************************************************
 *                             宏  定  义 
 *************************************************************************/
#define SORT_ARRAY_LEN      64
#define SORT_DISPLAY_WIDTH  32 

/*************************************************************************
 *                             函 数 声 明 
 *************************************************************************/
extern void generate_array(int array[], int n);
extern void print_array(int array[], int n);
extern void bubble_sort(int array[], int n);
#endif


