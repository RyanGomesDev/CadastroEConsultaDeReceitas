#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int main(void)
{
	//*** Setando os caracteres da língua portuguesa no código***//
	setlocale(LC_ALL, "Portuguese");
	//*** Inicio Criação das variaveis ***//
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
	/*** Fim Criação das variaveis ***/
	/************************************** INICIO DO PROGRAMA *************************************/
	do{
		puts("\t\t\t\t\t    ---------------------\n\t\t\t\t\t    | BANCO DE RECEITAS |\n\t\t\t\t\t    ---------------------\n");
		printf("\t\t\t\t\t---    ---------------------\n\t\t\t\t\t|1| -> | Cadastrar receita |\n\t\t\t\t\t---    ---------------------\n\t\t\t\t\t---    ---------------------\n\t\t\t\t\t|2| -> | Consultar receita |\n\t\t\t\t\t---    ---------------------\n\t\t\t\t\t---    --------------------\n\t\t\t\t\t|3| -> | Sair do programa |\n\t\t\t\t\t---    --------------------\n\t\t\t\t\t-> Opção: ");
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
								printf("\t--------------------------------------------------------------------------------------\n\t| AVISO: O PROGRAMA NÃO LER ACENTOS E CARACTERES ESPECIAIS NA CRIAÇÃO DAS RECEITAS!! | (EX: ´ E ^)\n\t--------------------------------------------------------------------------------------\n\n");
								printf("-> Digite o nome da receita: ");
								scanf(" %[^\n]s", bolo[ContadorCadastro].nome);
								printf("\n\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro dos Ingredientes |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DOS INGREDIENTES <--\n\n");
								//Adicionando o NOME no arquivo
								fprintf(listabolo, "*********************\n");//Estilização 
								fprintf(listabolo, "-> NOME DA RECEITA: ");//Estilização 
								strcat(bolo[ContadorCadastro].nome, "\n");
								fprintf(listabolo, bolo[ContadorCadastro].nome);//Adicionando o nome
								fprintf(listabolo, "\n-> INGREDIENTES: \n\n");//Estilização 
								//Fim da gravação de dados
								while(ContadorIngredientes<=29) //Adicionando os ingredientes
								{
									printf("-> Adicione o ingrediente número %d: ", ContadorIngredientes+1);
									scanf(" %[^\n]s", bolo[ContadorCadastro].ingrediente[ContadorIngredientes]);
									if(strcmp(bolo[ContadorCadastro].ingrediente[ContadorIngredientes], "fim"))
									{
										//Adicionando os dados no arquivo
										strcat(bolo[ContadorCadastro].ingrediente[ContadorIngredientes], " \n");
										fprintf(listabolo, "-> ");
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
								fprintf(listabolo, "-> PASSO A PASSO: \n\n");//Estilização 
								while(ContadorPassos<=29) //Adicionando os passos
								{
									printf("-> Adicione o passo número %d: ", ContadorPassos+1);
									scanf(" %[^\n]s", bolo[ContadorCadastro].passos[ContadorPassos]);
									
									if(strcmp(bolo[ContadorCadastro].passos[ContadorPassos], "fim"))
									{
										//Adicionando os dados no arquivo
										strcat(bolo[ContadorCadastro].passos[ContadorPassos], " \n");
										fprintf(listabolo, "-> ");
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
						
						for(ContadorCadastro=0; ContadorCadastro<=29; ContadorCadastro++)//Achar uma receita vazia
						{
							ContadorIngredientes=0, ContadorPassos=0;
							if(trufa[ContadorCadastro].id == 0)
							{
								
								listatrufa = fopen("receitastrufa.txt", "a");//Comando para abrir o arquivo(Incluir dados)
								printf("\t--------------------------------------------------------------------------------------\n\t| AVISO: O PROGRAMA NÃO LER ACENTOS E CARACTERES ESPECIAIS NA CRIAÇÃO DAS RECEITAS!! | (EX: ´ E ^)\n\t--------------------------------------------------------------------------------------\n\n");
								printf("-> Digite o nome da receita: ");
								scanf(" %[^\n]s", trufa[ContadorCadastro].nome);
								printf("\n\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro dos Ingredientes |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DOS INGREDIENTES <--\n\n");
								//Adicionando o NOME no arquivo
								fprintf(listatrufa, "*********************\n");//Estilização 
								fprintf(listatrufa, "-> NOME DA RECEITA: ");//Estilização 
								strcat(trufa[ContadorCadastro].nome, "\n");
								fprintf(listatrufa, trufa[ContadorCadastro].nome);//Adicionando o nome
								fprintf(listatrufa, "\n-> INGREDIENTES: \n\n");//Estilização 
								//Fim da gravação de dados
								while(ContadorIngredientes<=29) //Adicionando os ingredientes
								{
									printf("-> Adicione o ingrediente número %d: ", ContadorIngredientes+1);
									scanf(" %[^\n]s", trufa[ContadorCadastro].ingrediente[ContadorIngredientes]);
									if(strcmp(trufa[ContadorCadastro].ingrediente[ContadorIngredientes], "fim"))
									{
										//Adicionando os dados no arquivo
										strcat(trufa[ContadorCadastro].ingrediente[ContadorIngredientes], " \n");
										fprintf(listatrufa, "-> ");
										fprintf(listatrufa, trufa[ContadorCadastro].ingrediente[ContadorIngredientes]);
										//Fim da gravação de dados
										ContadorIngredientes++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DOS INGREDIENTES <--\n\n");
										ContadorIngredientes=31;
										fprintf(listatrufa, " \n");
									}
								}
								
								printf("\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro do Passo a Passo |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DO PASSO A PASSO <--\n\n");
								fprintf(listatrufa, "-> PASSO A PASSO: \n\n");//Estilização 
								while(ContadorPassos<=29) //Adicionando os passos
								{
									printf("-> Adicione o passo número %d: ", ContadorPassos+1);
									scanf(" %[^\n]s", trufa[ContadorCadastro].passos[ContadorPassos]);
									
									if(strcmp(trufa[ContadorCadastro].passos[ContadorPassos], "fim"))
									{
										//Adicionando os dados no arquivo
										strcat(trufa[ContadorCadastro].passos[ContadorPassos], " \n");
										fprintf(listatrufa, "-> ");
										fprintf(listatrufa, trufa[ContadorCadastro].passos[ContadorPassos]);
										//Fim da gravação de dados
										ContadorPassos++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DO PASSO A PASSO <--\n\n");
										ContadorPassos=31;
										fprintf(listatrufa, " \n");
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
								
								for(Exibir=0; Exibir<=29; Exibir++)//Amostrando os Passos
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
						fclose(listatrufa);//Fechamento da lista trufa
						break; 
					/******************* FIM CADASTRO DO TRUFA *******************/
					/******************* INICIO CADASTRO DO MILKSHAKE *******************/
					case 3:
						
						for(ContadorCadastro=0; ContadorCadastro<=29; ContadorCadastro++)//Achar uma receita vazia
						{
							ContadorIngredientes=0, ContadorPassos=0;
							if(milkshake[ContadorCadastro].id == 0)
							{
								
								listamilkshake = fopen("receitasmilkshake.txt", "a");//Comando para abrir o arquivo(Incluir dados)
								printf("\t--------------------------------------------------------------------------------------\n\t| AVISO: O PROGRAMA NÃO LER ACENTOS E CARACTERES ESPECIAIS NA CRIAÇÃO DAS RECEITAS!! | (EX: ´ E ^)\n\t--------------------------------------------------------------------------------------\n\n");
								printf("-> Digite o nome da receita: ");
								scanf(" %[^\n]s", milkshake[ContadorCadastro].nome);
								printf("\n\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro dos Ingredientes |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DOS INGREDIENTES <--\n\n");
								//Adicionando o NOME no arquivo
								fprintf(listamilkshake, "*********************\n");//Estilização 
								fprintf(listamilkshake, "-> NOME DA RECEITA: ");//Estilização 
								strcat(milkshake[ContadorCadastro].nome, "\n");
								fprintf(listamilkshake, milkshake[ContadorCadastro].nome);//Adicionando o nome
								fprintf(listamilkshake, "\n-> INGREDIENTES: \n\n");//Estilização 
								//Fim da gravação de dados
								while(ContadorIngredientes<=29) //Adicionando os ingredientes
								{
									printf("-> Adicione o ingrediente número %d: ", ContadorIngredientes+1);
									scanf(" %[^\n]s", milkshake[ContadorCadastro].ingrediente[ContadorIngredientes]);
									if(strcmp(milkshake[ContadorCadastro].ingrediente[ContadorIngredientes], "fim"))
									{
										//Adicionando os dados no arquivo
										strcat(milkshake[ContadorCadastro].ingrediente[ContadorIngredientes], " \n");
										fprintf(listamilkshake, "-> ");
										fprintf(listamilkshake, milkshake[ContadorCadastro].ingrediente[ContadorIngredientes]);
										//Fim da gravação de dados
										ContadorIngredientes++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DOS INGREDIENTES <--\n\n");
										ContadorIngredientes=31;
										fprintf(listamilkshake, " \n");
									}
								}
								
								printf("\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro do Passo a Passo |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DO PASSO A PASSO <--\n\n");
								fprintf(listamilkshake, "-> PASSO A PASSO: \n\n");//Estilização 
								while(ContadorPassos<=29) //Adicionando os passos
								{
									printf("-> Adicione o passo número %d: ", ContadorPassos+1);
									scanf(" %[^\n]s", milkshake[ContadorCadastro].passos[ContadorPassos]);
									
									if(strcmp(milkshake[ContadorCadastro].passos[ContadorPassos], "fim"))
									{
										//Adicionando os dados no arquivo
										strcat(milkshake[ContadorCadastro].passos[ContadorPassos], " \n");
										fprintf(listamilkshake, "-> ");
										fprintf(listamilkshake, milkshake[ContadorCadastro].passos[ContadorPassos]);
										//Fim da gravação de dados
										ContadorPassos++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DO PASSO A PASSO <--\n\n");
										ContadorPassos=31;
										fprintf(listamilkshake, " \n");
									}
								}
								printf("\t\t\t\t\t----------------------------------\n\t\t\t\t\t| Cadastro Realizado Com Sucesso |\n\t\t\t\t\t----------------------------------\n\n");
								printf("-> Receita: %s\n\n-> Lista dos Ingredientes: \n\n", milkshake[ContadorCadastro].nome);
								
								for(Exibir=0; Exibir<=29; Exibir++)//Amostrando os ingredientes
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
						fclose(listamilkshake);//Fechamento da lista milkshake
						break;
					/******************* FIM CADASTRO DO MILKSHAKE *******************/
					/******************* INICIO CADASTRO DO PASTEL *******************/
					case 4:
						
						for(ContadorCadastro=0; ContadorCadastro<=29; ContadorCadastro++)//Achar uma receita vazia
						{
							ContadorIngredientes=0, ContadorPassos=0;
							if(pastel[ContadorCadastro].id == 0)
							{
								
								listapastel = fopen("receitaspastel.txt", "a");//Comando para abrir o arquivo(Incluir dados)
								printf("\t--------------------------------------------------------------------------------------\n\t| AVISO: O PROGRAMA NÃO LER ACENTOS E CARACTERES ESPECIAIS NA CRIAÇÃO DAS RECEITAS!! | (EX: ´ E ^)\n\t--------------------------------------------------------------------------------------\n\n");
								printf("-> Digite o nome da receita: ");
								scanf(" %[^\n]s", pastel[ContadorCadastro].nome);
								printf("\n\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro dos Ingredientes |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DOS INGREDIENTES <--\n\n");
								//Adicionando o NOME no arquivo
								fprintf(listapastel, "*********************\n");//Estilização 
								fprintf(listapastel, "-> NOME DA RECEITA: ");//Estilização 
								strcat(pastel[ContadorCadastro].nome, "\n");
								fprintf(listapastel, pastel[ContadorCadastro].nome);//Adicionando o nome
								fprintf(listapastel, "\n-> INGREDIENTES: \n\n");//Estilização 
								//Fim da gravação de dados
								while(ContadorIngredientes<=29) //Adicionando os ingredientes
								{
									printf("-> Adicione o ingrediente número %d: ", ContadorIngredientes+1);
									scanf(" %[^\n]s", pastel[ContadorCadastro].ingrediente[ContadorIngredientes]);
									if(strcmp(pastel[ContadorCadastro].ingrediente[ContadorIngredientes], "fim"))
									{
										//Adicionando os dados no arquivo
										strcat(pastel[ContadorCadastro].ingrediente[ContadorIngredientes], " \n");
										fprintf(listapastel, "-> ");
										fprintf(listapastel, pastel[ContadorCadastro].ingrediente[ContadorIngredientes]);
										//Fim da gravação de dados
										ContadorIngredientes++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DOS INGREDIENTES <--\n\n");
										ContadorIngredientes=31;
										fprintf(listapastel, " \n");
									}
								}
								
								printf("\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro do Passo a Passo |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DO PASSO A PASSO <--\n\n");
								fprintf(listapastel, "-> PASSO A PASSO: \n\n");//Estilização 
								while(ContadorPassos<=29) //Adicionando os passos
								{
									printf("-> Adicione o passo número %d: ", ContadorPassos+1);
									scanf(" %[^\n]s", pastel[ContadorCadastro].passos[ContadorPassos]);
									
									if(strcmp(pastel[ContadorCadastro].passos[ContadorPassos], "fim"))
									{
										//Adicionando os dados no arquivo
										strcat(pastel[ContadorCadastro].passos[ContadorPassos], " \n");
										fprintf(listapastel, "-> ");
										fprintf(listapastel, pastel[ContadorCadastro].passos[ContadorPassos]);
										//Fim da gravação de dados
										ContadorPassos++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DO PASSO A PASSO <--\n\n");
										ContadorPassos=31;
										fprintf(listapastel, " \n");
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
								
								for(Exibir=0; Exibir<=29; Exibir++)//Amostrando os Passos
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
						fclose(listapastel);//Fechamento da lista pastel
						break;
					/******************* FIM CADASTRO DO PASTEL *******************/
					/******************* INICO CADASTRO DA PIZZA *******************/
					case 5:
						
						for(ContadorCadastro=0; ContadorCadastro<=29; ContadorCadastro++)//Achar uma receita vazia
						{
							ContadorIngredientes=0, ContadorPassos=0;
							if(pizza[ContadorCadastro].id == 0)
							{
								
								listapizza = fopen("receitaspizza.txt", "a");//Comando para abrir o arquivo(Incluir dados)
								printf("\t--------------------------------------------------------------------------------------\n\t| AVISO: O PROGRAMA NÃO LER ACENTOS E CARACTERES ESPECIAIS NA CRIAÇÃO DAS RECEITAS!! | (EX: ´ E ^)\n\t--------------------------------------------------------------------------------------\n\n");
								printf("-> Digite o nome da receita: ");
								scanf(" %[^\n]s", pizza[ContadorCadastro].nome);
								printf("\n\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro dos Ingredientes |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DOS INGREDIENTES <--\n\n");
								//Adicionando o NOME no arquivo
								fprintf(listapizza, "*********************\n");//Estilização 
								fprintf(listapizza, "-> NOME DA RECEITA: ");//Estilização 
								strcat(pizza[ContadorCadastro].nome, "\n");
								fprintf(listapizza, pizza[ContadorCadastro].nome);//Adicionando o nome
								fprintf(listapizza, "\n-> INGREDIENTES: \n\n");//Estilização 
								//Fim da gravação de dados
								while(ContadorIngredientes<=29) //Adicionando os ingredientes
								{
									printf("-> Adicione o ingrediente número %d: ", ContadorIngredientes+1);
									scanf(" %[^\n]s", pizza[ContadorCadastro].ingrediente[ContadorIngredientes]);
									if(strcmp(pizza[ContadorCadastro].ingrediente[ContadorIngredientes], "fim"))
									{
										//Adicionando os dados no arquivo
										strcat(pizza[ContadorCadastro].ingrediente[ContadorIngredientes], " \n");
										fprintf(listapizza, "-> ");
										fprintf(listapizza, pizza[ContadorCadastro].ingrediente[ContadorIngredientes]);
										//Fim da gravação de dados
										ContadorIngredientes++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DOS INGREDIENTES <--\n\n");
										ContadorIngredientes=31;
										fprintf(listapizza, " \n");
									}
								}
								
								printf("\t\t\t\t\t---------------------------------------\n\t\t\t\t\t| Inicio do Cadastro do Passo a Passo |\n\t\t\t\t\t---------------------------------------\n\n");
								printf("--> OBS: DIGITE ''fim'' PARA ENCERRAR O CADASTRO DO PASSO A PASSO <--\n\n");
								fprintf(listapizza, "-> PASSO A PASSO: \n\n");//Estilização 
								while(ContadorPassos<=29) //Adicionando os passos
								{
									printf("-> Adicione o passo número %d: ", ContadorPassos+1);
									scanf(" %[^\n]s", pizza[ContadorCadastro].passos[ContadorPassos]);
									
									if(strcmp(pizza[ContadorCadastro].passos[ContadorPassos], "fim"))
									{
										//Adicionando os dados no arquivo
										strcat(pizza[ContadorCadastro].passos[ContadorPassos], " \n");
										fprintf(listapizza, "-> ");
										fprintf(listapizza, pizza[ContadorCadastro].passos[ContadorPassos]);
										//Fim da gravação de dados
										ContadorPassos++;
									}
									else
									{
										printf("\n--> FIM DO CADASTRO DO PASSO A PASSO <--\n\n");
										ContadorPassos=31;
										fprintf(listapizza, " \n");
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
								
								printf("\n-> Passo a Passo: \n\n");
								
								for(Exibir=0; Exibir<=29; Exibir++)//Amostrando os Passos
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
						fclose(listapizza);//Fechamento da lista pizza
						break;
					/******************* FIM CADASTRO DA PIZZA *******************/
				}
			break;
				/******************* FIM CADASTRO DAS RECEITAS *******************/
			
			
				/*---------------------------------------------------------------------
				---------------------------------------------------------------------*/
			
			
				/******************* INICIO CONSULTA DAS RECEITAS*******************/
			
			case 2:
				printf("\n-> Escolha o tipo de receita que você quer consultar:\n\n");
				printf("---    --------\n|1| -> | Bolo |\n---    ---------\n|2| -> | Trufa |\n---    -------------\n|3| -> | Milkshake |\n---    -------------\n|4| -> | Pastel |\n---    ----------\n|5| -> | Pizza |\n---    ---------\n\n-> Opção: ");
				scanf("%d", &OpcaoConsulta);
				printf("\n\t\t\t\t\t\t------------------------\n\t\t\t\t\t\t| RECEITAS CADASTRADAS |\n\t\t\t\t\t\t------------------------\n\n");
				
				switch(OpcaoConsulta){
				//***********************************INICIO CONSULTA DAS RECEITAS DO BOLO ********************************//
					case 1:
						listabolo = fopen("receitasbolo.txt", "r");
						
						if(listabolo == NULL)
						{
							printf("Arquivo nao pode ser aberto");
							system("pause");
							return 0;
						}
						
						char frase[200];
						
						while(fgets(frase, 200, listabolo) != NULL){
								printf("%s", frase);
						}
						
						printf("--> DICA: PRESSIONE ''CRTL + F'' PARA PESQUISAR UMA RECEITA ESPECÍFICA, NA ÁREA ''LOCALIZAR'' <--\n\n");
						
						break;
					//********************************** FIM CONSULTA DAS RECEITAS DO BOLO ********************************//
					
					case 2://***********************************INICIO CONSULTA DAS RECEITAS DE TRUFA ********************************//
						listatrufa = fopen("receitastrufa.txt", "r");
						
						if(listatrufa == NULL)
						{
							printf("Arquivo nao pode ser aberto");
							system("pause");
							return 0;
						}
						
						while(fgets(frase, 200, listatrufa) != NULL){
								printf("%s", frase);
						}
						
						printf("--> DICA: PRESSIONE ''CRTL + F'' PARA PESQUISAR UMA RECEITA ESPECÍFICA, NA ÁREA ''LOCALIZAR'' <--\n\n");
						
						break;
					//********************************** FIM CONSULTA DAS RECEITAS DE TRUFA ********************************//
					
					case 3://***********************************INICIO CONSULTA DAS RECEITAS DE MILKSHAKE ********************************//
						listamilkshake = fopen("receitasmilkshake.txt", "r");
						
						if(listamilkshake == NULL)
						{
							printf("Arquivo nao pode ser aberto");
							system("pause");
							return 0;
						}
						
						while(fgets(frase, 200, listamilkshake) != NULL)
						{
								printf("%s", frase);
						}
						
						printf("--> DICA: PRESSIONE ''CRTL + F'' PARA PESQUISAR UMA RECEITA ESPECÍFICA, NA ÁREA ''LOCALIZAR'' <--\n\n");
						
						break;
					//********************************** FIM CONSULTA DAS RECEITAS DE MILKSHAKE ********************************//
					
					case 4://***********************************INICIO CONSULTA DAS RECEITAS DE PASTEL ********************************//
						listapastel = fopen("receitaspastel.txt", "r");
						
						if(listapastel == NULL)
						{
							printf("Arquivo nao pode ser aberto");
							system("pause");
							return 0;
						}
						
						while(fgets(frase, 200, listapastel) != NULL)
						{
								printf("%s", frase);
						}
						
						printf("--> DICA: PRESSIONE ''CRTL + F'' PARA PESQUISAR UMA RECEITA ESPECÍFICA, NA ÁREA ''LOCALIZAR'' <--\n\n");
						
						break;
					//********************************** FIM CONSULTA DAS RECEITAS DE PASTEL ********************************//
					
					case 5://***********************************INICIO CONSULTA DAS RECEITAS DE PIZZA ********************************//
						listapizza = fopen("receitaspizza.txt", "r");
						
						if(listapizza == NULL)
						{
							printf("Arquivo nao pode ser aberto");
							system("pause");
							return 0;
						}
						
						while(fgets(frase, 200, listapizza) != NULL)
						{
								printf("%s", frase);
						}
						
						printf("--> DICA: PRESSIONE ''CRTL + F'' PARA PESQUISAR UMA RECEITA ESPECÍFICA, NA ÁREA ''LOCALIZAR'' <--\n\n");
						
						break;
					//********************************** FIM CONSULTA DAS RECEITAS DE PIZZA ********************************//
				}
			break;
		}
	} while(OpcaoAcao!=3);
	
	printf("\n\t\t\t\t\t\t------------\n\t\t\t\t\t\t| Creditos |\n\t\t\t\t\t\t------------\n\n\t\t\t\t\t\tProgramadores\n\n\t\t\t\t\t     Jonathan Fernandes\n\t\t\t\t\t\t Oscar Alves\n\t\t\t\t\t\t Ryan Gomes\n\n");
	
 	system("pause");
 	return 0;
}
