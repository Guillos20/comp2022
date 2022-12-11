#include "symtab.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "struct.h"
#include <ctype.h>
// variaveis dentro de funçao com nomes iguais
Table *symtab;

void initTable(Node *node)
{

    char *name = node->son->value;
    // printf("===== Class %s Symbol Table =====\n", name);
    symtab = createTable(name, 1, NULL, NULL, NULL);
    Table *aux = symtab;
    Table_ent *correct_Methods = NULL;
    node = node->son->sibling;
    type *typ_aux = NULL;
    create_entry_Class_Table(node, symtab);
    // printf("vens aqui ?  \n");
    while (node != NULL)
    { // percorre metodo a metodo ou field decl
        if (strcmp(node->token, "MethodDecl") == 0)
        {
            if (strcmp(node->son->token, "MethodHeader") == 0) // podemos vir a poder tirar isto uma vez que aparece sempre ,acho
            {
                aux = symtab;
                char *id = node->son->son->sibling->value;
                typ_aux = CreateType_List(node->son->son->sibling->sibling->son);
                if (aux->next == NULL)
                {
                    if (compare_methods(correct_Methods, typ_aux, id) == 1)
                    {
                        // printf("guillos %s  \n",id);
                        aux->next = createTable(node->son->son->sibling->value, 2, typ_aux, NULL, NULL);
                        create_entry_Method_Table(node, aux->next); // o node aqui vai ser igual ao de cima
                        correct_Methods = addToListEntry(correct_Methods, NULL, id, typ_aux, 0, NULL);
                    }
                    else
                    {
                        // printf("YEET%s already defined \n",id);
                    }
                }
                else
                {
                    aux = aux->next;
                    while (aux->next)
                    {
                        aux = aux->next;
                    }
                    // verificar metodo
                    if (compare_methods(correct_Methods, typ_aux, id) == 1)
                    {
                        // printf("guillos1 %s  \n",id);
                        aux->next = createTable(node->son->son->sibling->value, 2, typ_aux, NULL, NULL);
                        create_entry_Method_Table(node, aux->next); // o node aqui vai ser igual ao de cima
                        correct_Methods = addToListEntry(correct_Methods, NULL, id, typ_aux, 0, NULL);
                    }
                    // printf("%s depois\n", aux->id);
                }
            }
        }

        node = node->sibling;
    }
}

// table ent tem type[8], id, se é parametro, e o next ent

Table_ent *create_entry_Class_Table(Node *node, Table *global_table)
{ // este nó será o method decl ou field decl
    Table_ent *entry;
    type *temp = createType("_", NULL);
    type *parametros = NULL;
    Table_ent *ret_Entry = NULL;
    int count = 0;
    while (node != NULL)
    {
        if (strcmp(node->token, "MethodDecl") == 0)
        {

            Node *paramdecl = node->son->son->sibling->sibling->son; // paramDecl
            parametros = CreateType_List(paramdecl);
            char *tipo = typeChange(node->son->son->token);
            char *id = node->son->son->sibling->value;
            if (compare_methods(ret_Entry, parametros, id) == 1)
            {
                entry = insertEntry(tipo, parametros, id, 0, NULL);

                if (global_table->entry == NULL)
                {

                    global_table->entry = entry;
                }
                else
                {

                    Table_ent *entry_aux = global_table->entry;
                    while (entry_aux->next)
                    {
                        entry_aux = entry_aux->next;
                    }
                    entry_aux->next = entry;
                }
                ret_Entry = addToListEntry(ret_Entry, tipo, id, parametros, 0, NULL);
            }
            else
            {
               // printf("Line %d, col %d: Symbol %s already defined\n", node->son->son->sibling->line, node->son->son->sibling->column, id);
            }
        }
        if (strcmp(node->token, "FieldDecl") == 0)
        {

            char *id = node->son->sibling->value;
            if (Compare_Lists(temp, id) == 1)
            {
                temp = addToList(temp, id);
                parametros = CreateType_List(node);
                entry = insertEntry(NULL, parametros, id, 1, NULL);

                if (global_table->entry == NULL)
                {
                    global_table->entry = entry;
                }
                else
                {
                    Table_ent *entry_aux = global_table->entry;
                    while (entry_aux->next)
                    {
                        entry_aux = entry_aux->next;
                    }
                    entry_aux->next = entry;
                }
            }
            else if(strcmp(id,"_")==0){
                    printf("Line %d, col %d: Symbol %s is reserved\n", node->son->sibling->line, node->son->sibling->column -1, id);

            }else
            {
                printf("Line %d, col %d: Symbol %s already defined\n", node->son->sibling->line, node->son->sibling->column, id);
            }
        }

        node = node->sibling;
    }
}

