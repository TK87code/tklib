#include <stdlib.h>
#include "tk_list.h"

tk_node_t* tk_list_create(void* data){
    tk_node_t *node;
    
    node = malloc(sizeof(tk_node_t));
    if(!node){
        return NULL;
    }
    
    node->data = data;
    node->next = NULL;
    
    return node;
}

void tk_list_delete(tk_node_t *list)
{
    tk_node_t *current;
    tk_node_t *next;
    current = list;
    
    do{
        next = current->next;
        free(current);
        current = next;
    }while (current != NULL);
}

tk_node_t* tk_list_push_front(tk_node_t *list, void *data)
{
    tk_node_t *node = malloc(sizeof(tk_node_t));
    if(!node){
        return NULL; 
    }
    
    node->data = data;
    node->next = list;
    
    return node;
}

tk_node_t* tk_list_pop_front(tk_node_t *list)
{
    tk_node_t *node = list->next;
    free(list);
    return node;
}

int tk_list_push_back(tk_node_t *list, void* data)
{
    tk_node_t *new_node;
    tk_node_t *back_node;
    
    new_node = malloc(sizeof(tk_node_t));
    if (!new_node){
        return -1;
    }
    
    new_node->data = data;
    new_node->next = NULL;
    
    back_node = tk_list_get_back(list); 
    
    back_node->next = new_node;
    
    return 0;
}

void tk_list_pop_back(tk_node_t *list)
{
    tk_node_t *back_node;
    tk_node_t *current;
    
    back_node = tk_list_get_back(list);
    
    current = list;
    while (current->next != back_node)
        current = current->next;
    
    free(back_node);
    current->next = NULL;
}

tk_node_t* tk_list_get_back(tk_node_t *list)
{
    tk_node_t *current;
    current = list;
    while (current->next != NULL){
        current = current->next;
    }
    
    return current;
}