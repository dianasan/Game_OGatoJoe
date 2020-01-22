#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){

//criando a variável ponteiro para o arquivo 
FILE *ponteiro_do_arquivo;
char nome[4];
int pontos; 

//abrindo o arquivo (usar "a" que escreve no final e cria um arquivo caso ele não exista)
ponteiro_do_arquivo = fopen("ranking.txt", "a");

//verificando se criou o arquivo 
if(ponteiro_do_arquivo == NULL){
	printf("erro ao criar arquivo\n");
}else{
	printf("arquivo criado\n");
}

printf("Nome do jogador\n");
fgets(nome, 4, stdin);

//escrevendo o nome no arquivo
fprintf(ponteiro_do_arquivo, "%s",nome);
fprintf(ponteiro_do_arquivo, " ");
fprintf(ponteiro_do_arquivo, "%d\n",pontos);

//fechando o arquivo 
fclose(ponteiro_do_arquivo);

	return 0;
}