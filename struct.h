#ifndef STRUCT_H
#define STRUCT_H

typedef struct Node{
    char *token;
    char *value;
    char *type;
    struct Node *son;
    struct Node *sibling;
}Node;

Node *root;

void print_tree(Node *node, int num);

#endif //STRUCT_H