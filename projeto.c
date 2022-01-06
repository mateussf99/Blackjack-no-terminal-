#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limpar() 
{
    system("cls || clear");
}

typedef struct No{
    int valor;
    struct No* next;
} No;

typedef struct Lista{
    No* inicio;
} Lista;

Lista* criar_lista() // lista para guarda as cartas puxadas do jogador
{
    Lista* jogador = malloc(sizeof(Lista));
    if (jogador != NULL)
    {
        jogador->inicio = NULL;
    }

    return jogador;
}
Lista* criar_lista2() // lista para guarda as cartas puxadas da banca
{
    Lista* banca = malloc(sizeof(Lista));
    if (banca != NULL)
    {
        banca->inicio = NULL;
    }

    return banca;
}

void rodada_inicial(Lista* jogador, Lista *banca, int *soma1, int *soma2)
{
    srand(time(NULL));
    for(int i=0; i<2; i++ ) //gera os numeros aleatorios para nossa rodada
    {
        No *novo = malloc(sizeof(No));
        novo->valor = rand() % 11;
        if (jogador->inicio == NULL)
        {
            jogador->inicio = novo; 
            novo->next = NULL;
            *soma1 += novo->valor;
        }
        else
        {
            novo->next = jogador->inicio;
            jogador->inicio=novo;
            *soma1 += novo->valor;
        }
    }
    for(int i=0; i<2; i++ ) //gera os numeros aleatorios para nossa rodada
    {
        No *novo = malloc(sizeof(No));
        novo->valor = rand() % 11;
        if (banca->inicio == NULL)
        {
            banca->inicio = novo; 
            novo->next = NULL;
            *soma2 += novo->valor;
        }
        else
        {
            novo->next = banca->inicio;
            banca->inicio=novo;
            *soma2 += novo->valor;
        }
    }
    
    
}

void imprimir(Lista* jogador, Lista *banca, int *soma1, int *soma2)// criei so para ver se tava salvando certo
{
    No* atual;
    if(jogador->inicio == NULL)
    {
        printf("A lista está vazia.");
        return;
    }
    printf("jogador: ");
    for(atual = jogador->inicio; atual != NULL; atual = atual->next)
    {
        printf("%d, ", atual->valor);
    }
    printf("\n");
    printf("%d\n", *soma1);
    printf("Banca: ");
    for(atual = banca->inicio; atual != NULL; atual = atual->next)
    {
        printf("%d, ", atual->valor);
    }
    printf("\n");
    printf("%d\n", *soma2);
}

void menu()
{
    int escolha, a = 0, b = 0;
    int *soma1, *soma2;
    soma1 = &a;
    soma2 = &b;
    Lista *jogador = criar_lista();
    Lista *banca = criar_lista2();

    do
    {
        limpar();
        printf("------------------------------\n");
        printf("########## BLACKJACK #########\n");
        printf("############ MENU ############\n");
        printf("------------------------------\n");
        printf("|1| Começar a jogar\n");
        printf("|2| imprimir\n");
        printf("|3| Encerrar\n");
        printf("------------------------------\n\n");

        printf("Escolha: ");
        scanf("%d", &escolha);
        getchar();
        limpar();
        switch(escolha) 
        {
            case 1:
                rodada_inicial(jogador, banca, soma1, soma2);
                break;
            case 2:
                imprimir(jogador, banca, soma1, soma2);
                break;
            case 3:
            return;

        default:
            printf("ERRO: OPÇÃO INVÁLIDA\n");
            break;
        }
        printf("\nPressione Enter para continuar...");
        getchar(); 
    }
    while(escolha != 3);

}

int main()
{
    menu();
    return 0;
}