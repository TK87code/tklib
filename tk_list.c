#include <stdlib.h> /* malloc(), exit()*/
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

int tk_list_push_front(tk_node_t **list, void *data)
{
    tk_node_t *node = malloc(sizeof(tk_node_t));
    if(!node){
        return -1;
    }
    
    node->data = data;
    node->next = *list;
    
    *list = node;
    
    return 0;
}

void tk_list_pop_front(tk_node_t **list)
{
    tk_node_t *tmp = *(list);
    free(*list);
    *list = tmp->next;
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
    tk_node_t *current;
    
    current = list;
    while (current->next->next != NULL)
        current = current->next;
    
    free(current->next);
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
/*
tk_node_t* tk_list_find(tk_list_t *list, void *data)
{
    
}

int tl_list_insert_after(tk_list_t **list, void* data_to_insert, tk_list_t node_to_find)
{
    
}
*/