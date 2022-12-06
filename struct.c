#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
// bash test.sh ./run para correr tudo estando os testes na pasta em questao, na meta 1 era meta1
extern Table *symtab;
char *func;
Node *createNode(char *token, char *value, Node *son, Node *sibling)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->token = token;
    n->value = value;
    n->son = son;
    n->sibling = sibling;
    n->type = NULL;
    return n;
}

Table *createTable(char *id, int typical, struct type *t, struct Table *next, struct Table_ent *entry)
{
    Table *table = malloc(sizeof(Table));
    /*if (table == NULL){
        return NULL;}
    */
    table->id = id;
    table->type = typical;
    // printf("%ld\n",sizeof(*params));
    table->tipo = t;
    table->next = next;
    table->entry = entry;
    return table;
}

Table_ent *insertEntry(char *ret, struct type *t, char *id, int isParam, struct Table_ent *next)
{
    Table_ent *ent = malloc(sizeof(Table_ent));
    ent->ret = ret;
    ent->id = id;
    ent->isParam = isParam;
    ent->next = next;
    // for (int i = 0; i < sizeof(*type); i++)
    // {
    //     //ent->typ[i] = type[i];
    // }
    ent->tipo = t;
    return ent;
}

type *createType(char *tipo, type *next)
{
    type *t = malloc(sizeof(type));
    t->tipo = tipo;
    t->next = next;
    return t;
}

