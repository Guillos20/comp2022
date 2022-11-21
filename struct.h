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
    char *id;//nome da funçao na class ou nome da variavel no metodo
    char *typ[8];//mais que um type para class pelo menos, no metodo ade ser apenas 1 
    int isParam; // caso no metodo seje param para adicionar á frente: 0 se for 1 se nao for 
    
    struct Table_ent *next;
}Table_ent;

typedef enum {integer, string, doub, boolean, undef} basic_type;

Node *root;

void print_tree(Node *node, int num);

Node *createNode(char *token, char *value, Node *son, Node *sibling);
void print_tree(Node *root, int num);
void save_type(Node *first, Node *type);
Node *add_sibling(Node * someone, Node * sibling);
Node *add_son(Node * parent, Node * son);
Table *createTable(char* id, int type, struct Table *next, struct Table_ent *entry);
Table_ent *insertEntry(char *type[8], char *id, int isParam , struct Table_ent *next);

#endif // STRUCT_H