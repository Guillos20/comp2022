#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "symtab.h"
// bash test.sh ./run para correr tudo estando os testes na pasta em questao, na meta 1 era meta1
extern Table *symtab;
char *func;
char *class;
extern int col_yacc;
extern int linha;

Node *createNode(char *token, char *value, Node *son, Node *sibling)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->token = token;
    n->value = value;
    n->son = son;
    n->sibling = sibling;
    n->type = NULL;
    n->column = col_yacc;
    n->line = linha;
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

char *get_type_entry(char *id, Table *tab, char *func)
{
    int hasDone = 0;
    if (strcmp(func, class) == 0)
    {
        hasDone++;
    }
    if (func)
    {
        while (strcmp(tab->id, func) != 0)
        {
            tab = tab->next;
        }
    }
    // printf("Tabela\t%s\n", tab->id);
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
                    // printf("entrou\n");
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
    if (!hasDone)
    {
        get_type_entry(id, symtab, class);
    }
    else
    {
        return "undef";
    }
}
type *get_type_func(char *id, Table *tab, type *t)
{
    // if (t)
    // {
    //     if (t->next)
    //     {
    //         printf("lelelelelelel\t %s  \n", t->next->tipo);
    //     }
    // }
    Table_ent *tab_ent = tab->entry;
    type *auxType = malloc(sizeof(type));
    while (tab_ent)
    {
        // printf("%s\n", tab_ent->id);
        if (strcmp(tab_ent->id, id) == 0)
        {
            // maybe add if
            auxType = tab_ent->tipo;
            // printf(" anibal\t%s\t%s\n",auxType->tipo,t->tipo);
            if (compare_tree_params(auxType, t) == 1)
            {
                return tab_ent->tipo;
            }
            else
            {
                tab_ent = tab_ent->next;
            }
            // while(auxType){
            //     if(strcmp(auxType->tipo, t->tipo)==0){

            //     }
            // }
            // printf("%s\n", tab_ent->tipo->tipo);
        }
        else
        {
            tab_ent = tab_ent->next;
        }
    }
    return NULL;
}

int compare_tree_params(type *params, type *p)
{
    // printf("lololololk\n");

    if (params == NULL && p == NULL)
    {
        return 1; // sao iguais
    }
    if ((params == NULL && p != NULL) || (params != NULL && p == NULL))
    {
        return 0; // sao diferentes
    }

    type *aux_type1 = params;
    type *aux_type2 = p;
    // printf("okokkok\n");
    while (aux_type1 && aux_type2)
    {
        if (strcmp(aux_type1->tipo, aux_type2->tipo) != 0)
        {
            return 0; // sao diferentes
        }
        if ((aux_type1->next == NULL && aux_type2->next != NULL) || (aux_type1->next != NULL && aux_type2->next == NULL))
        {
            return 0; // sao diferentes
        }
        aux_type1 = aux_type1->next;
        aux_type2 = aux_type2->next;
    }
    return 1; // sao iguais
}

