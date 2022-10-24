#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"



Node *create_node(char *token, char *value){
    Node *n = (Node *)malloc(sizeof(Node));
    n -> son = NULL;
    n -> sibling = NULL;
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