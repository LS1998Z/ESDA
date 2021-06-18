#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Jogador {
    char nome[40], apelido[20];
    int nrGolos, id, ativo;
    char dataIn[20], dataFim[20];
    int idEquipa;
};

struct Equipa {
    char nome[25];
    int id;
};

/*LISTAR JOGADORES*/
void lista_jogador();
void lista_equipe();
void cadastrar_equipe();
void cadastrar_jogador();

int main() {
    int escolha;
    printf("Escolha:\n1. para listar jogadores\n 2.listar equipas\n 3. cadastrar equipa\n 4. cadastrar jogador\nInsira: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            lista_jogador();
            break;
        case 2:
            lista_equipe();
            break;
        case 3:
            cadastrar_equipe();
            break;
        case 4:
            cadastrar_jogador();
            break;
        default:
            printf("%d",id_ultimaEquipa());
    }

    return (EXIT_SUCCESS);
}

void lista_jogador() {
    FILE *ficheiro;
    ficheiro = fopen("Jogadores.txt", "rb");

    if (ficheiro == NULL) {
        ficheiro = fopen("Jogadores.txt", "wb");
        printf("Erro ao abrir!!!\n");
        exit(1);
    }
    struct Jogador jogador;
    while (fread(&jogador, sizeof (struct Jogador), 1, ficheiro)) {
        printf("\nNome: %s \n", jogador.nome);
        printf("Apelido: %s \n", jogador.apelido);
        printf("Idade: %s \n", jogador.dataIn);
        printf("Idade: %s \n", jogador.dataFim);
        printf("Numero de Golos: %d \n", jogador.nrGolos);
        printf("Equipa: %d \n", jogador.ativo);
    };
    fclose(ficheiro);
}

void lista_equipe() {
    FILE *ficheiro;
    ficheiro = fopen("Equipes.txt", "rb");

    if (ficheiro == NULL) {
        ficheiro = fopen("Equipes.txt", "wb");
        printf("Erro ao abrir o ficheiro!!!");

    }
    struct Equipa equipa;
    while (fread(&equipa, sizeof (struct Equipa), 1, ficheiro) == 1) {
        printf("%d. %s \n", equipa.id, equipa.nome);
    }
    fclose(ficheiro);
}

/**Adicionar Jogador*/
void cadastrar_jogador() {
    bool aberto = true;

    FILE *ficheiro;
    ficheiro = fopen("Jogadores.txt", "ab");

    if (ficheiro == NULL) {
        ficheiro = fopen("Jogadores.txt", "wb");
        printf("Ficheiro nao encontrado!!!");

    }

    int i = 0, golos = 0, ativo = 0;
    char nome[50], apelido[50];
    char dataIn[20], dataFim[20];
    struct Jogador jogador;

    //Entrada do nome

    printf("Nome do Jogador: ");
    scanf("%s", &nome);
    setbuf(stdin, NULL);



    //Entrada de Apelido

    printf("Apelido do Jogador: ");
    scanf("%s", &apelido);
    setbuf(stdin, NULL);

    //Entrada do ano de Inicio

    printf("Data do Inicio do contrato: ");
    scanf("%s", &dataIn);
    setbuf(stdin, NULL);

    printf("Data do final do contrato: ");
    scanf("%s", &dataFim);
    setbuf(stdin, NULL);

    printf("status: ");
    scanf("%i", &ativo);
    setbuf(stdin, NULL);


    printf("Numero de Golos do Jogador: ");
    scanf("%i", &golos);
    setbuf(stdin, NULL);

    FILE *ficheiroE;
    ficheiroE = fopen("Equipes.txt", "rb");

    if (ficheiroE == NULL) {
        printf("Ficheiro de equipes nao encontrado!!!");
        exit(1);
    }

    
    int idEquipa;
    printf("Numero da equipa: ");
    scanf("%i", &idEquipa);
    setbuf(stdin, NULL);

    strcpy(jogador.nome, nome);
    strcpy(jogador.apelido, apelido);
    strcpy(jogador.dataIn, dataIn);
    strcpy(jogador.dataFim, dataFim);
    jogador.nrGolos = golos;
    jogador.ativo = ativo;
    jogador.idEquipa = idEquipa;
    jogador.id = id_ultimoJogador() + 1;

    if (fwrite(&jogador, sizeof (struct Jogador), 1, ficheiro) == 1) {
        printf("\n\t\t\t\t\t\tJogador Cadastrado com Sucesso....\n");
    } else {
        printf("Erro ao cadastar!!!\n");
    }

    setbuf(stdin, NULL);
    fclose(ficheiro);
}

/**Adicionar Equipe*/
void cadastrar_equipe() {
    int id = id_ultimaEquipa() + 1;
    FILE *ficheiro;
    ficheiro = fopen("Equipes.txt", "ab");

    if (ficheiro == NULL) {
        ficheiro = fopen("Equipes.txt", "wb");
        printf("Erro ao abrir o arquivo!!!");

    }


    char nome[50];
    struct Equipa equipa;

    //Entrada do nome

    printf("Nome da Equipe: ");
    scanf("%s", &nome);
    setbuf(stdin, NULL);

    equipa.id = id;
    strcpy(equipa.nome,nome);
    if (fwrite(&equipa, sizeof (equipa), 1, ficheiro) == 1) {
        printf("\n\t\t\t\t\tEquipe Cadastrada com Sucesso....\n");
    } else {
        printf("O nome da Equipe introduzido, Constam no Ficheiro!!!");
        exit(1);
    }

    fclose(ficheiro);
}

int numero_de_Equipes() {
    FILE *ficheiro;
    int quantidade = 0;

    ficheiro = fopen("Equipes.txt", "rb");

    if (ficheiro == NULL) {
        ficheiro = fopen("Equipes.txt", "wb");
        printf("Ficheiro nao encontrado de Equipes!!!");

    }
    struct Equipa equipa;
    while (fread(&equipa, sizeof (struct Equipa), 1, ficheiro)) {
        quantidade++;

    }
    fclose(ficheiro);
    return quantidade;


}

int id_ultimoJogador() {
    FILE *ficheiro;

    ficheiro = fopen("Jogadores.txt", "rb");

    if (ficheiro == NULL) {
        ficheiro = fopen("Jogadores.txt", "wb");
        printf("Ficheiro nao encontrado de Equipes!!!");

    }

    struct Jogador jogad;
    fseek(ficheiro, -sizeof (struct Jogador), SEEK_END);
    int n = fread(&jogad, sizeof (struct Equipa), 1, ficheiro);
    if (n != 1) {
        return 0;
    }
    fclose(ficheiro);
    return jogad.id;

}

int id_ultimaEquipa() {
    FILE *ficheiro;

    ficheiro = fopen("Equipes.txt", "rb");

    if (ficheiro == NULL) {
        ficheiro = fopen("equipas.txt", "wb");
        printf("Ficheiro nao encontrado de Equipes!!!");

    }

    struct Equipa equipa;
    fseek(ficheiro, -sizeof (struct Equipa), SEEK_END);
    int n = fread(&equipa, sizeof (struct Equipa), 1, ficheiro);
    if (n != 1) {
        return 0;
    }
    fclose(ficheiro);
    return equipa.id;
}

