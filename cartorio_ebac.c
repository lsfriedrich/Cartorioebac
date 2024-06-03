#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de akica��esde texto por regi�o
#include <string.h> // biblioteca da string, respons�vel por cuidar das strings

int registro()// ; s� ter� quando precisar chamar, fun��o respons�vel por cadastrar usu�rios no sistema
{
	// in�cio de cria��o das vari�veis/strings
	char arquivo [40];
	char cpf[40]; // 40 serve para guardar espa�o
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o das vari�veis 
	
	printf("Digite o CPF a ser cadastrado:  "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s vai salvar dentro de uma string
	
	strcpy(arquivo, cpf); //cria��o string cpf para o arquivo, respons�vel por copiar os valores das strings
	
	FILE *file; //procurar nas bibliotecas estruturas FILE dentro das estruturas *file para criar o arquivo para o BD
	file = fopen(arquivo, "w"); // w==write salva na pasta desenvolvimento
	fprintf(file, cpf); //salvar o file cpf, salvo o valor da vari�vel
	fclose(file);//fehca o arquivo
	
	file = fopen(arquivo, "a"); //abrir e criar info sem criar um novo arquivo
	fprintf(file, ",");//separar por v�rgula
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //salvo o nome digitado na string
	
	file = fopen(arquivo, "a"); //abrir o arquivo 
	fprintf(file,nome); //salvando o que foi digitado no nome
	fclose(file); //salvar o nome e fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrir e criar info sem criar um novo arquivo
	fprintf(file, ",");//separar por v�rgula
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); // "a" == atualizar
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //abrir e criar info sem criar um novo arquivo
	fprintf(file, ",");//separar por v�rgula
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); // "a" == atualizar
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a"); //abrir e criar info sem criar um novo arquivo
	fprintf(file, ",");//separar por v�rgula
	fclose(file);
	
	system("Pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //fun��es #s. Sempre colocar no mesmo arquivo.
	
	char cpf[40];
	char conteudo[200];

	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" == read
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}

	while(fgets(conteudo, 200, file) != NULL)// la�o de repeti��o - salvando em conte�do e buscando 200 caracteres, dentro do arquivo e vai parar qdo != for Nulo
	{ 
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
}

int deletar()
{
		char cpf[40];
		
		printf("Digite o CPF do usu�rio a ser deletado: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file= fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("O usu�rio n�o se encontra no sistema!\n");
			system("pause");	
		}	
}


int main()// fun��o principal tipo int - inteiro, main - principal, () denominando uma fun��o. Sempre vir� 1o n�o importa onde est� escrita
{
	int opcao=0; // definindo as vari�veis 
	int laco=1; // defini��o da vari�vel "for"
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); // avisando que pode ter acento e informando a regi�o - defini��o da linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); // as # n�o representa nenhum comando, somente visual
		printf("Escolha a op��o desejada do menu:\n\n"); // o \n deixa o programa limpo e amig�vel ao usu�rio
		printf("\t1 - Registrar Nomes\n"); // o \t vai da um espa�o maior do tipo tab
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o:  "); // fim do menu
	
		scanf("%d", &opcao); // pausa o prog para resposta do usu�rio
	
		system("cls");// deletar todas as mensagens que tinha antes, limpar a tela
	
	
		switch(opcao)//in�cio da sele��o do menu
		{
			case 1: // neste caso, n�o � necess�rio as chaves, os dois pontos serve para isto
			registro(); // j� vai chamar a fun��o colocada no int
			break; // para fechar, encerrar o 1o case 
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
				
			default: // caso n�o seja nenhuma das op��es
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			
		}//fim da sele��o
	
	
	}
}
