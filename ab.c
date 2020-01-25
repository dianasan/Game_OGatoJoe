#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[4];
	int pontos;
}jogador;

jogador auxiliar;


int main (void){

void add();

jogador player[3];



//criando a variável ponteiro para o arquivo 
FILE *arquivo;

arquivo = fopen("ranking.txt", "r");

//verificando se criou o arquivo 
if(arquivo == NULL){
	printf("erro ao criar arquivo\n");
}else{}

//ler o arquivo enquanto ele não chega no final e armazenar os 3 jogadores
while(!feof(arquivo)){
	
	for(int i = 0;i < 3;i++){
		fscanf(arquivo,"%s %d\n", player[i].nome, &player[i].pontos);
		printf("player %d = %s : %i\n",i, player[i].nome ,player[i].pontos);
	}
	break;
}
if (PONTUACAO > player[2].pontos){
	add();
	sprintf(player[2].nome, "%s", auxiliar.nome);
		player[2].pontos = auxiliar.pontos;
}

/*//ler o arquivo e aramzenar o último colocado
while(!feof(arquivo)){
fscanf(arquivo,"%s %d\n", auxiliar.nome, &auxiliar.pontos);
}
printf("auxiliar = %s : %i\n", auxiliar.nome ,auxiliar.pontos);


//se os pontos do auxiliar for maior que do player 3 eles trocam de lugar 
if(player[2].pontos < auxiliar.pontos){
		//player[3].nome = auxiliar.nome;
		
}*/

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

fclose(arquivo);


arquivo = fopen("ranking.txt", "w");

for(int i = 0; i < 3;i++){
	fprintf(arquivo, "%s %d\n",player[i].nome, player[i].pontos);
}

fclose(arquivo);

return 0;

}

void add(){

printf("Digite o nome do jogador\n");
fgets(auxiliar.nome, 4, stdin);
auxiliar.pontos = PONTUACAO;
}
