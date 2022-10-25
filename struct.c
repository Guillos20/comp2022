#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"



Node *create_node(char *token, char *value, struct node *son,struct node *sibling){
    struct Node *n = (Node *)malloc(sizeof(Node));
    n -> son = son;
    n -> sibling = sibling;
    n -> token = token;
    n -> value = value;
    
    return n;
}
void print_tree(Node *node, int num)
{
    if (root == NULL){
        return;
    }
    for( int i = 0; i< num; i++){
        printf("..");
    }
    

}