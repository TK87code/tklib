/* date = December 4th 2024 7:11 pm */

#ifndef TK_LIST_H
#define TK_LIST_H

#ifndef NULL
#define NULL 0
#endif //NULL

typedef struct tk_node_t{
    void *data;
    void *next;
}tk_node_t;

extern tk_node_t* tk_list_create(void *data);
extern void tk_list_delete(tk_node_t *list);

extern tk_node_t* tk_list_push_front(tk_node_t *list, void *data);
extern tk_node_t* tk_list_pop_front(tk_node_t *list);

extern int tk_list_push_back(tk_node_t *list, void* data);
extern void tk_list_pop_back(tk_node_t *list);
extern tk_node_t* tk_list_get_back(tk_node_t *list);


#endif //TK_LIST_H
