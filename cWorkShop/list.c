#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

#define TEST_MAX_NUM  8

typedef struct tag_test_node {
    int       data;
    LIST_T    link;
}TEST_NODE_T, *TEST_NODE_P;

int    test_data[TEST_MAX_NUM] = {1, 17, 14, 15, 165, -1, 17, 4};
LIST_T head;

static void init_list(LIST_P head)
{
    list_init(head);
    return ;
}

static int add_list(LIST_P head, int data)
{
    int has_insert = 0;
    TEST_NODE_P p_node = NULL;
    TEST_NODE_P pos = NULL, temp = NULL;

    p_node = malloc(sizeof(TEST_NODE_T));
    if (NULL == p_node) {
        return -1;
    }
    memset(p_node, 0, sizeof(TEST_NODE_T));
    p_node->data = data;
    init_list(&p_node->link);

    list_for_each_safe(pos, temp, head, TEST_NODE_T, link)
    {
        if (pos->data < data)
        {
            has_insert = 1;		
            list_add_tail(&p_node->link, &pos->link);
            break ;
        }
    }

    if (0 == has_insert)
    {
        list_add_tail(&p_node->link, head);
    }
    return 0;
}

static void delete_list(LIST_P head, int data)
{
    TEST_NODE_P p_node = NULL;
    TEST_NODE_P pos = NULL, temp = NULL;

    list_for_each_safe(pos, temp, head, TEST_NODE_T, link)
    {
        if (pos->data == data)
        {
            list_del(&pos->link);
            free(pos);
        }
    }
    return ;
}

static void print_list(LIST_P head)
{
    int  i = 0;
    TEST_NODE_P pos = NULL, temp = NULL;

    list_for_each_safe(pos, temp, head, TEST_NODE_T, link)
    {
        printf("%d:%d ", i, pos->data);
        i++;
    }
    printf("\n=============== list content =============\n");	

    return ;
}

int main(int argc, char **argv)
{
    int i = 0;

    init_list(&head);

    printf("start to insert list nodes!");

    for (i = 0; i < TEST_MAX_NUM; i++) 
    {	
        add_list(&head, test_data[i]);
    }	

    print_list(&head);

    printf("\nstart to delete list nodes 17!");

    delete_list(&head, 17);

    print_list(&head);

    return 0;
}

