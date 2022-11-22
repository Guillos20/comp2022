#include "symtab.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "struct.h"

Table *symtab;

void initTable(Node *node)
{
    char *params[8] = {"yes"};
    char *name = node->son->value;
    // printf("===== Class %s Symbol Table =====\n", name);
    symtab = createTable(name, 1, params,NULL, NULL);
    node = node->son->sibling;
    while (node != NULL)
    { // percorre metodo a metodo ou field decl
        if (strcmp(node->token, "MethodDecl") == 0)
        {
            if (strcmp(node->son->token, "MethodHeader") == 0)
            {
                create_entry_Class_Table(node, symtab);
            }
        }if(strcmp(node->token,"FieldDecl") == 0){
            create_entry_Class_Table(node,symtab);
        }
        node = node->sibling;
    }
}

// table ent tem type[8], id, se é parametro, e o next ent

Table_ent *create_entry_Class_Table(Node *node, Table *global_table)
{ // este nó será o method decl ou field decl
 Table_ent *entry;
 char *typeAux[8];
 int count = 0;
    if (strcmp(node->token, "MethodDecl") == 0)
    {
        char *tipo = typeChange(node->son->son->token);
        char *id = node->son->son->sibling->value;
        Node *aux = node->son->son->sibling->sibling->son; // ParamDecl
        // printf("%s\n", aux->token);
        if (aux != NULL)
        { // se o methodParams tem filhos
            for (Node *filho = aux; filho; filho = aux->sibling)
            { // percorre os paramDecl
                char *t = malloc(256);
                t = typeChange(filho->son->token);
                typeAux[count] = t;
                count++;
            }
        }
        entry = insertEntry(tipo,typeAux, id, 1, NULL);
        //printf("%s", entry->id);
        count = 0;
        bzero(typeAux,sizeof(typeAux));
    }
    if (strcmp(node->token, "FieldDecl") == 0)
    {   
        char *t = malloc(256);
        t = typeChange(node->son->token);
        typeAux[count] = t;
        char *id = node->son->sibling->value;
        entry = insertEntry(NULL,typeAux,id,1,NULL);
        bzero(typeAux,sizeof(typeAux));
    }
    if (global_table->entry == NULL)
    {
        global_table->entry = entry;
    }
    else
    {
        Table_ent *entry_aux =global_table->entry;
        while (entry_aux != NULL){
            // printf("%s\n", entry_aux->id);
            entry_aux = entry_aux->next;
        }
        entry_aux = entry;
                    // printf("%s depois\n", entry_aux->id);

    }
}

char *typeChange(char *aux)
{
    if (strcmp(aux, "StringArray") == 0)
    {
        return "String[]";
    }
    if (strcmp(aux, "Int") == 0)
    {
        return "int";
    }
    if (strcmp(aux, "Bool") == 0)
    {
        return "boolean";
    }
    if (strcmp(aux, "Void") == 0)
    {
        return "void";
    }
    if (strcmp(aux, "Double") == 0)
    {
        return "double";
    }
}

void print_Table(Table *start){
    Table *aux = start;
    while(aux!=NULL){
        if(aux->type == 1){
            char* name = aux->id;
            printf("===== Class %s Symbol Table =====\n", name);
            print_Entrys(aux);
            //printf("sai lololololol\n");
        }
        if(aux->type == 2){
            printf("===== Method %s(",aux->id);
            for(int i = 0; i< sizeof(aux->t);i++){
                if(i=(sizeof(aux->t)-1)){
                    printf("%s) Symbol Table =====\n", aux->t[i]);
                }else{
                printf("%s,", aux->t[i]);
                 }
            }
            print_Entrys(aux);
        }
        aux = aux->next;
    }
}


void print_Entrys(Table *tab){
    //printf("entrei lololololl\n");
    Table_ent *entry = tab->entry;
    while(entry!=NULL){
    printf("%s\t(", entry->id);
    // while(tab->typ[i]){
        printf("%s", entry->typ[0]);
    //     i++;
    // }
    printf(")\t%s\n\n", entry->ret);

    entry = entry->next;
}
return;
}//printar as entrys dependendo se é class ou metodo