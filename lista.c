#include <stdio.h>

enum boolean {false=0, true=1};
typedef enum boolean bool;

typedef struct
{
    int info;
    struct lista *ant, *prox;
}lista;

lista * criarNo(int valor)
{
    lista *novo = (lista*) malloc (sizeof(lista));
    novo->info = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

lista * inserirInicio( lista *p , lista *novo)
{
    novo->prox = p;
    p->ant = novo;
    return novo;
}
void inserirFim (lista *p , lista *novo)
{
    while ( p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = novo;
    novo->ant = p;
}
void inserirMeio (lista *p , lista *novo)
{
    int num = qtdNo(p);
    lista *aux;
    int ins;
    if( num > 1)
    {
        num = 0;
        while (num != qtdNo(p)/2)
        {
            p = p->prox;
            num++;
        }
        aux = p->prox;
        p->prox = novo;
        novo->ant = p;
        novo->prox = aux;
        aux->ant = novo;
    }
    else
        printf("lista possui apenas um elemento, não tem meio");

}
int qtdNo (lista *p)
{
    int qtd = 0;
    while(p != NULL)
    {
        p = p->prox;
        qtd++;
    }
    return qtd;
}
void imprime (lista *p)
{
    while(p!=NULL)
    {
        printf("%d\n" , p->info);
        p = p->prox;
    }
}
main()
{
    lista *no;
    no = criarNo(10);
    no = inserirInicio( no , criarNo(12));
    inserirFim( no , criarNo(19));
    inserirMeio( no , criarNo(1));
    inserirMeio( no , criarNo(18));
    imprime(no);
}
