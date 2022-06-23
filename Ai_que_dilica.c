#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 100

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	//******************* Inicio Criação das variaveis *************************/
 	typedef struct
	{
 		char nome[30];
 		char ingrediente[30][30];
 		char passos[30][50];
	} receita;
	receita bolo[30], trufa[30], milkshake[30], pastel[30], pizza[30];
	int opcao, opcao2, i=0;
	
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
		
		switch (opcao)
		{
		case 1:
			printf("\n-> Escolha o tipo de receita que você quer cadastrar:\n\n");
			printf("---    --------\n|1| -> | Bolo |\n---    ---------\n|2| -> | Trufa |\n---    -------------\n|3| -> | Milkshake |\n---    -------------\n|4| -> | Pastel |\n---    ----------\n|5| -> | Pizza |\n---    ---------\n\n-> Opção: \n\n");
			scanf("%d", &opcao2);
			switch (opcao2){
				case 1:
					printf("Digite o nome da receita: ");
					scanf(" %[^\n]s", bolo[0].nome);
					printf(" %s", bolo[0].nome);
			}
			break;
		case 2:
			printf("Digite o tipo ");
			break;
		}
	} while(opcao!=3);
	
	printf("\n\t\t\t\t\t\t------------\n\t\t\t\t\t\t| Creditos |\n\t\t\t\t\t\t------------\n\n\t\t\t\t\t\tProgramadores\n\n\t\t\t\t\t     Jonathan Fernandes\n\t\t\t\t\t\t Oscar Alves\n\t\t\t\t\t\t Ryan Gomes\n\n");
	
 	system("pause");
 	return 0;
}
