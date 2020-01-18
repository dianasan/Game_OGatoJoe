#include <stdio.h>

void timer();

int main(){

	timer();

	return 0;
}

void timer(){

	int fechar = 1;
	int contador = 120;
	int c2 = 1;
	int min;
	int seg;

	while(fechar){

		if(contador < 60){
			min = 0;
			seg = contador;
			
		}
		else{
			min = contador / 60;
			seg =  contador % 60;
		}

		printf("%d : %d\n",min,seg);

		if((c2 % 60) == 0)
			contador--;
		c2++;

		if(contador < 0){
			printf("\n********** GAME OVER ************** \n");
			fechar = 0;
		}
	}
}



