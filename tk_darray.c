#include <stdlib.h> /* malloc, exit, size_t */
#include <string.h> /* memset */
#include "tk_container.h"

#define DEFAULT_CAPACITY 1

enum { /* Dynamic Array's header elements */
    DARRAY_CAPACITY,
    DARRAY_LENGTH,
    DARRAY_ITEM_SIZE,
    DARRAY_ELEMENT_COUNT,
};

void* tk_darray_create(size_t item_size)
{
    /*
Memory layout of darray:
size_t capacity = number of items that can be held.
size_t length = number of items that array currently has.
size_t item_size = the size of each items in bytes.
void * items
*/
    size_t header_size, array_size;
    size_t *new_array;
    
    header_size = DARRAY_ELEMENT_COUNT * sizeof(size_t);
    array_size = DEFAULT_CAPACITY * item_size;
    
    new_array = malloc(header_size + array_size);
    if (!new_array) exit(1);
    memset(new_array, 0, header_size + array_size);
    
    new_array[DARRAY_CAPACITY] = DEFAULT_CAPACITY;
    new_array[DARRAY_LENGTH] = 0;
    new_array[DARRAY_ITEM_SIZE] = item_size;
    
    /* returns the address where user can actually store data */
    return (void*)(new_array + DARRAY_ELEMENT_COUNT);
}
