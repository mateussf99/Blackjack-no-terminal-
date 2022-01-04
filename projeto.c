#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limpar() 
{
    system("cls || clear");
}

typedef struct No{
    int valor;
    int result_soma;
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

void rodada(Lista *jogador)
{
    
    for(int i = 0; i < 2; i++) //gera os numeros aleatorios para nossa rodada
    {
        No *novo = malloc(sizeof(No));
        srand(time(NULL));
        novo->valor = rand() % 11;
        if (jogador->inicio == NULL)
        {
            jogador->inicio = novo; 
            novo->next = NULL;
            novo->result_soma = 0;
        }
        else
        {
            novo->next = jogador->inicio;
            jogador->inicio=novo;
            novo->result_soma = 0;
        }
        if (novo->next != NULL) 
        {
            novo->result_soma += novo->next->valor;
            novo->next->result_soma += novo->valor;
        }
    }

}

void imprimir(Lista* jogador)// criei so para ver se tava salvando certo
{
    No* atual;
    if(jogador->inicio == NULL)
    {
        printf("A lista está vazia.");
        return;
    }
    printf("jogador 1: ");
    for(atual = jogador->inicio; atual != NULL; atual = atual->next)
    {
        printf("%d, ", atual->valor);
    }
    printf("\n");
}

void menu()
{
    int escolha;
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
                rodada(jogador);
                break;
            case 2:
                imprimir(jogador);
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