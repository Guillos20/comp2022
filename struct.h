#ifndef STRUCT_H
#define STRUCT_H

typedef struct Node
{
    char *token;
    char *value;
    struct Node *son;
    struct Node *sibling;
} Node;

Node *root;

void print_tree(Node *node, int num);

Node *createNode(char *token, char *value, Node *son, Node *sibling);
void print_tree(Node *root, int num);
void save_type(Node *first, Node *type);
Node *add_sibling(Node * someone, Node * sibling);
Node *add_son(Node * parent, Node * son);

#endif // STRUCT_H