char *get_ret_func(char *id, Table *tab, type *tipo)
{
    type *auxType = malloc(sizeof(type));

    Table_ent *tab_ent = tab->entry;
    while (tab_ent)
    {
        auxType = tab_ent->tipo;
        // printf(" anibal\t%s\t%s\n",auxType->tipo,t->tipo);
        if (compare_tree_params(auxType, tipo) == 1)
        {
            return tab_ent->ret;
        }
        else
        {
            tab_ent = tab_ent->next;
        }
    }
    return "undef";
}
void anotate_that_tree(Node *node)
{
    if (node)
    {
        if (strcmp(node->token, "Program") == 0)
        {
            class = node->son->value;
        }
        if (strcmp(node->token, "MethodDecl") == 0)
        {
            func = node->son->son->sibling->value;
            // printf("%s\n", func);
        }
        if (strcmp(node->token, "Assign") == 0)
        {
            int leng =0;
            // need to add Lshift and Rshift in this func
            Node *son = node->son;

            if (strcmp(son->token, "Id") == 0)
            {
                son->type = get_type_entry(son->value, symtab, func);
                node->type = son->type;
            }
            else
            {
                anotate_that_tree(son);
                node->type = son->type;

            }

            if (strcmp(son->sibling->token, "Id") == 0)
            {
                son->sibling->type = get_type_entry(son->sibling->value, symtab, func);
            }
            else
            {
                anotate_that_tree(son->sibling);
            }
            if (strcmp(son->type, "double") == 0 && (strcmp(son->sibling->type, "double") == 0 || strcmp(son->sibling->type, "int") == 0))
            {
            }
            else if (strcmp(son->type, son->sibling->type) != 0)
            {
                if(son->sibling->value){
                    leng =strlen(son->sibling->value) + 2;
                }
                printf("Line %d, col %d: Operator = cannot be applied to types %s, %s\n", son->line, son->column - leng, son->type, son->sibling->type);
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
                    node->son->son->type = get_type_entry(node->son->son->value, symtab, func);
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
            char *op = "";
            if(strcmp(node->token, "Add") == 0){
            op = "+";

            }else if(strcmp(node->token, "Sub") == 0){
            op = "-";

            }else if(strcmp(node->token, "Mul") == 0){
            op = "*";

            }else if(strcmp(node->token, "Div") == 0){
            op = "/";
            }
            if (node->son)
            {
                if (strcmp(node->son->token, "Id") == 0)
                {
                    node->son->type = get_type_entry(node->son->value, symtab, func);
                }
                else
                {
                    anotate_that_tree(node->son);
                }
                if (strcmp(node->son->sibling->token, "Id") == 0)
                {
                    node->son->sibling->type = get_type_entry(node->son->sibling->value, symtab, func);
                }
                else
                {
                    anotate_that_tree(node->son->sibling);
                }
                if (node->son->type)
                {
                    if (strcmp(node->son->type, "double") == 0 || strcmp(node->son->sibling->type, "double") == 0)
                    {
                        node->type = "double";
                    }
                    if (strcmp(node->son->type, "int") == 0 && strcmp(node->son->sibling->type, "int") == 0)
                    {
                        node->type = "int";
                    }
                    if (strcmp(node->son->type, "boolean") == 0 || strcmp(node->son->type, "String") == 0 || strcmp(node->son->sibling->type, "boolean") == 0 || strcmp(node->son->sibling->type, "String") == 0 || strcmp(node->son->type, "undef") == 0 || strcmp(node->son->sibling->type, "undef") == 0 || strcmp(node->son->type, "String[]") == 0 || strcmp(node->son->sibling->type, "String[]") == 0)
                    {
                        node->type = "undef";
                        printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", node->line, node->column, op ,node->son->type, node->son->sibling->type);

                    }
                }
                else
                {
                    node->type = "undef";
                    //printf("Line %d, col %d: Operator %s cannot be applied to type %s\n", node->line, node->column, op ,node->son->type);

                }
            }
        }
        if (strcmp(node->token, "DecLit") == 0 || strcmp(node->token, "Length") == 0)

        {
            node->type = "int";
            if (node->son)
            {
                node->son->type = get_type_entry(node->son->value, symtab, func);
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
                    node->son->type = get_type_entry(node->son->value, symtab, func);
                }
                if (node->son->sibling)
                {
                    if (strcmp(node->son->sibling->token, "Id") == 0)
                    {
                        node->son->sibling->type = get_type_entry(node->son->sibling->value, symtab, func);
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
            Node *aux = malloc(sizeof(Node));
            aux = node->son;
            while (aux)
            {
                if (strcmp(aux->token, "Id") == 0)
                {
                    aux->type = get_type_entry(aux->value, symtab, func);
                }
                else
                {
                    anotate_that_tree(aux);
                }
                aux = aux->sibling;
            }
        }
        if (strcmp(node->token, "Print") == 0)
        {
            Node *aux = malloc(sizeof(Node));
            aux = node->son;
            while (aux)
            {

                if (strcmp(aux->token, "Id") == 0)
                {
                    aux->type = get_type_entry(aux->value, symtab, func);
                }
                else
                {
                    anotate_that_tree(aux);
                }
                aux = aux->sibling;
            }
        }
        if (strcmp(node->token, "If") == 0 || strcmp(node->token, "While") == 0)
        {
            Node *aux = malloc(sizeof(Node));
            aux = node->son;
            while (aux)
            {

                if (strcmp(aux->token, "Id") == 0)
                {
                    aux->type = get_type_entry(aux->value, symtab, func);
                }
                else
                {
                    anotate_that_tree(aux);
                }
                aux = aux->sibling;
            }
        }
        if (strcmp(node->token, "Call") == 0)
        {

            int num_of_params = 0;
            int num_of_sib = 0;
            type *tipos_call = NULL;
            type *aux_t = NULL;

            if (node->son->sibling)
            {
                Node *params = malloc(sizeof(Node));
                params = node->son->sibling;
                while (params)
                {
                    num_of_sib++;
                    if (strcmp(params->token, "Id") == 0)
                    {
                        params->type = get_type_entry(params->value, symtab, func);
                    }
                    else
                    {
                        // printf(" ioioioioo \t %s  \n", params->token);
                        anotate_that_tree(params);
                    }
                    // printf("estou aqui    %s \n",params->type);
                    if (tipos_call == NULL)
                    {
                        tipos_call = createType(params->type, NULL);
                    }
                    else
                    {
                        aux_t = tipos_call;
                        while (aux_t->next != NULL)
                        {
                            aux_t = aux_t->next;
                        }
                        aux_t->next = createType(params->type, NULL);
                    }
                    params = params->sibling;
                }

                if (tipos_call)
                {

                    // printf("lelelelelelel\t %s  \n", tipos_call->tipo);
                }
            }

            char string[1999] = "";
            int correct = 0;
            type *str = malloc(sizeof(type));
            // printf("KEBBAB1111  \t %s \n",node->son->value);
            str = get_type_func(node->son->value, symtab, tipos_call);
            if (str)
            {
                if (str->next)
                {
                    // printf("lelelelelelel\t %s  \n", str->next->tipo);
                }
            }
            // printf("KEBBAB  \t %s \n",str->tipo);
            char *ret = get_ret_func(node->son->value, symtab, tipos_call);
            type *aux2 = malloc(sizeof(type));
            aux2 = str;
            strcat(string, "(");
            if (str)
            {

                while (aux2->next)
                {
                    num_of_params++;
                    strcat(string, aux2->tipo);
                    strcat(string, ",");
                    aux2 = aux2->next;
                }
            }
            if (aux2)
            {
                num_of_params++;
                strcat(string, aux2->tipo);
            }
            strcat(string, ")");
            // printf("yes\t%s\n", string);

            Node *aux = malloc(sizeof(Node));
            aux = node->son->sibling;

            while (aux && str)
            {
                if (strcmp(str->tipo, "double") == 0)
                {
                    if (strcmp(aux->type, "double") == 0 || strcmp(aux->type, "int") == 0)
                    {
                    }
                    else
                    {
                        // printf("okoookokkkkdkkfkfkfk\t %s\t %s \n", str->tipo, aux->type);
                        correct += 1;
                    }
                }
                else if (strcmp(aux->type, str->tipo) == 0)
                {

                    // printf("%s\t%s\n", aux->type, str->tipo);
                }
                else
                {
                    // printf("hfhjdhggg\t%s\t %s \n", str->tipo, aux->type);
                    correct += 1;
                }
                // printf("Entrou:%s\t %s\t%s\n",node->son->value, aux->type, str->tipo);

                aux = aux->sibling;
                str = str->next;
            }
            // printf("%d\n", correct);
            if (correct != 0 || num_of_params != num_of_sib)
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
        if (strcmp(node->token, "Lshift") == 0 || strcmp(node->token, "Rshift") == 0)
        {
            if (strcmp(node->son->token, "Id") == 0)
            {
                node->son->type = get_type_entry(node->son->value, symtab, func);
            }
            else
            {
                anotate_that_tree(node->son);
            }
            if (strcmp(node->son->sibling->token, "Id") == 0)
            {
                node->son->sibling->type = get_type_entry(node->son->sibling->value, symtab, func);
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
        {
            if (node->son)
            {
                if (strcmp(node->son->token, "Id") == 0)
                {
                    node->son->type = get_type_entry(node->son->value, symtab, func);
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