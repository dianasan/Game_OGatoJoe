#include "fases.c"
//#include "teste.c"
//#include "teste2.c"
#include "teste3.c"


int main(){

	/*
	if(FIM_FASE1 == 0)
		fase1();
	if(FIM_FASE2 == 0)	
		fase2();
	else
		printf("GAME OVER\n");

	*/
	//Criando janela

	int corre = 0;

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){

		printf("Error ao iniciar SDL %s\n",SDL_GetError());

	}else{
		window = SDL_CreateWindow("Menu",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,LARGURA_JANELA,ALTURA_JANELA,SDL_WINDOW_SHOWN);

		if(window == NULL){

			printf("Error na janela %s\n",SDL_GetError());

		}else{
			if(IMG_Init(IMG_INIT_PNG) < 0){

				printf("Erro ao iniciar IMG_INIT %s\n",IMG_GetError());

			}else{
				


				
				//corre = menu(window);
				renderer = SDL_CreateRenderer(window,-1,0);
				
				SDL_Event event;
				
				while(corre != 1){
					
					
					printf("Fechar = %d\n",corre);
					if(corre == 0){
						corre = menu();
						
					}
					else if(corre == 2){
						
						if(renderer == NULL)
							printf("to pelado\n");
						
						
						corre = fase3();

						printf("Vá para a primeira fase\n");
					}
					printf("Valor da corrida %d\n",corre);
					
					printf("Entro aqui?????????????\n");
					while(SDL_PollEvent(&event) != 0){ //Eventos de Teclado e Mouse
						
						encerrarJogo(event, &corre);
					}

				}
		
				
					//encerrarJogo(event, &close);
					
					

					//background

					
					
			
				//while(SDL_PollEvent(&event) != 0){
					
				//}
				
				
				
				
					
			}
			
			
			
		}

		
	}
	

	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	
	SDL_DestroyTexture(backgroundTextura);
	backgroundTextura = NULL;
	SDL_DestroyWindow(window);
	window = NULL;

	IMG_Quit();
	SDL_Quit();
	Mix_Quit();
	TTF_Quit();	


	return 0;
}