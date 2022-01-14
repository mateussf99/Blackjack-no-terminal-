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
void resultado(Lista* jogador, Lista *banca, int *soma1, int *soma2)
{
    limpar();
    No* atual;
    if (*soma2 == *soma1)
    {
        printf("A Banca puxou algumas cartas\n");
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
        printf("DEU EMPATE!!!!!\n");
    }
    else if (*soma2 < *soma1 && *soma1 <= 21)
    {
        printf("A Banca puxou algumas cartas\n");
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
        printf("O JOGADOR GANHOU!!!!\n");
    }
    else if (*soma2 > *soma1 && *soma1 <= 21 && *soma2 > 21)
    {
        printf("A Banca puxou algumas cartas\n");
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
        printf("O JOGADOR GANHOU!!!!\n");
    }
    else if (*soma2 > *soma1 && *soma2 < 21)
    {
        printf("A Banca puxou algumas cartas\n");
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
        printf("A BANCA GANHOU!!!!\n");
    }
    else if (*soma2 > *soma1 && *soma2 <= 21)
    {
        printf("A Banca puxou algumas cartas\n");
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
        printf("A BANCA GANHOU!!!!\n");
    }
    else if (*soma2 < *soma1 && *soma1 > 21)
    {
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
        printf("A BANCA GANHOU!!!!\n");
    }
    free(jogador);
    free(banca);
    
}
void ad_jogador(Lista* jogador,  int *soma1)
{
    srand(time(NULL));
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
void ad_banca(Lista* jogador, Lista *banca, int *soma1, int *soma2)
{
    int cont=2;
    srand(time(NULL));
    while(cont != 5)
    {
        limpar();
        if(*soma2 < *soma1 && *soma1 <= 21 || *soma2 == *soma1 && *soma1 <= 21)
        {
            if(*soma2 > *soma1)
            {
                break;
            }
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
            No* atual;
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
            cont++;
        }
        else
        {
            break;
        }
        
    }
    resultado(jogador, banca, soma1, soma2);
    
}

void carta(Lista* jogador, Lista *banca, int *soma1, int *soma2)
{
    int escolha, cont=2;
    while(escolha != 2)
    {
        printf("------------------------------\n");
        printf("|1| Pedir carta\n");
        printf("|2| Passar a vez para a Banca\n");
        printf("------------------------------\n\n");

        printf("Escolha: ");
        scanf("%d", &escolha);
        getchar();
        limpar();
        switch(escolha) 
        {
            case 1:
                if(cont<5)
                {
                    cont++;
                    ad_jogador(jogador,  soma1);
                    No* atual;
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
                else
                {
                    printf("Voçê não pode pedir mais cartas\n");
                }
                break;
            case 2:
                ad_banca(jogador, banca, soma1, soma2);
                return;

        default:
            printf("ERRO: OPÇÃO INVÁLIDA\n");
            break;
        }
        printf("\nPressione Enter para continuar...");
        getchar();
    }
    

}

void rodada_inicial()
{
    int a = 0, b = 0;
    int *soma1, *soma2;
    soma1 = &a;
    soma2 = &b;
    Lista *jogador = criar_lista();
    Lista *banca = criar_lista2();
    srand(time(NULL));
    for(int i=0; i<2; i++ ) //gera os 2 primeiros numeros aleatorios para o jogador
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
    for(int i=0; i<2; i++ ) //gera os 2 primeiros numeros aleatorios para a banca
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
    No* atual;
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
    carta( jogador, banca, soma1, soma2);
}

void menu()
{
    int escolha;

    do
    {
        limpar();
        printf("------------------------------\n");
        printf("########## BLACKJACK #########\n");
        printf("############ MENU ############\n");
        printf("------------------------------\n");
        printf("|1| Começar a jogar\n");
        printf("|2| Encerrar\n");
        printf("------------------------------\n\n");

        printf("Escolha: ");
        scanf("%d", &escolha);
        getchar();
        limpar();
        switch(escolha) 
        {
            case 1:
                rodada_inicial();
                break;
            case 2:
            return;

        default:
            printf("ERRO: OPÇÃO INVÁLIDA\n");
            break;
        }
        printf("\nPressione Enter para continuar...");
        getchar(); 
    }
    while(escolha != 2);

}

int main()
{
    menu();
    return 0;
}