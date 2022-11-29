#ifndef SYMTAB_H
#define SYMTAB_H

#include "struct.h"

extern Table *symtab;

typedef struct symtab
{
    char token[256];
    struct symtab *next;
}table;

void initTable(Node *node);
char* typeChange(char* aux);
Table_ent *create_entry_Class_Table(Node * node, Table *global_table);
void print_Table(Table *start);
void print_Entrys(Table *tab);
type *CreateType_List(Node *cabeca);
Table_ent *create_entry_Method_Table(Node *node, Table *global_table);
int Compare_Lists(type *t, char *tipo);
type * addToList(type *list, char * t);
int compare_params(type* param, type* p);
int compare_methods(Table_ent * list, type *param,char * id);
Table_ent * addToListEntry(Table_ent * list ,char* ret, char* id, type *tipo, int isParam, Table_ent *next);


#endif