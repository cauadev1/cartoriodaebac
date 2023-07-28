#include <stdio.h> //biblioteca de comunicaçao com o usúario
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocaçoes de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsavel por cadastrar os usuários no sistema
{
	//inicio da criação das variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:" ); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
    strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file;	//cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor das variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
		
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

	char cpf[40];
	char conteudo[100];
	
	printf("digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 100,file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf [40];
	
	printf ("digite o CPF que deseja ser deletado: ");
	scanf("%s",cpf);
	
	FILE* file;
	file = fopen(cpf,"r");
	
    if(file == NULL)
    {
    	printf("cpf não encontrado!\n");
    	system("pause");
    	return 0;
	}
	 fclose(file);
	
	if (remove(cpf) ==0)
	{
		printf("CPF removido com sucesso!\n");
	}	
	else
	{
		printf("Erro ao deletar o usuário!\n");
	}
		
		system("pause");
		return 0;
}



int main()
    {
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{	 
	
	    system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	    printf("### Cartório da EBAC###\n\n"); //começo do menu 
	    printf("Escola a opçao desejada do menu:\n\n");
	    printf("\t1 - registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n\n"); 
	    printf("opção:"); //fim do menu
  
        scanf("%d", &opcao);  //armazenando a escolha do usuário 
        
        system("cls"); //responsavel por limpar a tela
    
    
        switch(opcao) //inicio da seleção
        {	             
        	case 1:
        	registro(); //chamada de funções
        	break;
		
		    case 2:
		    consulta();
        	break;
		
		    case 3:                                       
		    deletar();
		    break;
		    
		    default:
		    printf("Está opção não está disponivel!!\n");
	        system("pause");
	        break;
	   } //fim da seleção
	    
	}
 
 }   