Table_ent *create_entry_Method_Table(Node *node, Table *global_table)
{ // node vai ser method decl ou field decl
    Table_ent *entry;
    type *parametros = NULL;
    type *id_list = createType("_", NULL);
    int count = 0;
    if (strcmp(node->token, "MethodDecl") == 0)
    {
        Node *methodBody = node->son->sibling;
        char *ret = typeChange(node->son->son->token);
        char *id = "return";
        entry = insertEntry(ret, NULL, id, 1, NULL);
        global_table->entry = entry;
        Node *aux = node->son->son->sibling->sibling; // MethodParams
        type *vars1 = NULL;
        if (aux->son)
        {
            aux = aux->son;
            while (aux)
            {
                id = aux->son->sibling->value;
                if (Compare_Lists(id_list, id) == 1)
                {
                    ret = typeChange(aux->son->token);
                    entry->next = insertEntry(ret, NULL, id, 0, NULL);
                    entry = entry->next;
                    id_list = addToList(id_list, id);
                }
                else if (strcmp(id, "_") == 0)
                {
                    //is kinda correct
                    
                    //printf("Line %d, col %d: Symbol %s is reserved\n", aux->son->sibling->line, aux->son->sibling->column - 1, id);
                }
                else
                {
                    printf("Line %d, col %d: Symbol %s already defined\n", aux->son->sibling->line, aux->son->sibling->column, id);
                }

                aux = aux->sibling;
            }
        }
        if (methodBody->son)
        {
            Node *aux1 = methodBody->son;
            type *vars = NULL;
            while (aux1)
            {
                if (strcmp(aux1->token, "VarDecl") == 0)
                {
                    ret = typeChange(aux1->son->token);
                    id = aux1->son->sibling->value;

                    if (Compare_Lists(id_list, id) == 1)
                    {
                        entry->next = insertEntry(ret, NULL, id, 1, NULL);
                        entry = entry->next;
                        id_list = addToList(id_list, id);
                    }
                    else if (strcmp(id, "_") == 0)
                    {
                        //printf("Line %d, col %d: Symbol %s is reserved\n", aux1->son->sibling->line, aux1->son->sibling->column, id);
                    }
                    else
                    {
                        //printf("Line %d, col %d: Symbol %s already defined\n", aux1->son->sibling->line, aux1->son->sibling->column, id);
                    }
                }
                aux1 = aux1->sibling;
            }
        }
    }
}

int compare_methods(Table_ent *list, type *param, char *id)
{
    if (list == NULL)
    {
        return 1; // esta tudo correto
    }
    else
    {
        Table_ent *aux = list;
        while (aux)
        {
            if ((strcmp(id, aux->id) == 0 && compare_params(aux->tipo, param) == 0) || strcmp(id, "_") == 0)
            {

                return 0; // ignorar aquele metodo
            }

            aux = aux->next;
        }
        return 1; // esta correto
    }
}

int compare_params(type *param, type *p)
{
    if (param == NULL || p == NULL)
    {
        return 1; // tudo correto
    }
    else
    {
        int count = 0;
        type *aux = param;
        type *aux1 = p;
        while (aux && aux1)
        {
            if (strcmp(aux->tipo, aux1->tipo) != 0)
            {
                return 1; // tudo correto
            }
            if (aux->next == NULL && aux1->next == NULL && strcmp(aux->tipo, aux1->tipo) == 0)
            {
                return 0; // errado
            }
            aux = aux->next;
            aux1 = aux1->next;
        }
        return 1; // tudo correto
    }
}

int List_check(type *list)
{ // adicionar a lista de ids

    if (list == NULL)
    {
        return 1; // nao há repetidos
    }
    else
    {
        type *aux = list;
        while (aux->next != NULL)
        {
            type *aux1 = aux->next;
            while (aux1 != NULL)
            {
                if (strcmp(aux->tipo, aux1->tipo) == 0)
                {
                    return 0; // existe repetidos
                }
                aux1 = aux1->next;
            }
            aux = aux->next;
        }
        return 1; // nao há repetidos
    }
}

int Compare_Lists(type *t, char *tipo)
{
    if (t == NULL)
    {
        return 1; // nao existe;
    }
    else
    {
        type *aux = t;
        while (aux->next != NULL)
        {
            if (strcmp(aux->tipo, tipo) == 0)
            {
                return 0; // já existe
            }
            aux = aux->next;
        }
        if (strcmp(aux->tipo, tipo) == 0)
        {
            return 0; // já existe
        }
        else
        {
            return 1; // nao existe ;
        }
    }
}

