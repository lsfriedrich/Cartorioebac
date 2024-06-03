#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de akicaçõesde texto por regiâo
#include <string.h> // biblioteca da string, responsável por cuidar das strings

int registro()// ; só terá quando precisar chamar, função responsável por cadastrar usuários no sistema
{
	// início de criação das variáveis/strings
	char arquivo [40];
	char cpf[40]; // 40 serve para guardar espaço
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação das variáveis 
	
	printf("Digite o CPF a ser cadastrado:  "); //coletando informação do usuário
	scanf("%s", cpf); //%s vai salvar dentro de uma string
	
	strcpy(arquivo, cpf); //criação string cpf para o arquivo, responsável por copiar os valores das strings
	
	FILE *file; //procurar nas bibliotecas estruturas FILE dentro das estruturas *file para criar o arquivo para o BD
	file = fopen(arquivo, "w"); // w==write salva na pasta desenvolvimento
	fprintf(file, cpf); //salvar o file cpf, salvo o valor da variável
	fclose(file);//fehca o arquivo
	
	file = fopen(arquivo, "a"); //abrir e criar info sem criar um novo arquivo
	fprintf(file, ",");//separar por vírgula
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //salvo o nome digitado na string
	
	file = fopen(arquivo, "a"); //abrir o arquivo 
	fprintf(file,nome); //salvando o que foi digitado no nome
	fclose(file); //salvar o nome e fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrir e criar info sem criar um novo arquivo
	fprintf(file, ",");//separar por vírgula
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); // "a" == atualizar
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //abrir e criar info sem criar um novo arquivo
	fprintf(file, ",");//separar por vírgula
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); // "a" == atualizar
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a"); //abrir e criar info sem criar um novo arquivo
	fprintf(file, ",");//separar por vírgula
	fclose(file);
	
	system("Pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //funções #s. Sempre colocar no mesmo arquivo.
	
	char cpf[40];
	char conteudo[200];

	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" == read
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}

	while(fgets(conteudo, 200, file) != NULL)// laço de repetição - salvando em conteúdo e buscando 200 caracteres, dentro do arquivo e vai parar qdo != for Nulo
	{ 
		printf("\nEssas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
}

int deletar()
{
		char cpf[40];
		
		printf("Digite o CPF do usuário a ser deletado: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file= fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("O usuário não se encontra no sistema!\n");
			system("pause");	
		}	
}


int main()// função principal tipo int - inteiro, main - principal, () denominando uma função. Sempre virá 1o não importa onde está escrita
{
	int opcao=0; // definindo as variáveis 
	int laco=1; // definição da variável "for"
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); // avisando que pode ter acento e informando a região - definição da linguagem
	
		printf("### Cartório da EBAC ###\n\n"); // as # não representa nenhum comando, somente visual
		printf("Escolha a opção desejada do menu:\n\n"); // o \n deixa o programa limpo e amigável ao usuário
		printf("\t1 - Registrar Nomes\n"); // o \t vai da um espaço maior do tipo tab
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção:  "); // fim do menu
	
		scanf("%d", &opcao); // pausa o prog para resposta do usuário
	
		system("cls");// deletar todas as mensagens que tinha antes, limpar a tela
	
	
		switch(opcao)//início da seleção do menu
		{
			case 1: // neste caso, não é necessário as chaves, os dois pontos serve para isto
			registro(); // já vai chamar a função colocada no int
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
				
			default: // caso não seja nenhuma das opções
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
			
		}//fim da seleção
	
	
	}
}
