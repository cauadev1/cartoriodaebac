#include <stdio.h> //biblioteca de comunica�ao com o us�ario
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca�oes de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o das variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:" ); //coletando informa��o do usu�rio
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
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 100,file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
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
    	printf("cpf n�o encontrado!\n");
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
		printf("Erro ao deletar o usu�rio!\n");
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
	
	    printf("### Cart�rio da EBAC###\n\n"); //come�o do menu 
	    printf("Escola a op�ao desejada do menu:\n\n");
	    printf("\t1 - registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n\n"); 
	    printf("op��o:"); //fim do menu
  
        scanf("%d", &opcao);  //armazenando a escolha do usu�rio 
        
        system("cls"); //responsavel por limpar a tela
    
    
        switch(opcao) //inicio da sele��o
        {	             
        	case 1:
        	registro(); //chamada de fun��es
        	break;
		
		    case 2:
		    consulta();
        	break;
		
		    case 3:                                       
		    deletar();
		    break;
		    
		    default:
		    printf("Est� op��o n�o est� disponivel!!\n");
	        system("pause");
	        break;
	   } //fim da sele��o
	    
	}
 
 }   
