//
//  Exemplo 1 modulo 1.c
//  Estudo 1
//
//  Created by Caio Sertori on 16/01/2023.
//

#include <stdio.h> //Biblioteca de comunica��oo com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Bliblioteca de aloca��oo de texto por regi�o
#include <string.h> // Biblioteca respons�vel por cuidar das strings

int registro() // funcao responsavel por cadastrar os usuarios no sistema
{
	// inicio da criacao das variaveis/strings
    char arquivo[40];
    char cpf [40];
    char nome[40];
    char sobrenome[40];
    char cargo [40];
    //final da criacao de variaveis
    
    printf("Digite o CPF a ser cadastrado: \n");// coleta de informacoes do usuario
    scanf("%s", cpf);//%s refere-se a strings
    
    strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings.
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever(write)
    fprintf(file, cpf); //Salva o valor da vari�vel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: \n");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    
    
    printf("Digite o sobrenome a ser cadastrado: \n");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: \n");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
   system("pause");    //Na aula, � ensinado o system("pause"), mas o xcode n�o aceita.
    
    
    
    
   
}
int consulta()
{
    setlocale(LC_ALL, "Portuguese");
    char cpf[40];
    char conteudo[100];
    
    printf("Digite o CPF a ser consultado: \n");
    scanf("%s", cpf );
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
        printf("Ops. N�o conseguimos localizar esse arquivo!\n");
        system("pause");
    }
    
    printf("\nEssas s�o as informa��es do usu�rio: \n");
    
    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("%s", conteudo);
        printf("\n");
    }
    	fclose(file);
        system("pause");
    
}
int deletar()
{
    char cpf[40];
    
    printf("Digite o cpf a ser deletado: \n");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O usu�rio n�o se encontra no sistema. \n");
    	system("pause");
	}
}

int main (){
    int opcao=0;//Definindo vari�veis
    int laco=1;
    
    for(laco=1;laco=1;)//Pela aula, o formato correto � for(laco=1;laco=1)
    {
        
        system("cls");//responsavel por limpar a tela
        
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
        
        printf("#####  Cart�rio da Ebac  ##### \n\n"); // In�cio do Menu
        printf("Qual das op��es abaixo voc� deseja?\n\n");
        printf("\t1- Adicionar novo nome.\n");
        printf("\t2- Consultar nomes cadastrados.\n");
        printf("\t3- Deletar nomes(s).\n\n");
        printf("Op��o:");//Fim do menu
        
        scanf("%d", &opcao); //Armazenando a escolha do usu�rio.
        
        system("cls");
        // system("clear"); Comando da linha de c�digo n�o reconhecido pelo xcode!**** Acho que rolou.
        switch(opcao)// inicio da selecao menu
        {
            case 1:
                registro();//chamada de funcoes
                break;
                
            case 2:
                consulta();
                break;
                
            case 3:
                deletar();
                break;
                
            default :
            {
                printf("Ops. Voc� selecionou uma op��o inv�lida.\n\n");
               system("pause");
                break;
            }//fim da selecao
        }
    }
}
