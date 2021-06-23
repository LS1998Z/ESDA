#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


struct equipa {
	char nome[15];
	int id;
};

struct jogador{
	int id, nGolos, id_eq;
	char nome[25];
	char apelido[15];
	char dat_Inicio[30];
	char dat_Fim[30];
	char ativo[10];	
};

void menu();
void cad_eq();
void cad_jog();
void list_eq();
void list_jog();

int main(void){
	int op;
	
	do{
		menu();
		printf("****** Escolha uma das opcoes *******\n\n");
		printf("1 - Cadastrar Equipa \n");
		printf("2 - Cadastrar Jogador \n");
		printf("3 - Listar  Equipas\n");
		printf("4 - Listar  Jogadores\n");
		printf("5 - Para sair \n");
		printf("6 - Remover jogador com maior numero de golos \n");
		
		scanf("%i", &op);
		
		switch(op){
			case 1:
					system("cls");
					cad_eq();
					break;
			
		
			case 2:
					system("cls");
					cad_jog();
					break;
					
		
			case 3:
					system("cls");
					list_eq();
					break;			
					
		
			case 4:
					system("cls");
					list_jog();
					
					break;
										
			case 5:
					system("cls");
					printf("FIM PROGRAMA!");
					break;
					
			case 6 : 	
			
					break;
						
				
			default:
				system("cls");
				printf("Opcao invalida Escolha uma opcao valida\n");
				getch();				
			
		}
		
	}while(op != 5);
	
	return 0;}



void menu(){
	system("cls");
	printf("*****************************************\n");
}

void cad_eq(){
	 struct equipa e;
	 struct equipa *pt_e;
	 pt_e = &e;
	 //caso de error reever
	
	FILE* arq;
	 
	arq = fopen("equipa.txt", "ab");
	 
	 if(arq == NULL){
	 	printf("Erro ao abrir arquivo");
	 }else{
	 		fflush(stdin);//buffering do teclado
	 		printf("Digite nome: ");
	 		gets(pt_e->nome);
	 		
	 		fflush(stdin);
	 		printf("Digite Id: ");
	 		scanf("%i",&pt_e->id);
	 		
	 		fwrite(pt_e, sizeof(e), 1, arq);
		 fclose(arq); 
	 }
}


void cad_jog(){
	 struct jogador j;
	 struct jogador *pt_j;
	 pt_j = &j;
	 int cont;
	
	FILE* arq;
	 
   arq = fopen("jogadores.txt", "ab");
	 
	 if(arq == NULL){
	 	printf("Erro ao abrir arquivo");
	 }else{
	 		printf("Cadastro do Jogador\n");
	 		fflush(stdin);
	 		printf("\nDigite nome: ");
	 		gets(pt_j->nome);
	 		fflush(stdin);
	 		printf("\nDigite apelido: ");
	 		gets(pt_j->apelido);
	 		fflush(stdin);
	 		printf("\nDigite Id: ");
	 		scanf("%i",&pt_j->id);
	 		printf("\nDigite Id_Equipa: ");
	 		scanf("%i",&pt_j->id_eq);
	 		printf("\nDigite nmrGolos: ");
	 		scanf("%i",&pt_j->nGolos);
	 		fflush(stdin);
	 		printf("\nDigite data_Inicio do Contrato: ");
	 		gets(pt_j->dat_Inicio);
	 		fflush(stdin);
	 		printf("\nDigite data_Fim do Contrato: ");
	 		gets(pt_j->dat_Fim);
	 		printf("\nDigite 'ATIVO' se o jogador estiver ativo e inativo caso contrario 'INATIVO':\n ");
	 		gets(pt_j->ativo);
	 		
	 		
	 		
	 		
	 		fwrite(pt_j, sizeof(j), 1, arq);

		 fclose(arq); 
	 }
}

void list_eq(){
	struct equipa e;
	struct equipa *pt_e;
	pt_e = &e;
	
	FILE* arq;
	 
 arq = fopen("equipa.txt", "rb");
	 
	 if(arq == NULL){
	 	printf("Erro ao abrir arquivo");
	 }else{
	 	printf("\tDados Equipa\n\n");
	 	while(fread(pt_e, sizeof(e), 1, arq) == 1){
	 		printf("Nome: %s", pt_e->nome);
	 		printf("\nId: %i", pt_e->id);
	 		printf("\n++++++++++++++++++++++\n");
		 }
	 }
	 fclose(arq);
	 getch();
}

void list_jog(){
	 struct jogador j;
	 struct jogador *pt_j;
	 pt_j = &j;
	 int cont;
	
	FILE* arq;
	 
   arq = fopen("jogadores.txt", "rb");
	 
	 if(arq == NULL){
	 	printf("Erro ao abrir arquivo");
	 }else{
	
	 	printf("Dados Jogadores\n\n");
	 	
	 	while(fread(pt_j, sizeof(j), 1, arq) == 1){
	 		printf("ID: %i", pt_j->id);
	 		printf("\nID_Equipa: %i", pt_j->id_eq);
			printf("\nNome: %s", pt_j->nome);
	 		printf("\nApelido: %s", pt_j->apelido);
	 		printf("\nData_Inicio : %s", pt_j->dat_Inicio);
	 		printf("\nData_Fim : %s", pt_j->dat_Fim);
	 		printf("\nNr_Golos : %i", pt_j->nGolos);
	 		printf("\nEstado_Jogador : %s", pt_j->ativo);
			
	 		printf("\n------------------------------\n");
		 }
	 }
	 fclose(arq);
	 getch();
	 	
	 }
	
