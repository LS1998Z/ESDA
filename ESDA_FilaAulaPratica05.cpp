#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char bairro[50];
    char cidade[50];
    char pais[50];
}Endereco;

typedef struct{
    int codigo;
    Data dataAss;
    float salario;
}Contrato;

typedef struct{
    char nome[50];
    Data dataNas;
    Endereco end;
    Contrato contr;
}Jogador;

typedef struct no{
    Jogador j;
    struct no *proximo;
}No;

void imprimirData(Data d){
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

void imprimirEndereco(Endereco end){
    printf("\tEndereco:\n");
    printf("\t\tBairro: %s", end.bairro);
    printf("\t\tCidade: %s", end.cidade);
    printf("\t\tPais: %s", end.pais);
}

void imprimirContrato(Contrato c){
    printf("\tContrato %d:\n", c.codigo);
    printf("\t\tSalario R$%.2f\n", c.salario);
    printf("\t\tData de ad.: ");
    imprimirData(c.dataAss);
}

void imprirJogador(Jogador j){
    printf("\n\tNome: %s", j.nome);
    printf("\tData de nas.: ");
    imprimirData(j.dataNas);
    imprimirEndereco(j.end);
    imprimirContrato(j.contr);
}

// ------------ Leitura dos dados de uma Pessoa -------------------------

Data lerData(){
    Data d;
    printf("\nDigite a data no formato dd mm aaaa: ");
    scanf("%d%d%d", &d.dia, &d.mes, &d.ano);
    getchar();
    return d;
}

Endereco lerEndereco(){
    Endereco end;
    printf("\nBairro: ");
    fgets(end.bairro, 49, stdin);
    printf("\nCidade: ");
    fgets(end.cidade, 49, stdin);
    printf("\nPais: ");
    fgets(end.pais, 49, stdin);
    getchar();
    return end;
}

Contrato lerContrato(){
    Contrato c;
    printf("\nCodigo do contrato: ");
    scanf("%d", &c.codigo);
    printf("\nData de assinatura: ");
    c.dataAss = lerData();
    printf("\nSalario: R$");
    scanf("%f", &c.salario);
    getchar();
    return c;
}

Jogador lerJogador(){
    Jogador j;
    printf("\nNome: ");
    fgets(j.nome, 49, stdin);
    printf("\nData de nascimento: ");
    j.dataNas = lerData();
    j.contr = lerContrato();
    j.end = lerEndereco();
    return j;
}


void inserir_na_fila(No **fila, Jogador jogador){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->j = jogador;
        novo->proximo = NULL;
        if(*fila == NULL)
            *fila = novo;
        else{
            aux = *fila;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("\nErro ao alocar memoria.\n");
}

No* remover_da_fila(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }
    else
        printf("\tFila vazia\n");
    return remover;
}

void imprimir(No *fila){
    printf("\t------- FILA --------\n\t");
    while(fila){
        imprirJogador(fila->j);
        fila = fila->proximo;
        if(fila)
            printf("\t-----------------------\n\t");
    }
    printf("\n\t------- FIM FILA --------\n");
}

int main(){
    No *r, *fila = NULL;
    int opcao;
    Jogador j;

    do{
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
        case 1:
            j = lerJogador();
            inserir_na_fila(&fila, j);
            break;
        case 2:
            r = remover_da_fila(&fila);
            if(r){
                imprirJogador(r->j);
                free(r);
            }
            break;
        case 3:
            imprimir(fila);
            break;
        default:
            if(opcao != 0)
                printf("\nOpcao invaluda!\n");
        }

    }while(opcao != 0);

    return 0;
}

