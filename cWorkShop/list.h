#ifndef __LIST_H__
#define __LIST_H__

typedef struct tag_list {
	struct tag_list *prev;
	struct tag_list *next;
}LIST_T, *LIST_P;

#define list_init(head) \
{ \
	head->prev = head;\
	head->next = head;\
}
	
#define offset_of(type, member) \
	(\
	     (unsigned int) (&((type *)0)->member) \
    ) 

#define container_of(ptr, type, member) \
   ({ \
        typeof(((type *)0)->member) *__mptr = ptr; \
        (type *)((char *)__mptr-offset_of(type, member)); \
	})

#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)

#define list_for_each_safe(pos, n, head, type, member) \
	for(pos=list_entry(head->next, type, member), \
		n=list_entry(pos->member.next, type, member); \
		&(pos->member) != head; \
		pos = n, \
		n=list_entry(pos->member.next, type, member)) 
			
static inline __list_add(struct tag_list *new_entry, struct tag_list *prev, struct tag_list *next) 
{ 
	prev->next = new_entry; 
	new_entry->prev = prev; 
	new_entry->next = next; 
	next->prev = new_entry; 
	return ;
}

static inline void __list_del(struct tag_list *prev, struct tag_list *next) 
{ 
	prev->next = next; 
	next->prev = prev; 
	return ;
}	     

static inline void list_add(struct tag_list *new_entry, struct tag_list *head)
{
    __list_add(new_entry, head, head->next);
	return ;
}

static inline void list_add_tail(struct tag_list *new_entry, struct tag_list *head)
{
    __list_add(new_entry, head->prev, head);
    return ;
}	

static inline void list_del(struct tag_list *entry)
{
    __list_del(entry->prev, entry->next);
	entry->prev = (void *)0;
	entry->next = (void *)0;
	return ;
}

#endif 
