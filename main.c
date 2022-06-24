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
	int opcao, opcao2, i=0, contc, conting=0, contpassos=0;
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
				contc = 0;
				switch (opcao2){
					case 1://Cadastro Bolo
						for(contc=0; contc<=29; contc++){//Achar uma receita vazia
							if(bolo[contc].id == 0){
							printf("Digite o nome da receita: ");
							scanf(" %[^\n]s", bolo[contc].nome);
							printf("Inicio Cadastro dos Ingredientes: \n");
							while(conting<=29){//Adicionando os ingredientes
								printf("Adicione o ingrediente %d ou digite fim para finalizar: ", conting+1);
								scanf(" %[^\n]s", bolo[contc].ingrediente[conting]);
								//printf("O ingrediente escolhido foi: %s\n", bolo[contc].ingrediente[conting]);
								
								if(strcmp(bolo[contc].ingrediente[conting], "fim")){
									conting++;
								}else{
									printf("Fim do cadastro de ingrediente\n");
									conting=31;
								}
								
							}
							printf("Inicio Cadastro do passo a passo: \n");
							while(contpassos<=29){//Adicionando os passos
								printf("Adicione o passo %d ou digite ""fim"" para finalizar: ", contpassos+1);
								scanf(" %[^\n]s", bolo[contc].passos[contpassos]);
								if(strcmp(bolo[contc].passos[contpassos], "fim")){
									contpassos++;
								}else{
									printf("Fim do cadastro do passo a passo\n");
									contpassos=31;
								}
								
							}
							printf("Cadastro Realizado Com Sucesso!\n");
							printf("Receita: \n Nome: %s\n", bolo[contc].nome);
							printf("Ingredientes: \n");
							for(teste=0; teste<=29; teste++){
								
									printf("%s\n", bolo[contc].ingrediente[teste]);
									
								
							}
							printf("\n");
							printf("Passo a Passo: \n");
							for(teste=0; teste<=29; teste++){
								
									printf("%s\n", bolo[contc].passos[teste]);
									
								
							}
							bolo[contc].id=1;
							contc=31;
							}
						}
						break;//Fim Cadastro Bolo
					case 2://Cadastro Trufa
						for(contc=0; contc<=29; contc++){//Achar uma receita vazia
							if(trufa[contc].id == 0){
							printf("Digite o nome da receita: ");
							scanf(" %[^\n]s", trufa[contc].nome);
							printf("Inicio Cadastro dos Ingredientes: \n");
							while(conting<=29){//Adicionando os ingredientes
								printf("Adicione o ingrediente %d ou digite fim para finalizar: ", conting+1);
								scanf(" %[^\n]s", trufa[contc].ingrediente[conting]);
								//printf("O ingrediente escolhido foi: %s\n", bolo[contc].ingrediente[conting]);
								
								if(strcmp(trufa[contc].ingrediente[conting], "fim")){
									conting++;
								}else{
									printf("Fim do cadastro de ingrediente\n");
									conting=31;
								}
								
							}
							printf("Inicio Cadastro do passo a passo: \n");
							while(contpassos<=29){//Adicionando os passos
								printf("Adicione o passo %d ou digite ""fim"" para finalizar: ", contpassos+1);
								scanf(" %[^\n]s", trufa[contc].passos[contpassos]);
								if(strcmp(trufa[contc].passos[contpassos], "fim")){
									contpassos++;
								}else{
									printf("Fim do cadastro do passo a passo\n");
									contpassos=31;
								}
								
							}
							printf("Cadastro Realizado Com Sucesso!\n");
							printf("Receita: \n Nome: %s\n", trufa[contc].nome);
							printf("Ingredientes: \n");
							for(teste=0; teste<=29; teste++){
								
									printf("%s\n", trufa[contc].ingrediente[teste]);
									
								
							}
							printf("Passo a Passo: \n");
							for(teste=0; teste<=29; teste++){
								
									printf("%s\n", trufa[contc].passos[teste]);
									
								
							}
							trufa[contc].id=1;
							contc=31;
							}
						}
						break;//Fim Cadastro Trufa
					case 3://Cadastro Milkshake
						for(contc=0; contc<=29; contc++){//Achar uma receita vazia
							if(milkshake[contc].id == 0){
							printf("Digite o nome da receita: ");
							scanf(" %[^\n]s", milkshake[contc].nome);
							printf("Inicio Cadastro dos Ingredientes: \n");
							while(conting<=29){//Adicionando os ingredientes
								printf("Adicione o ingrediente %d ou digite fim para finalizar: ", conting+1);
								scanf(" %[^\n]s", milkshake[contc].ingrediente[conting]);
								//printf("O ingrediente escolhido foi: %s\n", bolo[contc].ingrediente[conting]);
								
								if(strcmp(milkshake[contc].ingrediente[conting], "fim")){
									conting++;
								}else{
									printf("Fim do cadastro de ingrediente\n");
									conting=31;
								}
								
							}
							printf("Inicio Cadastro do passo a passo: \n");
							while(contpassos<=29){//Adicionando os passos
								printf("Adicione o passo %d ou digite ""fim"" para finalizar: ", contpassos+1);
								scanf(" %[^\n]s", milkshake[contc].passos[contpassos]);
								if(strcmp(milkshake[contc].passos[contpassos], "fim")){
									contpassos++;
								}else{
									printf("Fim do cadastro do passo a passo\n");
									contpassos=31;
								}
								
							}
							printf("Cadastro Realizado Com Sucesso!\n");
							printf("Receita: \n Nome: %s\n", milkshake[contc].nome);
							printf("Ingredientes: \n");
							for(teste=0; teste<=29; teste++){
								
									printf("%s\n", milkshake[contc].ingrediente[teste]);
									
								
							}
							printf("Passo a Passo: \n");
							for(teste=0; teste<=29; teste++){
								
									printf("%s\n", milkshake[contc].passos[teste]);
									
								
							}
							milkshake[contc].id=1;
							contc=31;
							}
						}
						break;//Fim Cadastro Milkshake
					case 4://Cadastro Pastel
						for(contc=0; contc<=29; contc++){//Achar uma receita vazia
							if(pastel[contc].id == 0){
							printf("Digite o nome da receita: ");
							scanf(" %[^\n]s", pastel[contc].nome);
							printf("Inicio Cadastro dos Ingredientes: \n");
							while(conting<=29){//Adicionando os ingredientes
								printf("Adicione o ingrediente %d ou digite fim para finalizar: ", conting+1);
								scanf(" %[^\n]s", pastel[contc].ingrediente[conting]);
								//printf("O ingrediente escolhido foi: %s\n", bolo[contc].ingrediente[conting]);
								
								if(strcmp(pastel[contc].ingrediente[conting], "fim")){
									conting++;
								}else{
									printf("Fim do cadastro de ingrediente\n");
									conting=31;
								}
								
							}
							printf("Inicio Cadastro do passo a passo: \n");
							while(contpassos<=29){//Adicionando os passos
								printf("Adicione o passo %d ou digite ""fim"" para finalizar: ", contpassos+1);
								scanf(" %[^\n]s", pastel[contc].passos[contpassos]);
								if(strcmp(pastel[contc].passos[contpassos], "fim")){
									contpassos++;
								}else{
									printf("Fim do cadastro do passo a passo\n");
									contpassos=31;
								}
								
							}
							printf("Cadastro Realizado Com Sucesso!\n");
							printf("Receita: \n Nome: %s\n", pastel[contc].nome);
							printf("Ingredientes: \n");
							for(teste=0; teste<=29; teste++){
								
									printf("%s\n", pastel[contc].ingrediente[teste]);
									
								
							}
							printf("Passo a Passo: \n");
							for(teste=0; teste<=29; teste++){
								
									printf("%s\n", pastel[contc].passos[teste]);
									
								
							}
							pastel[contc].id=1;
							contc=31;
							}
						}
						break;//Fim Cadastro Pastel
					case 5:// Cadastro pizza
						for(contc=0; contc<=29; contc++){//Achar uma receita vazia
							if(pizza[contc].id == 0){
							printf("Digite o nome da receita: ");
							scanf(" %[^\n]s", pizza[contc].nome);
							printf("Inicio Cadastro dos Ingredientes: \n");
							while(conting<=29){//Adicionando os ingredientes
								printf("Adicione o ingrediente %d ou digite fim para finalizar: ", conting+1);
								scanf(" %[^\n]s", pizza[contc].ingrediente[conting]);
								//printf("O ingrediente escolhido foi: %s\n", bolo[contc].ingrediente[conting]);
								
								if(strcmp(pizza[contc].ingrediente[conting], "fim")){
									conting++;
								}else{
									printf("Fim do cadastro de ingrediente\n");
									conting=31;
								}
								
							}
							printf("Inicio Cadastro do passo a passo: \n");
							while(contpassos<=29){//Adicionando os passos
								printf("Adicione o passo %d ou digite ""fim"" para finalizar: ", contpassos+1);
								scanf(" %[^\n]s", pizza[contc].passos[contpassos]);
								if(strcmp(pizza[contc].passos[contpassos], "fim")){
									contpassos++;
								}else{
									printf("Fim do cadastro do passo a passo\n");
									contpassos=31;
								}
								
							}
							printf("Cadastro Realizado Com Sucesso!\n");
							printf("Receita: \n Nome: %s\n", pizza[contc].nome);
							printf("Ingredientes: \n");
							for(teste=0; teste<=29; teste++){
								
									printf("%s\n", pizza[contc].ingrediente[teste]);
									
								
							}
							printf("Passo a Passo: \n");
							for(teste=0; teste<=29; teste++){
								
									printf("%s\n", pizza[contc].passos[teste]);
									
								
							}
							pizza[contc].id=1;
							contc=31;
							}
						}
						break;//Fim Cadastro Pizza
						
				}
			break;
			/******************** Fim Cadastro Receita ********************/
			/******************** Inicio Consulta Receita ********************/
			case 2:
				printf("\n-> Escolha o tipo de receita que você quer consultar:\n\n");
				printf("---    --------\n|1| -> | Bolo |\n---    ---------\n|2| -> | Trufa |\n---    -------------\n|3| -> | Milkshake |\n---    -------------\n|4| -> | Pastel |\n---    ----------\n|5| -> | Pizza |\n---    ---------\n\n-> Opção: \n\n");
				scanf("%d", &opcao2);
				break;
		}
	} while(opcao!=3);
	
	printf("\n\t\t\t\t\t\t------------\n\t\t\t\t\t\t| Creditos |\n\t\t\t\t\t\t------------\n\n\t\t\t\t\t\tProgramadores\n\n\t\t\t\t\t     Jonathan Fernandes\n\t\t\t\t\t\t Oscar Alves\n\t\t\t\t\t\t Ryan Gomes\n\n");
	
 	system("pause");
 	return 0;
}
