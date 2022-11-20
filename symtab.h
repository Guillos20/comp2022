#ifndef SYMTAB_H
#define SYMTAB_H


typedef enum {integer, string, doub, boolean, undef} basic_type;

typedef struct symtab
{
    char token[256];
    basic_type type;
    struct symtab *next;
}table;


#endif