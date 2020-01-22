#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){

typedef struct{
	char nome[4];
	int pontos;
}jogador;

jogador player[3];
jogador auxiliar;

//criando a variável ponteiro para o arquivo 
FILE *ponteiro_do_arquivo;

ponteiro_do_arquivo = fopen("ranking.txt", "r");

//verificando se criou o arquivo 
if(ponteiro_do_arquivo == NULL){
	printf("erro ao criar arquivo\n");
}else{}

//ler o arquivo enquanto ele não chega no final
while(!feof(ponteiro_do_arquivo)){
	for(int i = 0;i < 3;i++){
		fscanf(ponteiro_do_arquivo,"%s %d\n", player[i].nome, &player[i].pontos);
	}
}

//ordenar os jogadores 
for(int j = 0; j < 3;j++){
	if(player[j].pontos < player[j+1].pontos){
		auxiliar.pontos = player[j+1].pontos;
		//auxiliar.nome = player[j+1].nome;
		sprintf(auxiliar.nome, "%s", player[j+1].nome);
		player[j+1].pontos = player[j].pontos;
		//player[j+1].nome = player[j].nome;
		sprintf(player[j+1].nome, "%s", player[j].nome);
		player[j].pontos = auxiliar.pontos;
		//player[j].nome = auxiliar.nome;
		sprintf(player[j].nome, "%s", auxiliar.nome);
	}
}

for(int i = 0; i < 3; i++){
	printf("%s : %i\n",player[i].nome ,player[i].pontos);
}

fclose(ponteiro_do_arquivo);

return 0;

}