#include<stdio.h> // biblioteca de comunicaçao com usúario
#include<stdlib.h>// biblioteca de alocação de memória
#include<locale.h>// biblioteca  de alocaçoes de texto por região
#include<string.h> // biblioteca responsável por cuidar das string
  
 int registrar()
 {
 	char arquivo [40];
 	char cpf[40]; 
	char nome[40]; 
	char sobrenome[40]; 
	char cargo[40];
	 
	 printf("\nDigite CPF para  cadastro: "); // interação com ususario
	 scanf("%s",cpf); // armazena resposta
	 
	 strcpy(arquivo, cpf); // Responsavel por copiar os valores das string
	 
	 FILE *file; // cria o arquivo
	 file = fopen(arquivo, "w"); //cria arquivo e abre e o w significa write
	 fprintf(file, cpf); // salva o valor na variavel
	 fclose(file);	// fecha o arquivo
	 
	 file = fopen(arquivo, "a"); // abrir arquivo e atualizar
	 fprintf(file, ", "); //adiciona o  caractere entre aspas
	 fclose(file);
	 
     printf("Digite o nome  : "); 
	 scanf("%s", nome); 
	 
	 file=fopen(arquivo, "a");
	 fprintf(file, nome);
	 fclose(file);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file, ", ");
	 fclose(file);
	 
	 printf("Digite o sobrenome: ");
	 scanf("%s", sobrenome);
	 
	 file=fopen(arquivo, "a");
	 fprintf(file, sobrenome);
	 fclose(file);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file, ", ");
	 fclose(file);
	 
   	 printf("Digite o cargo: ");
	 scanf("%s", cargo);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file, cargo);
	 fclose(file);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file, ".");
	 fclose(file);
	 
	 system("pause");
	 
 } 
 
 int consultar()
 {
  setlocale( LC_ALL,"Portuguese" ); // definindo linguagem

  char  cpf[40];
  char conteudo[200];
  
  printf("Digite o  CPF de consulta : ");
  scanf("%s",cpf);
  
  FILE *file;
  file= fopen(cpf, "r"); //ler arquivo, r significa read
  
  if(file== NULL)
  {
  	printf("ESTE CPF NÃO ESTA CADASTRADO PARA CONSULTA!\n");
  	system("pause");
  }
  
  while(fgets(conteudo,200,file) != NULL)
  {
  	 printf("\nEstas são as informações do usuario: ");
  	 printf("%s",conteudo);
  	 printf("\n\n");
 	
     system("pause");
   } 
}
 
  int deletar()
  { 
    char cpf[40];
    
    printf("Digite o CPF do usuario  para deletar: ");
    scanf("%s",cpf);
            
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("USUARIO NÃO ENCONTRADO\n"); // quando não encontrado
    	system("pause");
	}
	else
	{
		printf("USUARIO DELETADO COM SUCESSO\n"); // quando encontrado
		system("pause");
	}
   }
    
 int main()
{
	int escolha = 0;// declarar variável
	int laco;
	
	setlocale( LC_ALL,"Portuguese" ); // definindo linguagem
			
	
	for(laco = 1; laco = 1;) // laço para voltar sempre ao menu
	{ 
	    system("cls");
								
    	
			
    	printf(" ..................Cartório da EBAC..................\n\n\n"); 	
		printf("\t\tEscolha a opção desejada:\n\n"); // inicio  do menu
		printf("\t\t 1- Registrar nomes\n");
		printf("\t\t 2- Consultar nomes\n");
		printf("\t\t 3- Deletar nomes\n\n\n"); 
		
   		printf(" ..................Opção: "); //fim do menu
		
		scanf("%d", &escolha);   // armazena a opção digitada		
				
		system("cls");     // limpar/zerar  a tela
		
		switch(escolha) //inicio seleção
		{
			case 1:
			registrar(); // chamada de função
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
				
			
			default: // para opção invalida
			printf("Esta opção não é valida!\n");
			system("pause");
			break;	
		} //fim seleção

	}  
}
 	

