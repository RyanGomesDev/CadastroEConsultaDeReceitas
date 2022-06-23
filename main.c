#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	//******************* Inicio Criação das variaveis *************************/
 	typedef struct
	{
		int id;
 		char nome[30];
 		char ingrediente[30][30];
 		char passos[30][50];
	} receita;
	receita bolo[30], trufa[30], milkshake[30], pastel[30], pizza[30];
	int opcao, opcao2, i=0, contb, contt, contm, contp, contz, conting=0, contpassos=0;
	int teste=0;
	/*Escrever
	FILE *file;
	file = fopen("teste.txt", "w");
	fprintf(file,"é menino?");
	fclose(file);
	
	Ler
	FILE *file;
	file = fopen("teste.txt", "w");
	if(file == NULL){
		printf("Arquivo nao pode ser aberto");
		system("pause");
		return 0;
	}
	char frase[100];
	while(fgets(frase, 100, file) != NULL){
		printf("%s", frase);
	}
	fclose(file);
	system("pause");
	return 0;
	
	Incluir Dados
	FILE *file;
	file = fopen("teste.txt", "a");
	if(file == NULL){
		printf("Arquivo nao pode ser aberto");
		system("pause");
		return 0;
	}
	char frase[] = "Segunda linha";
	fputs(frase, file);
	fclose(file);
	system("pause");
	return 0;
	
	/******************** Fim Criação das variaveis ********************/
	/******************** Inicio Programa ********************/
	do{
		puts("\t\t\t\t\t\t---------------\n\t\t\t\t\t\t|AI QUI DILICA|\n\t\t\t\t\t\t---------------\n");
		printf("\t\t\t\t\t---    ----------------------\n\t\t\t\t\t|1| -> | Cadastrar receita |\n\t\t\t\t\t---    ----------------------\n\t\t\t\t\t---    ---------------------\n\t\t\t\t\t|2| -> | Consultar receita |\n\t\t\t\t\t---    ---------------------\n\t\t\t\t\t---    --------------------\n\t\t\t\t\t|3| -> | Sair do programa |\n\t\t\t\t\t---    --------------------\n\t\t\t\t\t-> Opção: ");
		scanf("%d", &opcao);
		
		switch (opcao){
			/******************** Inicio Cadastro Receita ********************/
			case 1:
				printf("\n-> Escolha o tipo de receita que você quer cadastrar:\n\n");
				printf("---    --------\n|1| -> | Bolo |\n---    ---------\n|2| -> | Trufa |\n---    -------------\n|3| -> | Milkshake |\n---    -------------\n|4| -> | Pastel |\n---    ----------\n|5| -> | Pizza |\n---    ---------\n\n-> Opção: \n\n");
				scanf("%d", &opcao2);
				switch (opcao2){
					case 1://Cadastro Bolo
						for(contb=0; contb<=30; contb++){//Achar uma receita vazia
							if(bolo[contb].id == 0){
							printf("Digite o nome da receita: ");
							scanf(" %[^\n]s", bolo[contb].nome);
							printf("Inicio Cadastro dos Ingredientes: \n");
							while(conting<=29){//Adicionando os ingredientes
								printf("Adicione o ingrediente %d ou digite fim para finalizar: ", conting+1);
								scanf(" %[^\n]s", bolo[contb].ingrediente[conting]);
								//printf("O ingrediente escolhido foi: %s\n", bolo[contb].ingrediente[conting]);
								
								if(strcmp(bolo[contb].ingrediente[conting], "fim")){
									conting++;
								}else{
									printf("Fim do cadastro de ingrediente\n");
									conting=31;
								}
								
							}
							printf("Inicio Cadastro do passo a passo: \n");
							while(contpassos<=29){//Adicionando os passos
								printf("Adicione o passo %d ou digite ""fim"" para finalizar: ", contpassos+1);
								scanf(" %[^\n]s", bolo[contb].passos[contpassos]);
								if(strcmp(bolo[contb].passos[contpassos], "fim")){
									
									contpassos++;
								}else{
									printf("Fim do cadastro do passo a passo\n");
									contpassos=31;
								}
								
							}
							printf("Cadastro Realizado Com Sucesso!\n");
							printf("Receita: \n Nome: %s\n", bolo[contb].nome);
							printf("Ingredientes: \n");
							for(teste=0; teste<=29; teste++){
								
									printf("%s\n", bolo[contb].ingrediente[teste]);
									
								
							}
							printf("Passo a Passo: \n");
							for(teste=0; teste<=29; teste++){
								
									printf("%s\n", bolo[contb].passos[teste]);
									
								
							}
							bolo[contb].id=1;
							contb=31;
							}
						}
					break;
				}
			break;
			/******************** Fim Cadastro Receita ********************/
			/******************** Inicio Consulta Receita ********************/
			case 2:
				printf("Digite o tipo ");
				break;
		}
	} while(opcao!=3);
	
	printf("\n\t\t\t\t\t\t------------\n\t\t\t\t\t\t| Creditos |\n\t\t\t\t\t\t------------\n\n\t\t\t\t\t\tProgramadores\n\n\t\t\t\t\t     Jonathan Fernandes\n\t\t\t\t\t\t Oscar Alves\n\t\t\t\t\t\t Ryan Gomes\n\n");
	
 	system("pause");
 	return 0;
}