void save_type(Node *first, Node *type)
{
    Node *aux = first->sibling;
    Node *temp;
    while (aux)
    {
        Node *newtype = createNode(type->token, type->value, NULL, NULL);
        temp = aux->son;
        aux->son = newtype;
        aux->son->sibling = temp;
        aux = aux->sibling;
    }
}
Node *add_sibling(Node *someone, Node *sibling)
{

    if (sibling == NULL)
    {
        return NULL;
    }
    Node *aux = (Node *)(malloc)(sizeof(Node));
    Node *old = (Node *)(malloc)(sizeof(Node));
    old = someone;
    aux = someone->sibling;
    while (aux != NULL)
    {
        old = aux;
        aux = aux->sibling;
    }

    old->sibling = (Node *)(malloc)(sizeof(Node));

    old->sibling = sibling;

    return someone;
}
Node *add_son(Node *parent, Node *son)
{
    // if given son is NULL well that's about it
    if (son == NULL)
    {
        return NULL;
    }
    // if son exists but is empty we add it
    if (parent->son == NULL)
    {
        parent->son = (Node *)(malloc)(sizeof(Node));
        parent->son = son;
    }
    // if the son already exists checks every son of given parent until there is a son that has no sibling
    //  then adds the node 'son' to the empty node
    else
    {
        Node *aux = (Node *)(malloc)(sizeof(Node));
        Node *old = (Node *)(malloc)(sizeof(Node));
        old = parent->son;
        aux = parent->son->sibling;

        while (aux != NULL)
        {
            old = aux;
            aux = aux->sibling;
        }

        old->sibling = (Node *)(malloc)(sizeof(Node));
        old->sibling = son;
    }
    // printf("Child %s added to parent %s\n", son->token, parent->token);
    return parent;
}
void print_tree(Node *node, int num)
{
    if (node == NULL)
    {
        return;
    }
    for (int i = 0; i < num; i++)
    {
        printf("..");
    }
    if (node->value != NULL)
    {
        printf("%s(%s)\n", node->token, node->value);
    }
    else
    {

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
}
void print_anotated_tree(Node *node, int num)
{
    if (node == NULL)
    {
        return;
    }
    for (int i = 0; i < num; i++)
    {
        printf("..");
    }
    if (node->value != NULL)
    {

        printf("%s(%s)", node->token, node->value);
        if (node->type != NULL)
        {
            printf(" - %s\n", node->type);
        }
        else
        {
            printf("\n");
        }
    }
    else
    {

        printf("%s", node->token);
        if (node->type != NULL)
        {
            printf(" - %s\n", node->type);
        }
        else
        {
            printf("\n");
        }
    }

    if (node->son != NULL)
    {
        print_anotated_tree(node->son, num + 1);
    }

    if (node->sibling != NULL)
    {
        print_anotated_tree(node->sibling, num);
    }
}

char *get_type_entry(char *id, Table *tab)
{

    Table_ent *tab_ent = tab->entry;
    while (tab_ent)
    {
        // printf("%s\n", tab_ent->id);
        if (strcmp(tab_ent->id, id) == 0)
        {
            if (tab->type == 1)
            {
                if (tab_ent->tipo)
                {
                    //   printf("tipo-------%s\n", tab_ent->tipo->tipo);

                    return tab_ent->tipo->tipo;
                }
                else
                {
                    return "()";
                }
            }
            else
            {
                // printf("ret-------%s\n", tab_ent->ret);
                return tab_ent->ret;
            }
        }
        else
        {
            tab_ent = tab_ent->next;
        }
    }
    if (tab->next)
    {
        get_type_entry(id, tab->next);
    }
    else
    {
        return "undef";
    }
}
type *get_type_func(char *id, Table *tab)
{
    Table_ent *tab_ent = tab->entry;
    while (tab_ent)
    {
        // printf("%s\n", tab_ent->id);
        if (strcmp(tab_ent->id, id) == 0)
        {

            return tab_ent->tipo;
        }
        else
        {
            tab_ent = tab_ent->next;
        }
    }
}
char *get_ret_func(char *id, Table *tab)
{
    Table_ent *tab_ent = tab->entry;
    while (tab_ent)
    {
        // printf("%s\n", tab_ent->id);
        if (strcmp(tab_ent->id, id) == 0)
        {

            return tab_ent->ret;
        }
        else
        {
            tab_ent = tab_ent->next;
        }
    }
}
void anotate_that_tree(Node *node)
{
    if (node)
    {
        if (strcmp(node->token, "MethodDecl") == 0)
        {
            func = node->son->son->sibling->value;
            // printf("%s\n", func);
        }
        if (strcmp(node->token, "Assign") == 0)
        {
            // need to add Lshift and Rshift in this func
            Node *son = node->son;

            if (strcmp(son->token, "Id") == 0)
            {
                son->type = get_type_entry(son->value, symtab);
            }
            node->type = son->type;
            if (strcmp(son->sibling->token, "Id") == 0)
            {
                son->sibling->type = get_type_entry(son->sibling->value, symtab);
            }
            else
            {
                anotate_that_tree(son);
            }
        }
        if (strcmp(node->token, "Xor") == 0 || strcmp(node->token, "Or") == 0)
        {
            if (strcmp(node->son->token, "Not") == 0)
            {
                if (strcmp(node->son->son->token, "BoolLit") == 0)
                {
                    node->type = "boolean";
                }
                else
                {
                    node->son->son->type = get_type_entry(node->son->son->value, symtab);
                    node->son->type = "boolean";
                    node->type = "boolean";
                }
            }
            if (strcmp(node->son->token, "BoolLit") == 0)
            {
                node->type = "boolean";
            }

            if (strcmp(node->son->token, "DecLit") == 0)
            {
                node->type = "int";
            }
            else if (strcmp(node->son->token, "RealLit") == 0)
            {
                node->type = "undef";
            }
            else
            {
                node->type = "boolean";
            }
        }
        if (strcmp(node->token, "Add") == 0 || strcmp(node->token, "Sub") == 0 || strcmp(node->token, "Mul") == 0 || strcmp(node->token, "Div") == 0 || strcmp(node->token, "Mod") == 0)
        {
            if (strcmp(node->son->token, "Id") == 0)
            {
                node->son->type = get_type_entry(node->son->value, symtab);
            }
            else
            {
                anotate_that_tree(node->son);
                anotate_that_tree(node->son->sibling);
            }
            if (strcmp(node->son->sibling->token, "Id") == 0)
            {
                node->son->sibling->type = get_type_entry(node->son->sibling->value, symtab);
            }
            if (strcmp(node->son->token, "DecLit") == 0)
            {
                node->son->type = "int";
            }
            if (strcmp(node->son->token, "RealLit") == 0)
            {
                node->son->type = "double";
            }
            if (strcmp(node->son->token, "StrLit") == 0)
            {
                node->son->type = "String";
            }
            if (strcmp(node->son->token, "BoolLit") == 0)
            {
                node->son->type = "boolean";
            }
            if (strcmp(node->son->sibling->token, "DecLit") == 0)
            {
                node->son->sibling->type = "int";
            }
            if (strcmp(node->son->sibling->token, "RealLit") == 0)
            {
                node->son->sibling->type = "double";
            }
            if (strcmp(node->son->sibling->token, "StrLit") == 0)
            {
                node->son->sibling->type = "String";
            }
            if (strcmp(node->son->sibling->token, "BoolLit") == 0)
            {
                node->son->sibling->type = "boolean";
            }
            if (strcmp(node->son->type, "double") == 0 || strcmp(node->son->sibling->type, "double") == 0)
            {
                node->type = "double";
            }
            if (strcmp(node->son->type, "int") == 0 && strcmp(node->son->sibling->type, "int") == 0)
            {
                node->type = "int";
            }
            if (strcmp(node->son->type, "boolean") == 0 || strcmp(node->son->type, "String") == 0 || strcmp(node->son->sibling->type, "boolean") == 0 || strcmp(node->son->sibling->type, "String") == 0 || strcmp(node->son->type, "undef") == 0 || strcmp(node->son->sibling->type, "undef") == 0)
            {
                node->type = "undef";
            }
        }
        if (strcmp(node->token, "DecLit") == 0 || strcmp(node->token, "Length") == 0)

        {
            node->type = "int";
            if (node->son)
            {
                node->son->type = get_type_entry(node->son->value, symtab);
            }
        }
        if (strcmp(node->token, "RealLit") == 0)
        {
            node->type = "double";
        }
        if (strcmp(node->token, "StrLit") == 0)
        {
            node->type = "String";
        }
        if (strcmp(node->token, "Lt") == 0 || strcmp(node->token, "Gt") == 0 || strcmp(node->token, "Eq") == 0 || strcmp(node->token, "Ne") == 0 || strcmp(node->token, "Le") == 0 || strcmp(node->token, "Ge") == 0 || strcmp(node->token, "BoolLit") == 0 || (strcmp(node->token, "Not") == 0) || (strcmp(node->token, "And") == 0))
        {
            node->type = "boolean";
            if (node->son)
            {
                if (strcmp(node->son->token, "Id") == 0)
                {
                    node->son->type = get_type_entry(node->son->value, symtab);
                }
                if (node->son->sibling)
                {
                    if (strcmp(node->son->sibling->token, "Id") == 0)
                    {
                        node->son->sibling->type = get_type_entry(node->son->sibling->value, symtab);
                    }
                }
            }
        }
        if (strcmp(node->token, "Minus") == 0 || (strcmp(node->token, "Plus") == 0))
        {
            if (strcmp(node->son->token, "DecLit") == 0)

            {
                node->son->type = "int";
                node->type = "int";
            }
            if (strcmp(node->son->token, "RealLit") == 0)
            {
                node->son->type = "double";
                node->type = "double";
            }
            if (strcmp(node->son->token, "BoolLit") == 0)
            {
                node->son->type = "boolean";
                node->type = "undef";
            }
            // node->son->type = get_type_entry(node->son->value, symtab);
            // node->type = node->son->type;
            // if (strcmp(node->son->type, "boolean") == 0 || strcmp(node->son->type, "undef") == 0)
            // {
            // }else{

            // }
        }
        if (strcmp(node->token, "ParseArgs") == 0)
        {
            node->type = "int";

            if (strcmp(node->son->token, "Id") == 0)
            {
                node->son->type = get_type_entry(node->son->value, symtab);
            }
        }
        if (strcmp(node->token, "Print") == 0)
        {
            if (strcmp(node->son->token, "Id") == 0)
            {
                node->son->type = get_type_entry(node->son->value, symtab);
            }
        }
        if (strcmp(node->token, "If") == 0 || strcmp(node->token, "While") == 0)
        {
            if (strcmp(node->son->token, "Id") == 0)
            {
                node->son->type = get_type_entry(node->son->value, symtab);
            }
        }
        /*if (strcmp(node->token, "Call") == 0)
        {
            char string[100] = "";
            int correct = 0;
            type *str = malloc(sizeof(type));
            str = get_type_func(node->son->value, symtab);
            // while (str->next)
            // {
            //     printf("Node:  %s     %s\n", node->son->value, str->tipo);
            //     str = str->next;
            // }
            // printf("%s\n", str->tipo);
            char *ret = get_ret_func(node->son->value, symtab);
            type *aux2 = malloc(sizeof(type));
            aux2 = str;
            strcat(string, "(");
            while (aux2->next)
            {
                strcat(string, aux2->tipo);
                strcat(string, ",");
                aux2 = aux2->next;
            }
            strcat(string, aux2->tipo);
            strcat(string, ")");
            // printf("%s\n", string);

            // printf("Return: %s\n", ret);
            if (strcmp(node->son->sibling->token, "Id") == 0)
            {
                node->son->sibling->type = get_type_entry(node->son->sibling->value, symtab);
            }
            if (strcmp(node->son->sibling->sibling->token, "Id") == 0)
            {
                node->son->sibling->sibling->type = get_type_entry(node->son->sibling->sibling->value, symtab);
            }
            anotate_that_tree(node->son->sibling);
            anotate_that_tree(node->son->sibling->sibling);
            Node *aux = malloc(sizeof(Node));
            aux = node->son->sibling;

            while (aux && str)
            {
                if (strcmp(aux->type, "double") == 0)
                {
                    if (strcmp(str->tipo, "double") == 0 || strcmp(str->tipo, "int") == 0)
                    {
                    }
                    else
                    {
                        correct += 1;
                    }
                }
                else if (strcmp(aux->type, str->tipo) == 0)
                {

                    // printf("%s\t%s\n", aux->type, str->tipo);
                }
                // else
                // {
                //     correct += 1;

                // }
                printf("Entrou %s\t%s\n", aux->type, str->tipo);

                aux = aux->sibling;
                str = str->next;
            }
            printf("%d\n", correct);
            if (correct != 0)
            {
                node->type = "undef";
                node->son->type = "undef";
            }
            else
            {
                node->son->type = string;
                node->type = ret;
            }
        }
        */
        if (strcmp(node->token, "Lshift") == 0 || strcmp(node->token, "Rshift") == 0)
        {
            if (strcmp(node->son->token, "Id") == 0)
            {
                node->son->type = get_type_entry(node->son->value, symtab);
            }
            else
            {
                anotate_that_tree(node->son);
            }
            if (strcmp(node->son->sibling->token, "Id") == 0)
            {
                node->son->sibling->type = get_type_entry(node->son->sibling->value, symtab);
            }
            else
            {
                anotate_that_tree(node->son->sibling);
            }
            if (strcmp(node->son->type, "int") == 0 && strcmp(node->son->sibling->type, "int") == 0)
            {
                node->type = "int";
            }
            else
            {
                node->type = "undef";
            }
        }
        if (strcmp(node->token, "Return") == 0)
        {if(node->son){
            if (strcmp(node->son->token, "Id") == 0)
            {
                node->son->type = get_type_entry(node->son->value, symtab);
            }
        }
        }

        if (node->son != NULL)
        {
            anotate_that_tree(node->son);
        }

        if (node->sibling != NULL)
        {
            anotate_that_tree(node->sibling);
        }
    }
    else
    {
        return;
    }
};