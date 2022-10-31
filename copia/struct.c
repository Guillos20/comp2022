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
    return n;
}

void print_tree(Node *node, int num)
{
    if (node == NULL){
        return;
    }
    for (int i = 0; i < num; i++){
        printf("..");
    }
    if (node->value != NULL){
        printf("%s(%s)\n", node->token, node->value);    
        }else{
            
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
};