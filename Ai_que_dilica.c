#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 100

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
 	typedef struct
	{
 		char nome[30];
 		char ingrediente[30][30];
 		char passos[30][50];
	} receita;
	
	receita bolo[30], trufa[30], milkshake[30], pastel[30], pizza[30];
	
	int opcao, i=0;
	
	do{
		puts("\t\t\t\t\t\t---------------\n\t\t\t\t\t\t|AI QUI DILICA|\n\t\t\t\t\t\t---------------\n");
		printf("\t\t\t\t\t---    ----------------------\n\t\t\t\t\t|1| -> | Consultar receitas |\n\t\t\t\t\t---    ----------------------\n\t\t\t\t\t---    ---------------------\n\t\t\t\t\t|2| -> | Cadastrar receita |\n\t\t\t\t\t---    ---------------------\n\t\t\t\t\t---    --------------------\n\t\t\t\t\t|3| -> | Sair do programa |\n\t\t\t\t\t---    --------------------\n\t\t\t\t\t-> Opcao: ");
		scanf("%d", &opcao);
		
		switch (opcao)
		{
		case 1:
			printf("Digite o tipo ");
				
			break;
		case 2:
			printf("\n-> Escolha qual alimento dentre os seguintes voce deseja cadastrar uma receita nova:\n\n");
			printf("---    --------\n|1| -> | Bolo |\n---    ---------\n|2| -> | Trufa |\n---    -------------\n|3| -> | Milkshake |\n---    -------------\n|4| -> | Pastel |\n---    ----------\n|5| -> | Pizza |\n---    ---------\n\n-> Opcao: \n\n");
			
			break;
		}
	} while(opcao!=3);
	
	printf("\n\t\t\t\t\t\t------------\n\t\t\t\t\t\t| Creditos |\n\t\t\t\t\t\t------------\n\n\t\t\t\t\t\tProgramadores\n\n\t\t\t\t\t     Jonathan Fernandes\n\t\t\t\t\t\t Oscar Alves\n\t\t\t\t\t\t Ryan Gomes\n\n");
	
 	system("pause");
 	return 0;
}
