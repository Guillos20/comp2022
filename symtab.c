#include "symtab.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "struct.h"
#include <ctype.h>

Table *symtab;

void initTable(Node *node)
{
    char *params[8] = {"aiugsdiugha"};
    char *name = node->son->value;
    // printf("===== Class %s Symbol Table =====\n", name);
    symtab = createTable(name, 1, NULL, NULL, NULL);
    Table *aux = symtab;
    node = node->son->sibling;
    type *typ_aux = NULL;
    create_entry_Class_Table(node, symtab);
    while (node != NULL)
    { // percorre metodo a metodo ou field decl
        if (strcmp(node->token, "MethodDecl") == 0)
        {
            if (strcmp(node->son->token, "MethodHeader") == 0) // podemos vir a poder tirar isto uma vez que aparece sempre ,acho
            {
                aux = symtab;
                if (aux->next == NULL)
                {
                    typ_aux = CreateType_List(node->son->son->sibling->sibling->son);
                    aux->next = createTable(node->son->son->sibling->value, 2, typ_aux, NULL, NULL);
                    create_entry_Method_Table(node, aux->next);//o node aqui vai ser igual ao de cima
                    
                }
                else
                {
                    aux = aux->next;
                    while (aux->next)
                    {
                        aux = aux->next;
                    }
                    typ_aux = CreateType_List(node->son->son->sibling->sibling->son);
                    aux->next = createTable(node->son->son->sibling->value, 2, typ_aux, NULL, NULL);
                    create_entry_Method_Table(node, aux->next);
                    // printf("%s depois\n", entry_aux->id);
                }
            }
        }
        /*if (strcmp(node->token, "FieldDecl") == 0)
        {
            aux = symtab;
            if (aux->next == NULL){
        //printf("GIULLOS  ");
                    aux->next = createTable(node->son->son->sibling->value, 2, params, NULL, NULL);
                    create_entry_Class_Table(node, aux->next);
                }
                else
                {
                    //printf("anibau  ");
                    aux = aux->next;
                    while (aux->next){
                            aux = aux->next;
            //printf("%s  opa \n", entry_aux->id);
                        }
                aux = createTable(node->son->son->sibling->value, 2, params, NULL, NULL);
                create_entry_Class_Table(node, aux->next);
        // printf("%s depois\n", entry_aux->id);
    }
            symtab->next = createTable("entrou2", 1, NULL, NULL, NULL);
            create_entry_Class_Table(node, symtab);
            // symtab = symtab->next;
        }*/
        node = node->sibling;
    }
}

// table ent tem type[8], id, se é parametro, e o next ent

Table_ent *create_entry_Class_Table(Node *node, Table *global_table)
{ // este nó será o method decl ou field decl
    Table_ent *entry;
    type *parametros = NULL;
    int count = 0;
    while (node != NULL)
    {
        if (strcmp(node->token, "MethodDecl") == 0)
        {
            Node *paramdecl = node->son->son->sibling->sibling->son;//paramDecl
            parametros = CreateType_List(paramdecl);
            char *tipo = typeChange(node->son->son->token);
            char *id = node->son->son->sibling->value;
            // printf("%s\n", paramdecl->token);
            // if (paramdecl != NULL)
            // { // se o methodParams tem filhos
            //     for (Node *filho = paramdecl; filho != NULL; filho = filho->sibling)
            //     { // percorre os paramDecl
            //         char *t = malloc(256);
            //         t = typeChange(filho->son->token);
            //         // printf("%s olhaaaaa ", t);
            //         // printf("kkkkkkkkkk %d " , count);
            //         typeAux[count] = t;
            //         // printf(" %d   indice ", count);
            //         count++;
            //     }
            // }
            /*for(int i = 0; i < sizeof(typeAux);i++){
                printf("%s TypeAux  ", typeAux[i]);
            }*/
            parametros = CreateType_List(paramdecl);

            entry = insertEntry(tipo, parametros, id, 0, NULL);
            // printf("%s  ", entry->id);
            // count = 0;
            // bzero(typeAux, sizeof(typeAux));
        }
        if (strcmp(node->token, "FieldDecl") == 0)
        {

            parametros = CreateType_List(node);
            char *id = node->son->sibling->value;
            entry = insertEntry(NULL, parametros, id, 1, NULL);
            // bzero(typeAux, sizeof(typeAux));
        }
        // printf("welelle  ");
        if (global_table->entry == NULL)
        {
            // printf("GIULLOS  ");
            global_table->entry = entry;
        }
        else
        {
            // printf("anibau  ");
            Table_ent *entry_aux = global_table->entry;
            while (entry_aux->next)
            {

                // printf("%s  opa \n", entry_aux->id);
                entry_aux = entry_aux->next;
            }
            entry_aux->next = entry;
            // printf("%s depois\n", entry_aux->id);
        }
        node = node->sibling;
    }
}