type *addToList(type *list, char *t)
{
    type *head = list;
    type *aux = NULL;
    if (head == NULL)
    {
        head = createType(t, NULL);
    }
    else
    {
        aux = head;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = createType(t, NULL);
    }
    return head;
}

Table_ent *addToListEntry(Table_ent *list, char *ret, char *id, type *tipo, int isParam, Table_ent *next)
{
    Table_ent *head = list;
    Table_ent *aux = NULL;
    if (head == NULL)
    {
        head = insertEntry(ret, tipo, id, isParam, next);
    }
    else
    {
        aux = head;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = insertEntry(ret, tipo, id, isParam, next);
    }
    return head;
}

type *CreateId_List(Node *cabeca)
{
    // int count = 0;
    type *head = NULL;
    type *type_aux1 = NULL;
    if (cabeca != NULL) // ParamDecl
    {
        if (strcmp(cabeca->token, "ParamDecl") == 0)
        { // se o methodParams tem filhos
            for (Node *filho = cabeca; filho != NULL; filho = filho->sibling)
            { // percorre os paramDecl ou o field
              // count ++;
                char *t = filho->son->sibling->value;
                if (head == NULL)
                {
                    head = createType(t, NULL);
                }
                else
                {
                    type_aux1 = head;
                    while (type_aux1->next != NULL)
                    {
                        type_aux1 = type_aux1->next;
                    }
                    type_aux1->next = createType(t, NULL);
                }
            }
        }
    }
    return head;
}

type *CreateType_List(Node *cabeca)
{
    // int count = 0;
    type *head = NULL;
    type *type_aux1 = NULL;
    if (cabeca != NULL) // ParamDecl
    {
        if (strcmp(cabeca->token, "ParamDecl") == 0)
        { // se o methodParams tem filhos
            for (Node *filho = cabeca; filho != NULL; filho = filho->sibling)
            { // percorre os paramDecl ou o field
              // count ++;
                char *t = typeChange(filho->son->token);
                if (head == NULL)
                {
                    head = createType(t, NULL);
                }
                else
                {
                    type_aux1 = head;
                    while (type_aux1->next != NULL)
                    {
                        type_aux1 = type_aux1->next;
                    }
                    type_aux1->next = createType(t, NULL);
                }
            }
        }
        if (strcmp(cabeca->token, "FieldDecl") == 0)
        {
            char *t = typeChange(cabeca->son->token);
            head = createType(t, NULL);
        }
    }
    return head;
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

void print_Table(Table *start)
{
    Table *aux = start;
    while (aux)
    {
        if (aux->type == 1)
        {
            char *name = aux->id;
            printf("===== Class %s Symbol Table =====\n", name);
            print_Entrys(aux);
        }
        if (aux->type == 2)
        {

            printf("===== Method %s(", aux->id);
            if (aux->tipo)
            {
                type *t_aux = aux->tipo;
                while (t_aux->tipo && t_aux->next != NULL)
                {
                    printf("%s,", t_aux->tipo);
                    t_aux = t_aux->next;
                    // printf("%s porrada \n",entry->typ[i+1]);
                }
                if (t_aux->tipo)
                {
                    printf("%s) Symbol Table =====\n", t_aux->tipo);
                }
                else
                {
                    printf(") Symbol Table =====\n");
                }
            }
            else
            {
                printf(") Symbol Table =====\n");
            }
            print_Entrys(aux);
        }
        aux = aux->next;
    }
}

void print_Entrys(Table *tab)
{
    Table_ent *entry = tab->entry;
    if (tab->type == 1)
    {
        while (entry != NULL)
        {
            printf("%s\t", entry->id); // print ID
            if (entry->isParam == 1)
            {
                printf("\t%s", entry->tipo->tipo);
                // printf("guilherme\n");
            }
            if (entry->isParam == 0)
            {

                int i = 0;
                printf("(");
                type *t_aux = entry->tipo;
                if (t_aux)
                {
                    while (t_aux->tipo && t_aux->next != NULL)
                    {
                        printf("%s,", t_aux->tipo);
                        t_aux = t_aux->next;
                    }
                    if (t_aux->tipo)
                    {
                        printf("%s)", t_aux->tipo);
                    }
                }
                else
                {
                    printf(")");
                }
            }
            if (entry->ret != NULL)
            {
                printf("\t%s\n", entry->ret);
            }
            else
            {
                printf("\n");
            }
            entry = entry->next;
        }
    }
    else
    {

        while (entry != NULL)
        {
            printf("%s\t\t", entry->id);
            printf("%s", entry->ret);
            if (entry->isParam == 0)
            {
                printf("\tparam\n");
            }
            else
            {
                printf("\n");
            }
            entry = entry->next;
        }
    }
    printf("\n");
} // printar as entrys dependendo se é class ou metodo