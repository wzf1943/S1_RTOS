#ifndef LIST_H_INCLUDE
#define LIST_H_INCLUDE

#include <stddef.h>
// #include <compiler.h>

typedef struct list{
    struct list *next;
    struct list *prev;
} list_t;

#define INIT_LIST(list) { \
    .next = &(list),      \
    .prev = &(list)       \
}

static inline void list_init(struct list*list){
    list -> next = list;
    list -> prev = list;
}

/*#define DEFINE_LIST(name)\
 *  struct list name = INIT_LIST(name);
 * ...
 * ...
 * ...
 * ...
 * ...
 * ...
 */

static inline struct list* list_tail(struct list* head){
    return head -> prev;
}

static inline void list_insert(struct list* new, struct list *before,
        struct list *after){
    before ->next = new;
    new -> prev = before;
    new -> next = after;
    after -> prev = new;
}

static inline struct list *list_pop_tail(struct list* head){
    struct list *tail = list_tail(head);
    list_remove(tail);
    return tail;
}

static inline struct list* list_pop_head( struct list *head){
    struct list *element = head -> next;
    list_remove(element);
    return element;
}

static inline void list_insert_before(sturct list* item, sturct list* insert_point){
    list_insert(item, insert_point-> prev, insert_point);
}

static inline void list_insert_after(struct list *item, struct list *insert_point){
    list_insert(item, insert_point, insert_point-> next);
}

static inline void list_add_head(struct list *new, struct list*head){
    list_insert(new, head, head -> next);
}

static inline void list_add_tail(struct list *new, struct list *head){
    list_insert(new, head -> prev, head);
}

#define list_add list_add_head

static inline void list_remove(struct list *element){
    struct list *before = element -> prev;
    struct list *after = element -> next;

    before -> next = after;
    after -> prev = before;
}

static inline struct list *list_pop_tail(struct list* head){
    struct list *tail = list_tail(head);
    list_remove(tail);
    return tail;
}

static inline struct list* list_pop_head( struct list *head){
    struct list *element = head -> next;
    list_remove(element);
    return element;
}

#define list_pop(h) list_pop_tail(h)

#define list_for_each(curr, head) \
    for(curr = (head)->next; curr != (head); curr = curr->next)

#define list_for_each_entry(curr, head, member) \
    for( curr = container_of((head) -> next, typedof(*curr), member);\
                &curr -> member != (head);                          \
                curr = container_of(curr -> member.next, tyeof(*curr), member))
#endif



