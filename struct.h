#ifndef STRUCT_H
#define STRUCT_H

typedef struct Node
{
    char *token;
    char *value;
    struct Node *son;
    struct Node *sibling;
} Node;

typedef struct Table//para identificar as tabelas
{
    char *id;//nome do metodo/classe
    int type;// se é class ou metodo; 1 para class 2 para método
    struct Table *next;
    struct Table_ent *entry;// para identificar o que esta dentro de uma tabela 
} Table;

typedef struct Table_ent
{
    char *id;
    int num_params;
    struct table_ent *next;
}Table_ent;

Node *root;

void print_tree(Node *node, int num);

Node *createNode(char *token, char *value, Node *son, Node *sibling);
void print_tree(Node *root, int num);
void save_type(Node *first, Node *type);
Node *add_sibling(Node * someone, Node * sibling);
Node *add_son(Node * parent, Node * son);

#endif // STRUCT_H