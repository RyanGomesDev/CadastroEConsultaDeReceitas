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
	FILE *listamilkshake;  /*Criação de pastas de armazenamento*/
	FILE *listapastel;
	FILE *listapizza;
	
 	typedef struct
	{
		int id;
 		char nome[30];
 		char ingrediente[30][30];
 		char passos[30][50];
	} receita;
	
	receita bolo[30], trufa[30], milkshake[30], pastel[30], pizza[30];
	
	int Opcao1, Opcao2, i=0, ContadorCadastro, ContadorIngredientes=0, ContadorPassos=0, Exibir=0;
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
		scanf("%d", &Opcao1);
		
		switch (Opcao1)
		{
			/******************* FIM CADASTRO DAS RECEITAS *******************/
			case 1:
				printf("\n-> Escolha o tipo de receita que você quer cadastrar:\n\n");
				printf("---    --------\n|1| -> | Bolo |\n---    ---------\n|2| -> | Trufa |\n---    -------------\n|3| -> | Milkshake |\n---    -------------\n|4| -> | Pastel |\n---    ----------\n|5| -> | Pizza |\n---    ---------\n\n-> Opção: ");
				scanf("%d", &Opcao2);
				printf("\n");
				ContadorCadastro = 0;
				
				switch (Opcao2)
				{
					/*******************INICIO CADASTRO DO BOLO**************************/
					case 1:
						
						for(ContadorCadastro=0; ContadorCadastro<=29; ContadorCadastro++)//Achar uma receita vazia
						{
						
							if(bolo[ContadorCadastro].id == 0)
							{
								
								listabolo = fopen("receitaX.txt", "a");//Comando para abrir o arquivo(Incluir dados)
								printf("-> Digite o nome da receita: ");
								scanf(" %[^\n]s", bolo[ContadorCadastro].nome);
								printf("\n\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro dos Ingredientes |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DOS INGREDIENTES <--\n\n");
								//Adicionando os dados no arquivo
								fprintf(listabolo, "1\n");//Adicionando o ID
								strcat(bolo[ContadorCadastro].nome, "\n");
								fprintf(listabolo, bolo[ContadorCadastro].nome);//Adicionando o nome
								//Fim da gravação de dados
								while(ContadorIngredientes<=29) //Adicionando os ingredientes
								{
									printf("-> Adicione o ingrediente número %d: ", ContadorIngredientes+1);
									scanf(" %[^\n]s", bolo[ContadorCadastro].ingrediente[ContadorIngredientes]);
									//Adicionando os dados no arquivo
									strcat(bolo[ContadorCadastro].ingrediente[ContadorIngredientes], "\n");
									fprintf(listabolo, bolo[ContadorCadastro].ingrediente[ContadorIngredientes]);
									//Fim da gravação de dados
									if(strcmp(bolo[ContadorCadastro].ingrediente[ContadorIngredientes], "fim\n"))
									{
										ContadorIngredientes++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DOS INGREDIENTES <--\n\n");
										ContadorIngredientes=31;
									}
								}
								
								printf("\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro do Passo a Passo |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DO PASSO A PASSO <--\n\n");
								
								while(ContadorPassos<=29) //Adicionando os passos
								{
									printf("-> Adicione o passo número %d: ", ContadorPassos+1);
									scanf(" %[^\n]s", bolo[ContadorCadastro].passos[ContadorPassos]);
									//Adicionando os dados no arquivo
									strcat(bolo[ContadorCadastro].passos[ContadorPassos], "\n");
									fprintf(listabolo, bolo[ContadorCadastro].passos[ContadorPassos]);
									//Fim da gravação de dados
									if(strcmp(bolo[ContadorCadastro].passos[ContadorPassos], "fim\n"))
									{
										ContadorPassos++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DO PASSO A PASSO <--\n\n");
										ContadorPassos=31;
									}
								}
								printf("\t\t\t\t\t----------------------------------\n\t\t\t\t\t| Cadastro Realizado Com Sucesso |\n\t\t\t\t\t----------------------------------\n\n");
								printf("\t\t\t\t\t----------------------------------\n\t\t\t\t\t| RECEITA CADASTRADA : |\n\t\t\t\t\t----------------------------------\n\n");
								printf("-> Receita: %s\n\n-> Lista dos Ingredientes: \n\n", bolo[ContadorCadastro].nome);
								
								for(Exibir=0; Exibir<=29; Exibir++)//Amostrando os ingredientes
								{
									if(strcmp(bolo[ContadorCadastro].ingrediente[Exibir], "fim\n"))
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
									if(strcmp(bolo[ContadorCadastro].passos[Exibir], "fim\n"))
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
						//Fechamento da lista bolo
						fclose(listabolo);
						listabolo = fopen("listabolo.txt", "r");
						if(listabolo == NULL){
							printf("Arquivo nao pode ser aberto");
							system("pause");
							return 0;
						}
						char frase[100];
						while(fgets(frase, 100, listabolo) != NULL){
							printf("%s", frase);
						}
						fclose(listabolo);
						break; 
					/******************* FIM CADASTRO DO BOLO *******************/
					/******************* INICIO CADASTRO DO TRUFA *******************/
					case 2:
						fopen("listatrufa.txt", "w");//Abertura da pasta trufa

						for(ContadorCadastro=0; ContadorCadastro<=29; ContadorCadastro++)
						{//Achar uma receita vazia
						
							if(trufa[ContadorCadastro].id == 0)
							{
								printf("-> Digite o nome da receita: ");
								scanf(" %[^\n]s", trufa[ContadorCadastro].nome);
								printf("\n\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro dos Ingredientes |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DOS INGREDIENTES <--\n\n");
								
								while(ContadorIngredientes<=29) //Adicionando os ingredientes
								{
									printf("-> Adicione o ingrediente número %d: ", ContadorIngredientes+1);
									scanf(" %[^\n]s", trufa[ContadorCadastro].ingrediente[ContadorIngredientes]);
									if(strcmp(trufa[ContadorCadastro].ingrediente[ContadorIngredientes], "fim"))
									{
										ContadorIngredientes++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DOS INGREDIENTES <--\n\n");
										ContadorIngredientes=31;
									}
								}
								
								printf("\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro do Passo a Passo |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DO PASSO A PASSO <--\n\n");
								
								while(ContadorPassos<=29) //Adicionando os passos
								{
									printf("-> Adicione o passo número %d: ", ContadorPassos+1);
									scanf(" %[^\n]s", trufa[ContadorCadastro].passos[ContadorPassos]);
									if(strcmp(trufa[ContadorCadastro].passos[ContadorPassos], "fim"))
									{
										ContadorPassos++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DO PASSO A PASSO <--\n\n");
										ContadorPassos=31;
									}
								}
								
								printf("\t\t\t\t\t----------------------------------\n\t\t\t\t\t| Cadastro Realizado Com Sucesso |\n\t\t\t\t\t----------------------------------\n\n");
								printf("-> Receita: %s\n\n-> Lista dos Ingredientes: \n\n", trufa[ContadorCadastro].nome);
								
								for(Exibir=0; Exibir<=29; Exibir++)//Amostrando os ingredientes
								{
									if(strcmp(trufa[ContadorCadastro].ingrediente[Exibir], "fim"))
									{
										printf("-> %s\n", trufa[ContadorCadastro].ingrediente[Exibir]);
									}
									else
									{
										Exibir=31;
									}
								}
								
								printf("\n-> Passo a Passo: \n\n");
								
								for(Exibir=0; Exibir<=29; Exibir++)//Amostrando o passo a passo
								{
									if(strcmp(trufa[ContadorCadastro].passos[Exibir], "fim"))
									{
										printf("-> Passo número %d: %s\n", Exibir+1, trufa[ContadorCadastro].passos[Exibir]);
									}
									else
									{
										Exibir=31;
									}
								}
								
								trufa[ContadorCadastro].id=1;
								ContadorCadastro=31;
							}
						}
						//Fechamento da lista trufa
						fclose(listatrufa);
						break; 
					/******************* FIM CADASTRO DO TRUFA *******************/
					/******************* INICIO CADASTRO DO MILKSHAKE *******************/
					case 3:
						fopen("listamilkshake.txt", "w");//Abertura da pasta milkshake
						for(ContadorCadastro=0; ContadorCadastro<=29; ContadorCadastro++)
						{//Achar uma receita vazia
						
							if(milkshake[ContadorCadastro].id == 0)
							{
								printf("-> Digite o nome da receita: ");
								scanf(" %[^\n]s", milkshake[ContadorCadastro].nome);
								printf("\n\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro dos Ingredientes |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DOS INGREDIENTES <--\n\n");
								
								while(ContadorIngredientes<=29) //Adicionando os ingredientes
								{
									printf("-> Adicione o ingrediente número %d: ", ContadorIngredientes+1);
									scanf(" %[^\n]s", milkshake[ContadorCadastro].ingrediente[ContadorIngredientes]);
									
									if(strcmp(milkshake[ContadorCadastro].ingrediente[ContadorIngredientes], "fim"))
									{
										ContadorIngredientes++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DOS INGREDIENTES <--\n\n");
										ContadorIngredientes=31;
									}
								}
								
								printf("\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro do Passo a Passo |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DO PASSO A PASSO <--\n\n");
								
								while(ContadorPassos<=29) //Adicionando os passos
								{
									printf("-> Adicione o passo número %d: ", ContadorPassos+1);
									scanf(" %[^\n]s", milkshake[ContadorCadastro].passos[ContadorPassos]);
									
									if(strcmp(milkshake[ContadorCadastro].passos[ContadorPassos], "fim"))
									{
										ContadorPassos++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DO PASSO A PASSO <--\n\n");
										ContadorPassos=31;
									}
								}
								
								printf("\t\t\t\t\t----------------------------------\n\t\t\t\t\t| Cadastro Realizado Com Sucesso |\n\t\t\t\t\t----------------------------------\n\n");
								printf("-> Receita: %s\n\n-> Lista dos Ingredientes: \n\n", milkshake[ContadorCadastro].nome);
								
								for(Exibir=0; Exibir<=29; Exibir++)//Amostrando os Ingredientes
								{
									if(strcmp(milkshake[ContadorCadastro].ingrediente[Exibir], "fim"))
									{
										printf("-> %s\n", milkshake[ContadorCadastro].ingrediente[Exibir]);
									}
									else
									{
										Exibir=31;
									}
								}
								
								printf("\n-> Passo a Passo: \n\n");
								
								for(Exibir=0; Exibir<=29; Exibir++)//Amostrando os Passos
								{
									if(strcmp(milkshake[ContadorCadastro].passos[Exibir], "fim"))
									{
										printf("-> Passo número %d: %s\n", Exibir+1, milkshake[ContadorCadastro].passos[Exibir]);
									}
									else
									{
										Exibir=31;
									}
								}
								
								milkshake[ContadorCadastro].id=1;
								ContadorCadastro=31;
							}
						}
						//Fechamento da lista milkshake
						fclose(listamilkshake);
						break;
					/******************* FIM CADASTRO DO MILKSHAKE *******************/
					/******************* INICIO CADASTRO DO PASTEL *******************/
					case 4:
						fopen("listapastel.txt", "w");//Abertura da pasta pastel
						
						
						for(ContadorCadastro=0; ContadorCadastro<=29; ContadorCadastro++)
						{//Achar uma receita vazia
						
							if(pastel[ContadorCadastro].id == 0)
							{
								printf("-> Digite o nome da receita: ");
								scanf(" %[^\n]s", pastel[ContadorCadastro].nome);
								printf("\n\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro dos Ingredientes |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DOS INGREDIENTES <--\n\n");
								
								while(ContadorIngredientes<=29) //Adicionando os ingredientes
								{
									printf("-> Adicione o ingrediente número %d: ", ContadorIngredientes+1);
									scanf(" %[^\n]s", pastel[ContadorCadastro].ingrediente[ContadorIngredientes]);

									if(strcmp(pastel[ContadorCadastro].ingrediente[ContadorIngredientes], "fim"))
									{
										ContadorIngredientes++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DOS INGREDIENTES <--\n\n");
										ContadorIngredientes=31;
									}
								}
								
								printf("\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro do Passo a Passo |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DO PASSO A PASSO <--\n\n");
								
								while(ContadorPassos<=29) //Adicionando os passos
								{
									printf("-> Adicione o passo número %d: ", ContadorPassos+1);
									scanf(" %[^\n]s", pastel[ContadorCadastro].passos[ContadorPassos]);
									
									if(strcmp(pastel[ContadorCadastro].passos[ContadorPassos], "fim"))
									{
										ContadorPassos++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DO PASSO A PASSO <--\n\n");
										ContadorPassos=31;
									}
								}
								
								printf("\t\t\t\t\t----------------------------------\n\t\t\t\t\t| Cadastro Realizado Com Sucesso |\n\t\t\t\t\t----------------------------------\n\n");
								printf("-> Receita: %s\n\n-> Lista dos Ingredientes: \n\n", pastel[ContadorCadastro].nome);
								
								for(Exibir=0; Exibir<=29; Exibir++)//Amostrando os ingredientes
								{
									if(strcmp(pastel[ContadorCadastro].ingrediente[Exibir], "fim"))
									{
										printf("-> %s\n", pastel[ContadorCadastro].ingrediente[Exibir]);
									}
									else
									{
										Exibir=31;
									}
								}
								
								printf("\n-> Passo a Passo: \n\n");
								
								for(Exibir=0; Exibir<=29; Exibir++)//Amostrando os passos
								{
									if(strcmp(pastel[ContadorCadastro].passos[Exibir], "fim"))
									{
										printf("-> Passo número %d: %s\n", Exibir+1, pastel[ContadorCadastro].passos[Exibir]);
									}
									else
									{
										Exibir=31;
									}
								}
								
								pastel[ContadorCadastro].id=1;
								ContadorCadastro=31;
							}
						}
						//Fechamento da lista pastel
						fclose(listapastel);
						break;
					/******************* FIM CADASTRO DO PASTEL *******************/
					/******************* INICO CADASTRO DA PIZZA *******************/
					case 5:
						fopen("listapizza.txt", "w");//Abertura da pasta pizza
						for(ContadorCadastro=0; ContadorCadastro<=29; ContadorCadastro++)
						{//Achar uma receita vazia
						
							if(pizza[ContadorCadastro].id == 0)
							{
								printf("-> Digite o nome da receita: ");
								scanf(" %[^\n]s", pizza[ContadorCadastro].nome);
								printf("\n\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro dos Ingredientes |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DOS INGREDIENTES <--\n\n");
								
								while(ContadorIngredientes<=29) //Adicionando os ingredientes
								{
									printf("-> Adicione o ingrediente número %d: ", ContadorIngredientes+1);
									scanf(" %[^\n]s", pizza[ContadorCadastro].ingrediente[ContadorIngredientes]);
									
									if(strcmp(pizza[ContadorCadastro].ingrediente[ContadorIngredientes], "fim"))
									{
										ContadorIngredientes++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DOS INGREDIENTES <--\n\n");
										ContadorIngredientes=31;
									}
								}
								
								printf("\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro do Passo a Passo |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DO PASSO A PASSO <--\n\n");
								
								while(ContadorPassos<=29) //Adicionando os passos
								{
									printf("-> Adicione o passo número %d: ", ContadorPassos+1);
									scanf(" %[^\n]s", pizza[ContadorCadastro].passos[ContadorPassos]);
									
									if(strcmp(pizza[ContadorCadastro].passos[ContadorPassos], "fim"))
									{
										ContadorPassos++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DO PASSO A PASSO <--\n\n");
										ContadorPassos=31;
									}
								}
								
								printf("\t\t\t\t\t----------------------------------\n\t\t\t\t\t| Cadastro Realizado Com Sucesso |\n\t\t\t\t\t----------------------------------\n\n");
								printf("-> Receita: %s\n\n-> Lista dos Ingredientes: \n\n", pizza[ContadorCadastro].nome);
								
								for(Exibir=0; Exibir<=29; Exibir++)//Amostrando os ingredientes
								{
									if(strcmp(pizza[ContadorCadastro].ingrediente[Exibir], "fim"))
									{
										printf("-> %s\n", pizza[ContadorCadastro].ingrediente[Exibir]);
									}
									else
									{
										Exibir=31;
									}
								}
								
								printf("\n-> Passo a Passo: \n\n");//Amostrando os passos
								
								for(Exibir=0; Exibir<=29; Exibir++)
								{
									if(strcmp(pizza[ContadorCadastro].passos[Exibir], "fim"))
									{
										printf("-> Passo número %d: %s\n", Exibir+1, pizza[ContadorCadastro].passos[Exibir]);
									}
									else
									{
										Exibir=31;
									}
								}
								
								pizza[ContadorCadastro].id=1;
								ContadorCadastro=31;
							}
						}
						//Fechamento da lista pizza
						fclose(listapizza);
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
				scanf("%d", &Opcao2);
				break;
		}
	} while(Opcao1!=3);
	
	printf("\n\t\t\t\t\t\t------------\n\t\t\t\t\t\t| Creditos |\n\t\t\t\t\t\t------------\n\n\t\t\t\t\t\tProgramadores\n\n\t\t\t\t\t     Jonathan Fernandes\n\t\t\t\t\t\t Oscar Alves\n\t\t\t\t\t\t Ryan Gomes\n\n");
	
 	system("pause");
 	return 0;
}
