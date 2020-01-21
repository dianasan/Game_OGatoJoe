#include "fases.c"
#include "fase1.c"
#include "menu.c"
#include "gameOver.c"

int main(){

	int corre = 0;//Variável que controla o game loop

	if(iniciarSDL()){
		window = criarJanela();

		if(window != NULL){
		
			if(iniciarIMG()){

				if(iniciarTTF()){//Inicando ttf para usar texto

					if(iniciarMusica()){

						//criar tela de renderizção, onde os objetos vão ser desenhados
						renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);//Antes estava 0, porém não é o melhor, o melhor é o renderer software para esse caso

						while(corre != 1){
							
							if(corre == 0){//Volta para o menu
								corre = menu();
								
							}else if(corre == 2){//Vai para a 1ª fase
								
								corre = fase1();

							}else if(corre == 3){
								//tela de como jogar
								//corre = comoJogar();
							}else if(corre == 4){//Tela de ranking, quem coletou mais moedas
							//	corre = ranking();
							}
							else if(corre == 5){//Tela de créditos
								//corre = creditos();
							}else if(corre == 6){
								corre = gameOver();
							}
							
							while(SDL_PollEvent(&event) != 0){ //Eventos de Teclado e Mouse
								
								encerrarJogo(event, &corre);//Termina a execução do programa
							}

						}
					}
				}
			}
		}
	}

	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyTexture(backgroundTextura);
	backgroundTextura = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	som = NULL;
	SDL_DestroyTexture(notSom);
	notSom = NULL;
	Mix_FreeMusic(musica);
	musica = NULL;
	Mix_FreeChunk(botao);
	botao = NULL;

	destruirWRBTS();

	IMG_Quit();
	SDL_Quit();
	Mix_Quit();
	TTF_Quit();

	return 0;
}