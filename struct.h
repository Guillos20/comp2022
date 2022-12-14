#ifndef STRUCT_H
#define STRUCT_H

typedef struct Node
{
    char *token;
    char *value;
    struct Node *son;
    struct Node *sibling;
    char * type;
    int line;
    int column;
} Node;

typedef struct Table//para identificar as tabelas
{
    char *id;//nome do metodo/classe
    int type;// se é class ou metodo; 1 para class 2 para método
    struct type *tipo;//para os tipos dos metodos; NUll para a class
    struct Table *next;
    struct Table_ent *entry;// para identificar o que esta dentro de uma tabela 
} Table;

typedef struct Table_ent
{
    char *ret;// tipo de return para quando existe -> em funçoes, tambem para quando temos sempre apenas um tipo, tipo variaveis 
    char *id;//nome da funçao na class ou nome da variavel no metodo
    struct type *tipo;//mais que um type para class pelo menos, no metodo ade ser apenas 1-> ai usas-se o return
    int isParam; // caso no metodo seje param para adicionar á frente: 0 se for 1 se nao for 
    
    struct Table_ent *next;
}Table_ent;

typedef struct type
{
    char *tipo;
    struct type *next;

}type;
typedef struct erro
{
    char * error_message;
    struct erro *next;
}erro;


typedef enum {integer, string, doub, boolean, undef} basic_type;

Node *root;
Node *createNode(char *token, char *value, Node *son, Node *sibling);


Node *createNode2(char *token, char *value, Node *son, Node *sibling, int col);





Node *add_sibling(Node * someone, Node * sibling);
Node *add_son(Node * parent, Node * son);
void save_type(Node *first, Node *type);


void print_tree(Node *node, int num);
void print_anotated_tree(Node *node, int num);
void anotate_that_tree(Node *node);
char *get_type_entry(char *id, Table *tab, char *func);
type *get_type_func(char *id, Table *tab, type *t);
int compare_tree_params(type* params, type * p);


Table *createTable(char* id, int typical, struct type *t, struct Table *next, struct Table_ent *entry);
Table_ent *insertEntry(char *ret, struct type *t, char *id, int isParam , struct Table_ent *next);
type *createType(char* tipo, type *next);

#endif // STRUCT_H