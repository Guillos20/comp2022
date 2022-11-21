#ifndef SYMTAB_H
#define SYMTAB_H

#include "struct.h"


typedef struct symtab
{
    char token[256];
    struct symtab *next;
}table;

void initTable(Node *node);
char* typeChange(char* aux);
Table_ent *create_entry_Class_Table(Node * node, Table *global_table);

#endif