#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	//*** Inicio Criação das variaveis ***/
	FILE *listabolo;
	FILE *listatrufa;
	FILE *listamilkshake;  /*Criação dos ponteiros*/
	FILE *listapastel;
	FILE *listapizza;
	
 	typedef struct
	{
		int id;
 		char nome[50];
 		char ingrediente[30][200];
 		char passos[30][200];
	} receita;
	
	receita bolo[30], trufa[30], milkshake[30], pastel[30], pizza[30];
	
	int OpcaoAcao, OpcaoCadastro, OpcaoConsulta, i=0, ContadorCadastro, ContadorIngredientes=0, ContadorPassos=0, Exibir=0;
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
	
	/*** Fim Criação das variaveis ***/
	/************************************** INICIO DO PROGRAMA *************************************/
	do{
		puts("\t\t\t\t\t\t---------------\n\t\t\t\t\t\t|AI QUI DILICA|\n\t\t\t\t\t\t---------------\n");
		printf("\t\t\t\t\t---    ----------------------\n\t\t\t\t\t|1| -> | Cadastrar receita |\n\t\t\t\t\t---    ----------------------\n\t\t\t\t\t---    ---------------------\n\t\t\t\t\t|2| -> | Consultar receita |\n\t\t\t\t\t---    ---------------------\n\t\t\t\t\t---    --------------------\n\t\t\t\t\t|3| -> | Sair do programa |\n\t\t\t\t\t---    --------------------\n\t\t\t\t\t-> Opção: ");
		scanf("%d", &OpcaoAcao);
		
		switch (OpcaoAcao)
		{
			/******************* INICIO CADASTRO DAS RECEITAS *******************/
			case 1:
				printf("\n-> Escolha o tipo de receita que você quer cadastrar:\n\n");
				printf("---    --------\n|1| -> | Bolo |\n---    ---------\n|2| -> | Trufa |\n---    -------------\n|3| -> | Milkshake |\n---    -------------\n|4| -> | Pastel |\n---    ----------\n|5| -> | Pizza |\n---    ---------\n\n-> Opção: ");
				scanf("%d", &OpcaoCadastro);
				printf("\n");
				ContadorCadastro = 0;
				
				switch (OpcaoCadastro)
				{
					/*******************INICIO CADASTRO DO BOLO**************************/
					case 1:
						
						for(ContadorCadastro=0; ContadorCadastro<=29; ContadorCadastro++)//Achar uma receita vazia
						{
							ContadorIngredientes=0, ContadorPassos=0;
							if(bolo[ContadorCadastro].id == 0)
							{
								
								listabolo = fopen("receitasbolo.txt", "a");//Comando para abrir o arquivo(Incluir dados)
								printf("-> Digite o nome da receita: ");
								scanf(" %[^\n]s", bolo[ContadorCadastro].nome);
								printf("\n\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro dos Ingredientes |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DOS INGREDIENTES <--\n\n");
								//Adicionando o NOME no arquivo
								fprintf(listabolo, "*********************\n");//Estilização 
								fprintf(listabolo, "*Nome da Receita: *\n");//Estilização 
								strcat(bolo[ContadorCadastro].nome, "\n");
								fprintf(listabolo, bolo[ContadorCadastro].nome);//Adicionando o nome
								fprintf(listabolo, "*Ingredientes*: \n");//Estilização 
								//Fim da gravação de dados
								while(ContadorIngredientes<=29) //Adicionando os ingredientes
								{
									printf("-> Adicione o ingrediente número %d: ", ContadorIngredientes+1);
									scanf(" %[^\n]s", bolo[ContadorCadastro].ingrediente[ContadorIngredientes]);
									if(strcmp(bolo[ContadorCadastro].ingrediente[ContadorIngredientes], "fim"))
									{
										//Adicionando os dados no arquivo
										strcat(bolo[ContadorCadastro].ingrediente[ContadorIngredientes], " \n");
										fprintf(listabolo, bolo[ContadorCadastro].ingrediente[ContadorIngredientes]);
										//Fim da gravação de dados
										ContadorIngredientes++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DOS INGREDIENTES <--\n\n");
										ContadorIngredientes=31;
										fprintf(listabolo, " \n");
									}
								}
								
								printf("\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro do Passo a Passo |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DO PASSO A PASSO <--\n\n");
								fprintf(listabolo, "*Passo a Passo: *\n");//Estilização 
								while(ContadorPassos<=29) //Adicionando os passos
								{
									printf("-> Adicione o passo número %d: ", ContadorPassos+1);
									scanf(" %[^\n]s", bolo[ContadorCadastro].passos[ContadorPassos]);
									
									if(strcmp(bolo[ContadorCadastro].passos[ContadorPassos], "fim"))
									{
										//Adicionando os dados no arquivo
										strcat(bolo[ContadorCadastro].passos[ContadorPassos], " \n");
										fprintf(listabolo, bolo[ContadorCadastro].passos[ContadorPassos]);
										//Fim da gravação de dados
										ContadorPassos++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DO PASSO A PASSO <--\n\n");
										ContadorPassos=31;
										fprintf(listabolo, " \n");
									}
								}
								printf("\t\t\t\t\t----------------------------------\n\t\t\t\t\t| Cadastro Realizado Com Sucesso |\n\t\t\t\t\t----------------------------------\n\n");
								printf("\t\t\t\t\t----------------------------------\n\t\t\t\t\t| RECEITA CADASTRADA : |\n\t\t\t\t\t----------------------------------\n\n");
								printf("-> Receita: %s\n\n-> Lista dos Ingredientes: \n\n", bolo[ContadorCadastro].nome);
								
								for(Exibir=0; Exibir<=29; Exibir++)//Amostrando os ingredientes
								{
									if(strcmp(bolo[ContadorCadastro].ingrediente[Exibir], "fim"))
									{
										printf("-> %s\n", bolo[ContadorCadastro].ingrediente[Exibir]);
									}
									else
									{
										Exibir=31;
									}
								}
								
								printf("\n-> Passo a Passo: \n\n");
								
								for(Exibir=0; Exibir<=29; Exibir++)//Amostrando os Passos
								{
									if(strcmp(bolo[ContadorCadastro].passos[Exibir], "fim"))
									{
										printf("-> Passo número %d: %s\n", Exibir+1, bolo[ContadorCadastro].passos[Exibir]);
									}
									else
									{
										Exibir=31;
									}
								}
								
								bolo[ContadorCadastro].id=1;
								ContadorCadastro=31;
							}
						}
						fclose(listabolo);//Fechamento da lista bolo
						break; 
					/******************* FIM CADASTRO DO BOLO *******************/
					/******************* INICIO CADASTRO DO TRUFA *******************/
					case 2:
						
						break; 
					/******************* FIM CADASTRO DO TRUFA *******************/
					/******************* INICIO CADASTRO DO MILKSHAKE *******************/
					case 3:
					
						break;
					/******************* FIM CADASTRO DO MILKSHAKE *******************/
					/******************* INICIO CADASTRO DO PASTEL *******************/
					case 4:
						
						break;
					/******************* FIM CADASTRO DO PASTEL *******************/
					/******************* INICO CADASTRO DA PIZZA *******************/
					case 5:
						
						break; 
					/******************* FIM CADASTRO DA PIZZA *******************/
				}
			break;
				/******************* FIM CADASTRO DAS RECEITAS *******************/
			
			
				/*---------------------------------------------------------------------
				-----------------------------------------------------------------------
			
			
				*/
				/******************* INICIO CONSULTA DAS RECEITAS*******************/
			
			case 2:
				printf("\n-> Escolha o tipo de receita que você quer consultar:\n\n");
				printf("---    --------\n|1| -> | Bolo |\n---    ---------\n|2| -> | Trufa |\n---    -------------\n|3| -> | Milkshake |\n---    -------------\n|4| -> | Pastel |\n---    ----------\n|5| -> | Pizza |\n---    ---------\n\n-> Opção: \n\n");
				scanf("%d", &OpcaoConsulta);
				switch(OpcaoConsulta){
					case 1://***********************************INICIO CONSULTA DAS RECEITAS DO BOLO ********************************//
						listabolo = fopen("receitasbolo.txt", "r");
						if(listabolo == NULL){
							printf("Arquivo nao pode ser aberto");
							system("pause");
							return 0;
						}
						char frase[200];
						while(fgets(frase, 200, listabolo) != NULL){
								printf("%s", frase);
						}
					break;
					//********************************** FIM CONSULTA DAS RECEITAS DO BOLO ********************************//
				}
			break;
		}
	} while(OpcaoAcao!=3);
	
	printf("\n\t\t\t\t\t\t------------\n\t\t\t\t\t\t| Creditos |\n\t\t\t\t\t\t------------\n\n\t\t\t\t\t\tProgramadores\n\n\t\t\t\t\t     Jonathan Fernandes\n\t\t\t\t\t\t Oscar Alves\n\t\t\t\t\t\t Ryan Gomes\n\n");
	
 	system("pause");
 	return 0;
}
