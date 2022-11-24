#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

Node *createNode(char *token, char *value, Node *son, Node *sibling)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->token = token;
    n->value = value;
    n->son = son;
    n->sibling = sibling;
    n->type = NULL;
    return n;
}

Table *createTable(char *id, int typical, struct type *t, struct Table *next, struct Table_ent *entry)
{
    Table *table = malloc(sizeof(Table));
    /*if (table == NULL){
        return NULL;}
    */
    table->id = id;
    table->type = typical;
    // printf("%ld\n",sizeof(*params));
    table->tipo = t;
    table->next = next;
    table->entry = entry;
    return table;
}

Table_ent *insertEntry(char *ret, struct type *t, char *id, int isParam, struct Table_ent *next)
{
    Table_ent *ent = malloc(sizeof(Table_ent));
    ent->ret = ret;
    ent->id = id;
    ent->isParam = isParam;
    ent->next = next;
    // for (int i = 0; i < sizeof(*type); i++)
    // {
    //     //ent->typ[i] = type[i];
    // }
    ent->tipo = t;
    return ent;
}

type *createType(char *tipo, type * next){
    type *t = malloc(sizeof(type));
    t->tipo = tipo;
    t->next = next;
    return t;
}

void save_type(Node *first, Node *type)
{
    Node *aux = first->sibling;
    Node *temp;
    while (aux)
    {
        Node *newtype = createNode(type->token, type->value, NULL, NULL);
        temp = aux->son;
        aux->son = newtype;
        aux->son->sibling = temp;
        aux = aux->sibling;
    }
}
Node *add_sibling(Node *someone, Node *sibling)
{

    if (sibling == NULL)
    {
        return NULL;
    }
    Node *aux = (Node *)(malloc)(sizeof(Node));
    Node *old = (Node *)(malloc)(sizeof(Node));
    old = someone;
    aux = someone->sibling;
    while (aux != NULL)
    {
        old = aux;
        aux = aux->sibling;
    }

    old->sibling = (Node *)(malloc)(sizeof(Node));

    old->sibling = sibling;

    return someone;
}
Node *add_son(Node *parent, Node *son)
{
    // if given son is NULL well that's about it
    if (son == NULL)
    {
        return NULL;
    }
    // if son exists but is empty we add it
    if (parent->son == NULL)
    {
        parent->son = (Node *)(malloc)(sizeof(Node));
        parent->son = son;
    }
    // if the son already exists checks every son of given parent until there is a son that has no sibling
    //  then adds the node 'son' to the empty node
    else
    {
        Node *aux = (Node *)(malloc)(sizeof(Node));
        Node *old = (Node *)(malloc)(sizeof(Node));
        old = parent->son;
        aux = parent->son->sibling;

        while (aux != NULL)
        {
            old = aux;
            aux = aux->sibling;
        }

        old->sibling = (Node *)(malloc)(sizeof(Node));
        old->sibling = son;
    }
    // printf("Child %s added to parent %s\n", son->token, parent->token);
    return parent;
}
void print_tree(Node *node, int num)
{
    if (node == NULL)
    {
        return;
    }
    for (int i = 0; i < num; i++)
    {
        printf("..");
    }
    if (node->value != NULL)
    {
        printf("%s(%s)\n", node->token, node->value);
    }
    else
    {

        printf("%s\n", node->token);
    }

    if (node->son != NULL)
    {
        print_tree(node->son, num + 1);
    }

    if (node->sibling != NULL)
    {
        print_tree(node->sibling, num);
    }
}
void print_anotated_tree(Node *node, int num){

};