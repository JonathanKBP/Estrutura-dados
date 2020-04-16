#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
struct ficha{
	char nome[40]; 
	char telefone[20];
	char email[40];
	char idade[3];
	char endereco[100];
};

int procurar(char procurado[], struct ficha vetor[], int indice_ultima_ficha){
	if(indice_ultima_ficha<0) return-1;
	else if (strstr(vetor[indice_ultima_ficha].nome, procurado)!= NULL) return indice_ultima_ficha;
	else return procurar(procurado, vetor, indice_ultima_ficha-1);
}

int main()
{
	struct ficha agenda[100];
	int fichas_existentes = 0, proxima = 0;
	char opcao[10]="0";
        setlocale(LC_ALL, "Portuguese");

	while(opcao[0] != '5')
	{
		printf("\nEntre com a opção desejada:\n");
		printf("\n1) Inserir ficha:");
		printf("\n2) Procurar por nome:");
		printf("\n3) Listar toda a base:");
		printf("\n4) Excluir por nome:");
		printf("\n5) Sair\n\n");
		gets(opcao);

		if(opcao[0] == '1') //inserir
		{
			printf("\nEntre com um nome: ");
			gets(agenda[proxima].nome);
			printf("\nEntre com a idade: ");
			gets(agenda[proxima].idade);
			printf("\nEntre com o telefone: ");
			gets(agenda[proxima].telefone);
			printf("\nEntre com um e-mail: ");
			gets(agenda[proxima].email);
			printf("\nEntre com um endereco: ");
			gets(agenda[proxima].endereco);
			fichas_existentes++;
			proxima++;
		}
		if(opcao[0] == '2') //procurar
		{
			char procurado[40];
			printf("\nEntre com o nome procurado: ");
			gets(procurado);
			
			int procurando = procurar(procurado, agenda, fichas_existentes);
			if(procurando != -1){
				int aux = fichas_existentes-1;
				while(aux != -1){
					printf("\nnome: %s \nidade: %s \ne-mail: %s \ntelefone: %s \nendereco: %s\n",
				    agenda[procurando].nome, agenda[procurando].idade, agenda[procurando].email,
					agenda[procurando].telefone, agenda[procurando].endereco);
					aux--;
					aux = procurar(procurado, agenda, aux);
				}	
			}
			
			else printf("\nNome nao encontrado\n");
		}
		if(opcao[0] == '3') //listar tudo
		{
			printf("\n\n");
			int i;
			for(i=0; i<fichas_existentes; i++)
			{
			    printf("nome: %s \nidade: %s \ne-mail: %s \ntelefone: %s \nendereco: %s\n\n",
			    agenda[i].nome, agenda[i].idade, agenda[i].email, agenda[i].telefone, agenda[i].endereco);
			}
			if(fichas_existentes == 0)
				printf("A base de dados está vazia!\n");
		}
		if(opcao[0] == '4') //excluir
		{
			char procurado[40];
			printf("\nEntre com o nome que sera excluido: ");
			gets(procurado);
			int procurando = procurar(procurado, agenda, fichas_existentes);
			
			if(procurando != -1){
				int aux = fichas_existentes-1;
				while(aux != -1){
					aux = procurar(procurado, agenda, aux);
					printf("nome: %s \nidade: %s \ne-mail: %s \ntelefone: %s \nendereco: %s\n",
				    agenda[aux].nome, agenda[aux].idade, agenda[aux].email,
					agenda[aux].telefone, agenda[aux].endereco);
				
					char resposta[3];
					printf("\nDeseja apagar?\nSIM/NÃO\n");
					gets(resposta);
					if(strcasecmp(resposta, "sim")==0){
						agenda[procurando] = agenda[fichas_existentes-1];
						fichas_existentes--;
						proxima--;
						printf("\nItem excluido.\n ");
					}
					aux = aux-1;
				}
			}
			else printf("\nNome nao encontrado\n");
		}
	}
	return 0;
}
