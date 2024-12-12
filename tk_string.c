#include <string.h>
#include <stdlib.h>

#include "tk_string.h"

/* 
WARNING: Using malloc, make sure to free in the client code.
Take a string as a parameter, find the string passed in the parameter, replace the substring with the string given.
    Return 0 on errors;
*/
char* tkstr_replace(char *src, char *find, char *replace_with)
{
    char *result;         /* result string to return */
    char *insert_point;   /* next insert point */
    char *tmp;
    int len_find;         /* length of the string to find */
    int len_replace_with; /* length of the string to replace */
    int len_front;        /* distance between "find" and end of last "replace_with" */
    int count;            /* number of replacements */
    
    /* sanity checks and initializations */
    if(!src || !find) 
        return 0;
    
    len_find = strlen(find);
    if (len_find == 0) 
        return 0; /* avoiding infinit loop */
    
    if (!replace_with) 
        replace_with = "";
    
    len_replace_with = strlen(replace_with);
    
    insert_point = src;
    
    /* Count the number of replacements needed */
    for (count = 0; (tmp = strstr(insert_point, find)); count++)
    {
        insert_point = tmp + len_find;
    }
    
    /* Allocate memory for the new string */
    result = tmp = malloc(strlen(src) + (len_replace_with - len_find) * count - 1);
    
    if (!result) 
        return 0;
    
    while(count--){
        insert_point = strstr(src, find); 
        len_front = insert_point - src;
        tmp = strncpy(tmp, src, len_front) + len_front; 
        tmp = strcpy(tmp, replace_with) + len_replace_with;
        src += len_front + len_find;  
    }
    
    strcpy(tmp, src); 
    
    return result;
}