Table_ent *create_entry_Method_Table(Node *node, Table *global_table){// node vai ser method decl ou field decl
    Table_ent *entry;
    type *parametros = NULL;
    int count = 0;
    if(strcmp(node->token,"MethodDecl") ==0){
        Node * methodBody = node->son->sibling;
        char *ret = typeChange(node->son->son->token);
        char *id = "return";
        entry = insertEntry(ret, NULL, id, 1, NULL);
        global_table->entry = entry;
        Node *aux =node->son->son->sibling->sibling;//MethodParams
        if(aux->son){
            aux = aux->son;
            while(aux){
                ret = typeChange(aux->son->token);
                id = aux->son->sibling->value;
                entry->next = insertEntry(ret,NULL,id,0,NULL);
                entry = entry->next;
                aux = aux->sibling;
            }
        }
        if(methodBody->son){
            Node *aux1 = methodBody->son;
            while(aux1){
                if(strcmp(aux1->token,"VarDecl") ==0){
                    ret = typeChange(aux1->son->token);
                    id = aux1->son->sibling->value;
                    entry->next = insertEntry(ret,NULL,id,1,NULL);
                    entry = entry->next;
                }
                aux1 = aux1->sibling;
            }
        }

    }  

}


type *CreateType_List(Node *cabeca)
{
    int count = 0;
    type *type_aux = NULL;
    if (cabeca != NULL) // ParamDecl
    {             
        if(strcmp(cabeca->token,"ParamDecl")==0){     // se o methodParams tem filhos
        for (Node *filho = cabeca; filho != NULL; filho = filho->sibling)
        { // percorre os paramDecl ou o field
                count ++;
            char *t = typeChange(filho->son->token);
            if (type_aux == NULL){
                type_aux = createType(t, NULL);

            }else{
                while (type_aux!=NULL){
                    type_aux = type_aux->next;
                }
                type_aux = createType(t, NULL);
            }
            }
        }if(strcmp(cabeca->token,"FieldDecl")==0){
            char *t = typeChange(cabeca->son->token);
            type_aux = createType(t, NULL);
        }
    }
    return type_aux;
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
            // printf("sai lololololol 132\n");
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
    // printf("entrei lololololl\n");
    /*if(tab->entry != NULL){
        printf("pppppp\n");
    }else{
        printf("tttttt\n");
    }*/
    // printf("okei\n");
    
    Table_ent *entry = tab->entry;
    // printf("okei\n");
    if (tab->type == 1)
    {
        while (entry != NULL)
        {
            // printf("jordao \n");
            printf("%s\t", entry->id); // print ID
            // printf("burro\n");
            if (entry->isParam == 1)
            {
                printf("%s", entry->tipo->tipo);
                // printf("guilherme\n");
            }
            if (entry->isParam == 0)
            {

                int i = 0;
                printf("(");
                // if (entry->typ[2] != NULL)
                // {
                //     printf("CONAAAA");
                // }
                // printf("%s   puta \n", entry->typ[2]);
                type *t_aux = entry->tipo;
                while (t_aux->tipo && t_aux->next != NULL)
                {
                    printf("%s,", t_aux->tipo);
                    t_aux = t_aux->next;
                    // printf("%s porrada \n",entry->typ[i+1]);
                }
                if (t_aux->tipo)
                {
                    printf("%s)", t_aux->tipo);
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
        printf("\n");
        return;
    }
    else
    {

        while (entry != NULL)
            {
        printf("%s\t", entry->id);
        printf("%s",entry->ret);
        if(entry->isParam == 0){
            printf("\tparam\n");
        }else{
            printf("\n");
        }
        entry = entry->next;
            }
    }
} // printar as entrys dependendo se é class ou metodo